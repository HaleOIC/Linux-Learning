## notes

### Demo1

- `cmake_minimum_required( VERSION 2.8 )`：指定运行此配置文件所需的 CMake 的最低版本；
- `project(Demo1)`：参数值是 `Demo1`，该命令表示项目的名称是 `Demo1` 。
- `add_executable( Demo main.cc )`： 将名为 main.cc 的源文件编译成一个名称为 Demo 的可执行文件。
- `# ....` 符号 `#` 后面的内容被认为是注释



### Demo2

- `aux_source_directory(<dir> <variable>)` 命令，该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名

- `${variable}` 指示`variable` 中的源文件



### Demo3

#### subdirectory

- `add_library` 将 src 目录中的源文件编译为静态链接库。

#### rootdirectory

- `add_subdirectory(math)` 添加 math 子目录
- `target_link_libraries(Demo MathFunctions)` 添加链接库



### Demo4

- `configure_file` 命令用于加入一个配置头文件 config.h ，这个文件由 CMake 从 config.h.in 生成，通过这样的机制，将可以通过预定义一些参数和变量来控制代码的生成。