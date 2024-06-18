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
    std::vector<double> x0 = {-4.f, 0.f, -6.f, 0};
    const double h = 0.000100;

    const double k1 = 10;
    const double c1 = 0.05;
    const double m1 = 5;
    const double s1 = -3;

    const double k2 = 3;
    const double c2 = 0.05;
    const double m2 = 5;
    const double s2 = -3;

    const int output_every = 100;
    NewtonRK4 rk(x0, h, k1, c1, m1, s1, k2, c2, m2, s2);
    Output output;
    std::string str = rk.get_string_representation();
    output.send(str);
    output.message_type_set(MESSAGE_TYPE::SUBSEQUENT);

    for (size_t i = 0; i < 25 / rk.h; i++)
    {
        rk.step();
        if (0 == i % output_every)
        {
            std::string str = rk.get_string_representation();
            output.send(str);
        }
    }

    output.message_type_set(MESSAGE_TYPE::FINAL);
    str = rk.get_string_representation();
    output.send(str);

    return 0;
}
