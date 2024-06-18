#include "RK1.hpp"

int RK1::step()
{
    std::vector<double> x_dot(dimension);
    (void)function(x_dot);

    for (int i = 0; i < dimension; i++)
    {
        x[i] += x_dot[i] * h;
    }

    t += h;

    return 0;
}