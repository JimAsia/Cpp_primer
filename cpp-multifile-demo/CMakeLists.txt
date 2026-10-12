# ============================================================
#  C++ 多文件示例工程
#  配置 -> 构建 -> 调试：
#      cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
#      cmake --build build
#      ./build/demo.exe
#  或者在 VS Code 里按 F5（.vscode/ 已配好）
# ============================================================
cmake_minimum_required(VERSION 3.16)

project(cpp_multifile_demo LANGUAGES CXX)

# ---------- 语言标准 ----------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 生成 compile_commands.json，IntelliSense / clangd 可直接复用编译参数
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# MinGW Makefiles、Ninja 这类单配置生成器默认没有构建类型，这里兜底成 Debug
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# ---------- 可执行目标 ----------
# 源文件必须显式列出。
# 不要用 file(GLOB *.cpp)：新增文件不会触发 CMake 重新配置，容易"改了没生效"。
add_executable(demo
    src/main.cpp
    src/math_utils.cpp
    src/greeter.cpp
)

# 头文件搜索目录：这样源码里可以直接写 #include "math_utils.h"
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ---------- 编译选项 ----------
if(MSVC)
    target_compile_options(demo PRIVATE /W4 /utf-8)
else()
    target_compile_options(demo PRIVATE -Wall -Wextra -Wpedantic)
endif()
