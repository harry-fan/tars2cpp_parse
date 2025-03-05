# 设置最低 CMake 版本
cmake_minimum_required(VERSION 3.5)

# 定义项目名称和语言
project(tars2cpp LANGUAGES CXX)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 收集 tarsparse 目录下的源文件
file(GLOB TARSPARSE_SOURCES "tarsparse/*.cpp")

# 定义所有源文件
set(SOURCES
    ${TARSPARSE_SOURCES}
    main.cpp
    tars2cpp.cpp
)

# 定义头文件目录
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/tarsparse
    ${CMAKE_CURRENT_SOURCE_DIR}/util
)

# 添加可执行文件目标
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接静态库 tars_cpp_utils.a
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tars_cpp_utils.a
)

# 可选：设置输出路径
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 可选：添加编译选项（如调试信息）
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g -O0)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -O2)
endif()