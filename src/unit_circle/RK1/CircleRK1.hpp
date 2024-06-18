#pragma once

#include "../../RK1.hpp"

class CircleRK1 : public RK1
{
    using RK1::RK1;
public:
    int function(std::vector<double> &x_dot) override;
};
