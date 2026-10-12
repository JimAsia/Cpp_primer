# build.ps1 -- compile one C++ source with g++ (single-file or whole-folder multi-file)
# Called by .vscode/tasks.json.  Target: Windows PowerShell 5.1 (the default on Win10).
#
#   -Target    : the .cpp you are editing (${file})
#   -OutDir    : where the .exe goes (${workspaceFolder}\.build)
#   -Mode      : debug   -> -g -O0 -Wall -Wextra -fexec-charset=UTF-8
#                release -> -O2
#   -MoreArgs  : extra g++ flags, e.g. -std=c++11
#
# WHY the odd-looking code below (all learned by actually running it):
#  1. Do NOT name a parameter -File: this script is started as
#     `powershell.exe -File build.ps1 ...`, and -File would clash with
#     powershell.exe's own -File parameter set.
#  2. Split-Path in Windows PowerShell 5.1 has NO -LiteralPath parameter
#     (that arrived in PowerShell 7). Using it aborts with
#     "Parameter set cannot be resolved". Use -Parent only.
#  3. Get-ChildItem -File is unreliable on the 5.1 FileSystem provider here,
#     so the .cpp files are filtered by extension by hand.
#  4. Keep this file saved as UTF-8 **with BOM** and CRLF line endings;
#     Windows PowerShell 5.1 misparses BOM-less / LF-only scripts.
#
# Naming rule:
#   one .cpp in the folder  -> <that file>.exe
#   two or more .cpp files  -> they are all compiled together, and the output
#                              is named after the file you ran the task on
#                              (so run the task on the file holding main()).
#
# Script output text is kept ASCII on purpose: it survives codepage changes.

param(
    [Parameter(Mandatory = $true)][string]$Target,
    [string]$OutDir = "",
    [string]$Mode = "debug",
    [string]$MoreArgs = ""
)

$ErrorActionPreference = 'Stop'

if ([string]::IsNullOrWhiteSpace($OutDir)) { $OutDir = Join-Path $PWD '.build' }

# ---- toolchain (this machine: g++ 16.2.0 from MSYS2 UCRT64) -------------
$GXX    = 'C:\msys64\ucrt64\bin\g++.exe'
$DLLDIR = 'C:\msys64\ucrt64\bin'   # libstdc++-6.dll / libgcc_s_seh-1.dll live here

if (-not (Test-Path $Target)) {
    Write-Host "[build] ERROR: source not found: $Target" -ForegroundColor Red
    exit 1
}

$dir  = Split-Path -Parent $Target
$base = [System.IO.Path]::GetFileNameWithoutExtension($Target)
if ([string]::IsNullOrWhiteSpace($base)) { $base = 'a' }

# ---- collect the translation units -------------------------------------
$all = @(Get-ChildItem -Path $dir | Where-Object { -not $_.PSIsContainer -and $_.Extension -eq '.cpp' } | Sort-Object Name)

if ($all.Count -le 1) {
    $sources = @((Get-Item -Path $Target))
    $kind = 'single-file'
} else {
    $sources = $all
    $kind = "multi-file ($($all.Count) .cpp)"
}

$out = Join-Path $OutDir ($base + '.exe')
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

# ---- flags --------------------------------------------------------------
$flags = @()
if ($Mode -eq 'release') { $flags += @('-O2') } else { $flags += @('-g', '-gdwarf-4', '-O0') }
# -fexec-charset=UTF-8: 让 exe 里的字符串字面量以 UTF-8 存储。
# 源文件是 UTF-8、exe 输出 UTF-8、VS Code 集成终端按 UTF-8 解读, 全链路一致。
# (以前这里是 GBK, 那是基于"Windows 控制台默认 GBK 代码页"的假设;
#  但 VS Code 终端经 ConPTY 走 UTF-8 通道, 于是 GBK 字节被当 UTF-8 解读 -> 中文乱码。
#  实测确认后改为 UTF-8。)
# 如果你以后要在传统 cmd 窗口里跑 exe, 先执行 chcp 65001 切换成 UTF-8 即可。
$flags += @('-Wall', '-Wextra', '-fexec-charset=UTF-8', '-std=c++17')
# -MoreArgs 放在最后面: g++ 以最后一个 -std 为准, 这样额外指定标准时
# 既能真正覆盖默认值, 也不会出现重复 -std 的警告。
if (-not [string]::IsNullOrWhiteSpace($MoreArgs)) {
    $flags += @($MoreArgs.Split(' ') | Where-Object { $_ -ne '' })
}

foreach ($d in @($DLLDIR, (Split-Path -Parent $GXX))) {
    if ($d -and ($env:Path -notlike "*$d*")) { $env:Path = $d + ';' + $env:Path }
}

# ---- run g++ -----------------------------------------------------------
Write-Host "[build] mode   : $Mode"  -ForegroundColor Cyan
Write-Host "[build] target : $kind"  -ForegroundColor Cyan
Write-Host "[build] output : $out"   -ForegroundColor Cyan
Write-Host ("[build] cmd    : g++ " + ($flags -join ' ') + " <sources>") -ForegroundColor DarkGray

$srcPaths = @($sources | ForEach-Object { $_.FullName })
& $GXX @flags @srcPaths '-o' $out
$code = $LASTEXITCODE

if ($code -ne 0) {
    Write-Host "[build] FAILED (g++ exit $code)" -ForegroundColor Red
    exit $code
}

Write-Host "[build] OK -> $out" -ForegroundColor Green
exit 0
