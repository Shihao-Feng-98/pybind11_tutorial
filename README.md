# pybind11_tutorial

## Installation
See [pybind11 document](https://pybind11.readthedocs.io/en/stable/installing.html). Download the source code from github, and include the ```pybind11``` file in cpp project.
```
git clone https://github.com/pybind/pybind11
```

Example code see ```example.cpp``` and ```check.py```. Use pybind11 in ```CMakeLists.txt```.
```
add_subdirectory(pybind11) 
pybind11_add_module(example example.cpp)
```
