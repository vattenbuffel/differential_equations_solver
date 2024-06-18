#include "RK.hpp"
#include <string>

int RK::step()
{
    std::cerr << __func__ << " not implemented\n";
    return 0;
}

int RK::function(std::vector<double> &x_dot)
{
    std::cerr << __func__ << " not implemented\n";
    return -1;
}
std::string RK::get_string_representation()
{
    std::string str = "";
    str += "x: {\n";
    for (auto val : x)
    {
        str += "\t";
        str += std::to_string(val);
        str += "\n";
    }
    str += "}\n";
    str += "t = ";
    str += std::to_string(t);
    str += "\n";
    return str;
}

RK::RK(std::vector<double> x0, double h) : x0(x0), h(h)
{
    x = x0;
    dimension = x0.size();
}

RK::RK(std::vector<double> x0) : RK::RK(x0, 0.1)
{
}

RK::~RK() {}