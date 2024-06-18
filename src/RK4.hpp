#pragma once

#include "RK.hpp"

class RK4 : public RK
{
public:
    using RK::RK;

    int step() override;

private:
    void apply_x_dot(std::vector<double> x_dot, double x_dot_factor);
};
