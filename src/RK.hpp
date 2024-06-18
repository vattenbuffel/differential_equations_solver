#pragma once

#include <iostream>
#include <vector>

class RK
{
public:
    std::vector<double> x0;
    std::vector<double> x;
    double h;
    double t;
    int dimension;

    RK(std::vector<double> x0, double h);
    RK(std::vector<double> x0);
    virtual int step();
    virtual int function(std::vector<double>& x_dot);

    virtual std::string get_string_representation();
    ~RK();
};
