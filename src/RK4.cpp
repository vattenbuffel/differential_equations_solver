#include "RK4.hpp"

void RK4::apply_x_dot(std::vector<double> x_dot, double x_dot_factor)
{
    for (int i = 0; i < dimension; i++)
    {
        x[i] += x_dot[i] * x_dot_factor;
    }
}

std::string _vector_double_to_string(std::vector<double> &vec)
{
    std::string res = "{";
    for (auto val : vec)
    {
        res += std::to_string(val);
        res += ", ";
    }
    res += "}";
    return res;
}

int RK4::step()
{
    std::vector<double> k1(dimension);
    std::vector<double> k2(dimension);
    std::vector<double> k3(dimension);
    std::vector<double> k4(dimension);
    std::vector<double> k(dimension);

    std::vector<double> x_old = x;

    // Compute k1
    (void)function(k1);
    // std::cout << "k1: " << _vector_double_to_string(k1) << "\n";

    // Compute k2
    t += h / 2;
    RK4::apply_x_dot(k1, h / 2);
    // std::cout << "x: " << _vector_double_to_string(x) << "\n";
    (void)function(k2);
    // std::cout << "k2: " << _vector_double_to_string(k2) << "\n";
    x = x_old;

    // Compute k3
    RK4::apply_x_dot(k2, h / 2);
    // std::cout << "x: " << _vector_double_to_string(x) << "\n";
    (void)function(k3);
    // std::cout << "k3: " << _vector_double_to_string(k3) << "\n";
    x = x_old;

    // Compute k4
    t += h / 2;
    RK4::apply_x_dot(k3, h);
    // std::cout << "x: " << _vector_double_to_string(x) << "\n";
    (void)function(k4);
    // std::cout << "k4: " << _vector_double_to_string(k4) << "\n";
    x = x_old;

    // Compute h/6(k1 + 2k2 + 2k3 + k4)
    for (int i = 0; i < dimension; i++)
    {
        k[i] = h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
    }

    // std::cout << "k: " << _vector_double_to_string(k) << "\n";

    // Finally update x
    RK4::apply_x_dot(k, 1);
    // std::cout << "x: " << _vector_double_to_string(x) << "\n";

    return 0;
}