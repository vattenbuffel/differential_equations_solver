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
    std::vector<double> x0 = {0.f, -3.f};
    NewtonRK4 rk(x0, 0.05, 1.f);
    Output output;
    for (size_t i = 0; i < 9 / rk.h; i++)
    {
        rk.step();
        std::string str = rk.get_string_representation();
        output.send(str);
    }

    return 0;
}
