#include <iostream>
#include <vector>
#include "CircleRK1.hpp"
#include "output.hpp"

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
    std::vector<double> x0 = {1.f, 0.f, 0.f};
    CircleRK1 bajs(x0, 0.01);
    Output output;
    for (size_t i = 0; i < 2 * 3.141592f / bajs.h; i++)
    {
        bajs.step();
        std::string str = bajs.get_string_representation();
        output.send(str);
    }

    return 0;
}
