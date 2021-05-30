#include <iostream>
#include <vector>
#include "func_1.h"
#include "func_2.h"
using namespace std;

/* Problem: solve system of equations:
*  System:
*
*   sin(x - 0.6)  - y = 1.6
*   3x - cos(y) = 0.9
*/

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

void SolveSystem(double& x, double& y, const double epsilon);
void Inverse_Matrix(Matrix& A);


int main()
{
    const double EPSILON = 0.001;
    double x = 1.25;
    double y = 0;

    SolveSystem(x, y, EPSILON);

    cout << "x = " << x << endl << "y = " << y << endl;

    return 0;
}


void SolveSystem(double& x, double& y, const double epsilon)
{
    Matrix A =
    {
        {0 , 0 },
        {0 , 0 }
    };

    Vector B(A.size());    
    double norm;

    do
    {
        A[0][0] = Derivative_Func1_X(x, y);
        A[0][1] = Derivative_Func1_Y(x, y);

        A[1][0] = Derivative_Func2_X(x, y);
        A[1][1] = Derivative_Func2_Y(x, y);

        Inverse_Matrix(A);

        double dx = -A[0][0] * Func1(x, y) + -A[0][1] * Func2(x, y);
        double dy = -A[1][0] * Func1(x, y) + -A[1][1] * Func2(x, y);

        x = x + dx;
        y = y + dy;

        B[0] = Func1(x, y);
        B[1] = Func2(x, y);

        norm = sqrt(B[0] * B[0] + B[1] * B[1]);

    } while (norm >= epsilon);
}


void Inverse_Matrix(Matrix& A)
{
    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    double temp = A[0][0];

    A[0][0] = A[1][1] / det;
    A[1][1] = temp / det;

    temp = A[0][1];

    A[0][1] = -A[0][1] / det;
    A[1][0] = -A[1][0] / det;
}
