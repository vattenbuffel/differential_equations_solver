#pragma once

#include "../../RK4.hpp"

class NewtonRK4 : public RK4
{
    using RK4::RK4;
public:
    double a;

    NewtonRK4(std::vector<double> x0, double h, double a);

    int function(std::vector<double> &x_dot) override;
};
