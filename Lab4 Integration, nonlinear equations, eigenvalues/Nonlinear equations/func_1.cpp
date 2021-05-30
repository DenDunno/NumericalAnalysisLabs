#include "func_1.h"
#include <cmath>


double Func1(double x, double y)
{
    return sin(x - 0.6) - y - 1.6;
}


double Derivative_Func1_X(double x, double y)
{
    return cos(x - 0.6);
}


double Derivative_Func1_Y(double x, double y)
{
    return -1;
}
