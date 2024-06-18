#include "NewtonRK4.hpp"
#include <math.h>

NewtonRK4::NewtonRK4(std::vector<double> x0, double h, double k, double c, double m) : RK4(x0, h), k(k), c(c), m(m) {}

int NewtonRK4::function(std::vector<double> &x_dot)
{
    const auto p = x[0];
    const auto v = x[1];

    x_dot[0] = v;
    x_dot[1] = (-k * p - c * v - m * g) / m;

    return 0;
}