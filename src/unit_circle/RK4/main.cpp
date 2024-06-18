#include <iostream>
#include <vector>
#include "CircleRK4.hpp"
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
    std::vector<double> x0 = {1.f, 0.f};
    CircleRK4 circlerk4(x0, 0.5);
    Output output;
    for (size_t i = 0; i < 2 * 3.141592f / circlerk4.h; i++)
    {
        circlerk4.step();
        std::string str = circlerk4.get_string_representation();
        output.send(str);
    }

    return 0;
}
