# vscode_new_type

这是一个用于在 VSCode 中构建 C++ 可执行项目的基础模板项目。

## 项目简介

本项目旨在提供一个开箱即用的 VSCode C++ 开发环境配置，方便快速创建和开发新的 C++ 可执行程序。项目包含了 CMake 构建配置、clangd 语言服务器支持以及 VSCode 调试配置。

## 目录结构

```
vscode_new_type/
├── .vscode/              # VSCode 配置文件夹
│   ├── launch.json       # 调试启动配置
│   ├── settings.json     # 编辑器设置
│   └── tasks.json        # 构建任务配置
├── src/                  # 源代码目录
│   └── common/           # 公共源代码
│       ├── common.h
│       └── utils.h
├── build/                # 构建输出目录
├── .clang-format         # 代码格式化配置
├── .clangd               # clangd 语言服务器配置
├── CMakeLists.txt        # CMake 构建脚本
└── .gitignore            # Git 忽略文件配置
```

## 技术栈

- **语言**：C++
- **构建工具**：CMake
- **编辑器**：Visual Studio Code
- **语言服务器**：clangd
- **编译器**：GCC / Clang

## 快速开始

### 前置条件

确保已安装以下工具：

- VSCode
- CMake
- GCC 或 Clang 编译器
- VSCode 扩展：`clangd`、`CMake Tools`

### 构建项目

```bash
cd vscode_new_type
mkdir build
cd build
cmake ..
make
```

### 运行程序

```bash
./build/your_executable_name
```

### 调试

在 VSCode 中按 `F5` 即可启动调试。

## 使用说明

1. 克隆本仓库到本地
2. 根据需要修改 `src/` 目录下的源代码
3. 修改 `CMakeLists.txt` 中的项目名称和配置
4. 使用上述构建命令重新构建项目

## 自定义项目

修改 `CMakeLists.txt` 文件中的项目名称：

```cmake
project(YourProjectName)
```

## License

MIT License
