#include "NewtonRK4.hpp"
#include <math.h>

NewtonRK4::NewtonRK4(std::vector<double> x0, double h, double a) : RK4(x0, h), a(a) {}

int NewtonRK4::function(std::vector<double> &x_dot)
{
    const auto v = x[1];

    x_dot[0] = v;
    x_dot[1] = a;

    return 0;
}