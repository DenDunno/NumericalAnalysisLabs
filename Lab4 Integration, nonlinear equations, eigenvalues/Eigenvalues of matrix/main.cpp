#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/* Problem: Find max eigenvalue of matrix using power iteration
*  Matrix:
* 
*   3.1  1.0  2.1
*   1.0  3.6  2.1
*   2.1  2.1  4.1
*/

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

double GetMaxEigenValue(const Matrix& matrix, const double EPSILON);


int main()
{
    const double EPSILON = 0.001;
    const Matrix MATRIX =
    {
        {3.1 , 1.0 , 2.1 },
        {1.0 , 3.6 , 2.1 },
        {2.1 , 2.1 , 4.1}
    };

    auto answer = GetMaxEigenValue(MATRIX , EPSILON);

    cout << answer << endl;
}


Vector operator*(const Matrix& matrix , const Vector& vec)
{
    Vector result (vec.size() , 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            result[i] += matrix[i][j] * vec[j];
        }
    }

    return result;
}


double DotProduct(const Vector& vec1, const Vector& vec2)
{
    double result = 0;

    for (int i = 0; i < vec1.size(); i++)
    {
        result += vec1[i] * vec2[i];
    }

    return result;
}


double GetMaxEigenValue(const Matrix& matrix , const double epsilon)
{
    Vector Xn(matrix.size(), 1);
    Vector Xn1(matrix.size());

    double answer = 0;
    double answerPrev = 0;

    do
    {
        Xn1 = matrix * Xn;

        answerPrev = answer;

        answer = DotProduct(Xn, Xn1) / DotProduct(Xn, Xn);

        Xn = Xn1;

    } while ((fabs(answer - answerPrev)) > epsilon);

    return answer;
}
