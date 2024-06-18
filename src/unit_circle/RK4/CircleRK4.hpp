#pragma once

#include "../../RK4.hpp"

class CircleRK4 : public RK4
{
    using RK4::RK4;
public:
    int function(std::vector<double> &x_dot) override;
};
