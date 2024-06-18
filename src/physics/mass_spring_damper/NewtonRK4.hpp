#pragma once

#include "../../RK4.hpp"

class NewtonRK4 : public RK4
{
    using RK4::RK4;

public:
    double k; // Spring constant
    double c; // Dampener constant
    double m; // mass
    const double g = 9.81;

    NewtonRK4(std::vector<double> x0, double h, double k, double c, double m);

    int function(std::vector<double> &x_dot) override;
};
