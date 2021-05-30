#include "func_2.h"
#include <cmath>


double Func2(double x, double y)
{
    return 3 * x - cos(y) - 0.9;
}


double Derivative_Func2_X(double x, double y)
{
    return 3;
}


double Derivative_Func2_Y(double x, double y)
{
    return sin(y);
}
