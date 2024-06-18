#pragma once

#include "../../RK4.hpp"

class NewtonRK4 : public RK4
{
    using RK4::RK4;

public:
    double k1; // Spring constant
    double c1; // Dampener constant
    double m1; // mass
    double s1; // spring length at rest

    double k2; // Spring constant
    double c2; // Dampener constant
    double m2; // mass
    double s2; // spring length at rest

    const double g = 0;

    NewtonRK4(std::vector<double> x0, double h,
              double k1, double c1, double m1, double s1,
              double k2, double c2, double m2, double s2);

    std::string get_string_representation();

    int function(std::vector<double> &x_dot) override;
};
