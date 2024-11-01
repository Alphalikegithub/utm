在纬度-经度和 UTM-UPS 网格之间转换坐标
# 第一种
## Makefile
为了简化编译和执行流程，可以使用一个 **Makefile** 来自动化编译和执行命令。这样只需在项目目录中运行 `make` 或者指定特定目标（如 `make run`），就可以完成编译和执行。

### 使用说明
1. **编译和执行**：在终端中输入 `make run1`，即可编译并执行 `final1`，同时在 `output` 文件夹下生成转换结果,实现从经纬度BL转为UTM投影下的XY(m)的功能。；在终端中输入 `make run2`，即可编译并执行 `final2`，同时在 `output` 文件夹下生成转换结果,实现从UTM投影下的XY转为经纬度BL的功能。
2. **自动生成**：使用 `make` 或 `make all` 可同时编译和运行所有目标。
3. **清理**：使用 `make clean` 可以清理所有生成的可执行文件和输出结果。

这样，就不需要手动输入编译和执行命令，直接使用 `make` 管理项目文件。

# 第二种
## CMake
### 编译和运行步骤

1. 在项目根目录下创建一个 `build` 目录，并进入该目录：
   ```bash
   mkdir -p build && cd build
   ```

2. 执行 CMake 以生成 Makefile，并在 `build` 目录中进行编译：
   ```bash
   cmake ..
   make
   ```

3. 编译后，可以直接运行：
   ```bash
   make run_all  # 运行 final1 和 final2
   ```

### 解释

- `WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}` 确保运行可执行文件时，它的工作目录是项目的根目录，这样就可以找到 `file` 和 `output` 目录。
- 这样设置后，您的程序就能找到输入文件 `LB.txt` 和 `XY.txt`，从而避免出现 "无法打开输入文件" 的错误。

按照这些修改，您的项目应该能够顺利编译并运行而不再出现文件路径的问题。


### 单独运行 final1 和 final2

1. **编译项目**：确保您已经在 `build` 目录中执行了 `cmake ..` 和 `make` 命令，这样会生成可执行文件 `final1` 和 `final2`。

2. **单独运行 final1**：
   ```bash
   make run_final1
   ```

3. **单独运行 final2**：
   ```bash
   make run_final2
   ```

### 直接在终端运行可执行文件

您还可以直接在终端中运行生成的可执行文件，前提是您在 `build` 目录中。您可以使用以下命令：

1. **运行 final1**：
   ```bash
   ./final1
   ```

2. **运行 final2**：
   ```bash
   ./final2
   ```

### 注意事项

- 确保在运行时，输入文件（如 `file/LB.txt` 和 `file/XY.txt`）的位置正确，并且相对于当前工作目录是可以访问的。如果使用的是 `make run_final1` 或 `make run_final2`，请确保您的 CMakeLists.txt 中设置的工作目录是正确的。
- 如果您更改了任何源代码或文件，记得重新编译：
   ```bash
   make
   ```

通过这些步骤，您可以轻松地单独运行 `final1` 和 `final2`。