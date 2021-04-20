#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<vector<double>> Matrix;

void ShowMatrix(const Matrix& matrix);
bool CheckTheoremCondition(const Matrix& matrix);
double EvaluateDeterminant(const Matrix& matrix , int size);
vector<double> SolveLinearSystems(const Matrix& matrix);


int main()
{
    Matrix matrix =
    {
        {6 , 3 , 1 , 0 , 15},
        {3 , 5 , 0 , 2 , 21},
        {1 , 0 , 3 , 1 , 14},
        {0 , 2 , 1 , 5 , 27},
    };

    double epsilon = 1e-3;

    ShowMatrix(matrix);

    if (CheckTheoremCondition(matrix) == true)
    {
        auto answer = SolveLinearSystems(matrix);

        for (int i = 1; i <= matrix.size(); ++i)
        {
            cout << "X" << i << " = " << answer[i - 1] << endl;
        }
    }
    
    return 0;
}


void ShowMatrix(const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j <= matrix.size(); ++j)
        {
            cout << matrix[i][j] << '\t';
        }

        cout << endl;
    }

    cout << endl;
}


bool CheckTheoremCondition(const Matrix& matrix)
{
    vector<double> mainMinors;

    for (int i = 1; i <= matrix.size(); ++i)
        mainMinors.push_back(EvaluateDeterminant(matrix, i));

    return all_of(mainMinors.begin(), mainMinors.end(), [](auto& x)
    {
        return x > 0;
    });
} 


double EvaluateDeterminant(const Matrix& matrix , int size)
{
    double det = 0;
    Matrix matr;    

    if (size == 1)
    {
        det = matrix[0][0];
    }

    else if (size == 2)
    {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    else
    {
        matr.resize(size - 1);

        for (int i = 0 , j; i < size; ++i)
        {
            for (j = 0; j < size - 1; ++j)
            {
                matr[j] = (j < i) ? matrix[j] : matrix[j + 1];
            }

            det += pow((double)-1, (i + j)) * EvaluateDeterminant(matr , size - 1) * matrix[i][size - 1];
        }
    }

    return det;
}


vector<double> SolveLinearSystems(const Matrix& matrix)
{    
    const int ITERATIONS = 14;
    vector<double> answer(matrix.size(), 0);

    for (int i = 0; i < ITERATIONS; ++i)
    {
        for (size_t j = 0; j < matrix.size(); ++j)
        {
            double sum = 0;

            for (size_t k = 0; k < matrix.size(); ++k)
            {
                sum += matrix[j][k] * answer[k];
            }

            sum -= matrix[j][j] * answer[j];
            sum = matrix[j][matrix.size()] - sum;

            answer[j] = sum / matrix[j][j];
        }
    }

    return answer;
}
