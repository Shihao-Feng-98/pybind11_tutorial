#include <vector>
#include <string>
#include <numeric>
using namespace std;

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

int add(int i, int j){
    return i + j;
}

class Calculation
{
public:
    Calculation(string str)
    {
        this->str = str;
    }

    int add_int (int a, int b)
    {
        return a + b;
    }

    double add_double(double a, double b)
    {
        return a + b;
    }

    int sum(vector<int> a)
    {
        return accumulate(a.begin(), a.end(), 0);
    }
    
    string str;
};


PYBIND11_MODULE(example, m){
    m.doc() = "pybind11 example plugin";

    m.def("add", &add, "A function that adds two numbers", py::arg("i"), py::arg("j"));

    py::class_<Calculation>(m, "Calculation")
        // 构造函数
        .def(py::init<string>(), py::arg("str"))
        // 成员变量
        .def_readwrite("str", &Calculation::str)
        // 成员函数
        .def("add_int", &Calculation::add_int, py::arg("a"), py::arg("b"))
        .def("add_double", &Calculation::add_double, py::arg("a"), py::arg("b"))
        .def("sum", &Calculation::sum, py::arg("a"));
}
