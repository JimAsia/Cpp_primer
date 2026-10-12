# C++ 多文件示例工程（VSCode + MinGW + CMake）

一个能直接跑起来的最小多文件工程，演示三件事：

1. 头文件放**声明**、`.cpp` 放**实现**、`main.cpp` 用它们；
2. VSCode 里怎么配才能**一次编译所有源文件**（`Ctrl+Shift+B` / `F5`）；
3. 用 CMake 管理更大的工程（新增文件改一行 `CMakeLists.txt`）。

---

## 一、目录结构

```
cpp-multifile-demo/
├── CMakeLists.txt              # CMake 工程定义（显式列出源文件）
├── README.md
├── .gitignore
├── build/                      # 所有产物都在这（build/.gitkeep 只是占位）
├── include/                    # 头文件：只放声明
│   ├── greeter.h
│   └── math_utils.h
├── src/                        # 源文件：放实现，只能有一个 main
│   ├── main.cpp                # 唯一入口
│   ├── greeter.cpp
│   └── math_utils.cpp
└── .vscode/
    ├── tasks.json              # 编译任务（5 个：g++ 显式 / g++ 通配符 / cmake configure / cmake build / g++ 单文件）
    ├── launch.json             # F5 调试配置（3 个：g++ 构建版、CMake 构建版、当前单文件）
    ├── c_cpp_properties.json   # IntelliSense 的头文件路径、标准、编译器
    └── settings.json           # CMake Tools / C_Cpp 扩展的默认值
```

依赖关系：`main.cpp` → 只 `#include "greeter.h"`、`"math_utils.h"`；
链接期才需要 `greeter.cpp`、`math_utils.cpp` 生成的 `.o`。
**头文件不需要、也不应该写进编译列表。**

---

## 二、跑起来的三种方式

### 方式 A：按 F5（最省事，推荐先用这个）

1. 用 VSCode 打开 **`cpp-multifile-demo` 这个文件夹**（不是打开单个 .cpp 文件，
   否则 `.vscode/` 里的配置不会生效）。
2. 装扩展：**C/C++**（`ms-vscode.cpptools`）。
3. 直接按 `F5` →
   `preLaunchTask` 先执行 `g++: 编译全部源文件` → 再启动 `build/demo.exe` 调试。

预期输出：

```
Hello, VSCode!
add(2, 3)     = 5
factorial(6)  = 720
average(1..5) = 3
```

### 方式 B：`Ctrl+Shift+B` 只编译

默认构建任务 = `g++: 编译全部源文件`，产物固定在 `build/demo.exe`。
想跑一下：终端里执行 `.\build\demo.exe`，或 `.\build\demo.exe 你的名字`。

### 方式 C：CMake 命令行（工程变大后用这个）

```powershell
cd cpp-multifile-demo
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug      # 配置
cmake --build build                               # 构建
.\build\demo.exe                                  # 运行
```

Windows 上如果报"找不到合适的生成器 / Generator not found"（说明没装 Visual Studio），
换成 MinGW 生成器即可：

```powershell
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
```

装了 **CMake Tools** 扩展的话，底部状态栏选 Kit → 点 **Build / Debug** 按钮，
它会自动做上面这些事（`.vscode/settings.json` 已把生成器设为 MinGW Makefiles）。

### 方式 D：只编译「当前打开的那一个文件」（单文件练习）

前面三种方式都是**整个工程**，它们不认"当前文件"。如果你想在这个项目里随手写个单文件练习
（比如 `notes/test.cpp`，整份代码就一个文件、自带 `main`）：

- 编译任务：`g++: 编译当前文件（单文件）`（终端 → 运行任务，或改 `tasks.json` 里它的 `isDefault`）
- 调试：F5 下拉里选 `调试当前文件（单文件）`
- 产物：与源文件同目录同名（`test.cpp` → `test.exe`），不写进 `build/`

⚠️ 不要对 `src/main.cpp` 用单文件任务：它自己只 `#include` 头文件，单独编译会在链接期报
`undefined reference to demo::add(...)` —— 那两个函数在 `math_utils.cpp`、`greeter.cpp` 里。

想把"单文件"变成按 F5 的默认行为，把 `launch.json` 里 `调试当前文件（单文件）`
这一整段移到 `configurations` 数组的第一位即可（第一项就是默认配置）。

---

## 三、新增一个源文件要改哪里

假设新增 `src/shapes.cpp` + `include/shapes.h`：

| 用到的方式 | 需要做的事 |
|---|---|
| `tasks.json` 任务 1（显式列表） | 在 args 里加一行 `"${workspaceFolder}/src/shapes.cpp"` |
| `tasks.json` 任务 2（通配符） | **不用改**，`src/*.cpp` 自动带上（依赖 g++ 自己展开通配符） |
| CMake | 在 `add_executable(demo ...)` 里加一行 `src/shapes.cpp` |

> 不要用 `file(GLOB *.cpp)` 代替显式列表：新增文件不会触发重新配置，
> 会出现"我明明加了文件却没编译进去"的玄学问题。

---

## 四、常见报错对照表

| 报错 | 原因 | 解决 |
|---|---|---|
| `multiple definition of 'main'` | 被编译的文件里有两个 `main()`（比如把上一题的 .cpp 也加进来了） | 一个工程只能有一个 `main`；检查编译列表 / `src` 目录 |
| `undefined reference to 'demo::add(int, int)'` | 实现 `add` 的 `.cpp` **没被编译**，或声明与定义签名/命名空间不一致 | 把该 `.cpp` 加进编译列表 / `add_executable` |
| 用「单文件」任务编译 `src/main.cpp` → 同样报 `undefined reference` | 单文件任务只编译一个 `.cpp`，另外两个模块没参与链接 | 多文件工程请按 `Ctrl+Shift+B` 用默认任务 |
| `fatal error: math_utils.h: No such file or directory` | 没告诉编译器头文件在哪 | g++ 加 `-I${workspaceFolder}/include`；CMake 用 `target_include_directories` |
| `No such file or directory: ...\src\*.cpp` | 通配符没被展开（或该目录下没有匹配文件） | 改用任务 1 的显式列表 |
| 断点变成空心灰圈，提示"未加载符号" | 没加 `-g`，或 `program` 路径和实际产物不一致 | 任务里保留 `-g`；核对 `launch.json` 的 `program` |
| CMake 报 Generator not found | 没装 Visual Studio | 加 `-G "MinGW Makefiles"`（settings.json 里已设） |
| 改了代码按 F5 还是旧结果 | 编译任务的输出路径和 `program` 不一致 | `-o` 与 `program` 都应是 `build/demo.exe` |

---

## 五、换成别的机器要改的 3 处路径

本工程按 `C:/Users/admin/mingw64/bin/` 写死了编译器路径，换环境时改：

- `.vscode/tasks.json` → 两个 g++ 任务的 `command`
- `.vscode/launch.json` → 两个配置的 `miDebuggerPath`
- `.vscode/c_cpp_properties.json` → `compilerPath`（只影响 IntelliSense）

MSYS2 用户通常是 `C:/msys64/ucrt64/bin/g++.exe`。

---

## 六、可选：再加一个 Makefile

如果不想装 CMake，也不想每次手动维护文件列表，可以在项目根目录加一个 Makefile，
用 `wildcard` + 头文件依赖自动处理增量编译，然后在 `tasks.json` 里加一条
`"command": "mingw32-make"` 的任务即可（本工程默认没放 Makefile，避免和 CMake 冲突）。
