cmake_minimum_required(VERSION 3.4)
project(example)

# g++ 编译选项
set(CMAKE_XCC_FLAGS "$ENV{CXXFLAGS} -O3 -std=c++11 -wall")

# compaile for python3.8 (default for python3.6)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# pybind11 
add_subdirectory(pybind11) # 需要复制pybind11文件夹
pybind11_add_module(example example.cpp)
