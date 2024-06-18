#include "CircleRK1.hpp"
#include <math.h>

int CircleRK1::function(std::vector<double> &x_dot)
{
    x_dot[0] = -sin(t);
    x_dot[1] = cos(t);

    return 0;
}