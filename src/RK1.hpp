#pragma once

#include "RK.hpp"

class RK1 : public RK
{
public:
    using RK::RK;

    int step() override;
};
