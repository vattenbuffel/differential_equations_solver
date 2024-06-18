#include "NewtonRK4.hpp"
#include <math.h>

NewtonRK4::NewtonRK4(std::vector<double> x0, double h,
                     double k1, double c1, double m1, double s1,
                     double k2, double c2, double m2, double s2)
    : RK4(x0, h), k1(k1), m1(m1), c1(c1), s1(s1), k2(k2), c2(c2), m2(m2), s2(s2) {}

std::string NewtonRK4::get_string_representation()
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
    str += ", ";
    str += "s1 = ";
    str += std::to_string(abs(s1));
    str += ", ";
    str += "s2 = ";
    str += std::to_string(abs(s2));
    str += "\n";
    return str;
}


int NewtonRK4::function(std::vector<double> &x_dot)
{
    const auto p1 = x[0];
    const auto v1 = x[1];

    const auto p2 = x[2];
    const auto v2 = x[3];

    const double F2 = -k2 * (p2 - p1 - s2) - c2 * v2;
    const double F1 = -F2 - k1 * (p1 - s1) - c1 * v1;

    x_dot[0] = v1;
    x_dot[1] = F1 / m1;

    x_dot[2] = v2;
    x_dot[3] = F2 / m2;

    return 0;
}