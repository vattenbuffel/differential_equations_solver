#include <iostream>
#include <vector>
#include "NewtonRK4.hpp"
#include "../../output.hpp"

/**
 * Simulate differential eq via newton's first method, ie RK1.
 * Input:
 *  Sampling time, h
 *  state vector dimension, x
 *  differential equation: x_dot = f(x)
 *
 * Functions:
 *  RK1
 *  RK2
 *  RK4
 *
 * Classes:
 *  something containing x and f
 */

int main()
{
    std::vector<double> x0 = {-4.f, 0.f};
    const double h = 0.0000100;
    const double k = 4;
    const double c = 0.1;
    const double m = 0.5;
    const int output_every = 10000;
    NewtonRK4 rk(x0, h, k, c, m);
    Output output;
    for (size_t i = 0; i < 60 / rk.h; i++)
    {
        rk.step();
        if (0 == i % output_every)
        {
            std::string str = rk.get_string_representation();
            output.send(str);
        }
    }

    return 0;
}
