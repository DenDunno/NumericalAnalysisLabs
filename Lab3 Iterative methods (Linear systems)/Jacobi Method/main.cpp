#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

/*
	Solve by Jacobi method , epsilon = 1e-3

	4  0  1  0     X1  =  7
	0  3  0  2  x  X2  =  14
	1  0  5  1     X3  =  20
	0  2  1  4     X4  =  23
*/

typedef vector<vector<double>> Matrix;

void ShowMatrix(Matrix& matrix);
double GetQ(Matrix& matrix);
vector<double> SolveLinearSystems(Matrix& matrix , int numOfIterations);


int main()
{
	Matrix matrix =
	{
		{4 , 0 , 1 , 0 , 7},
		{0 , 3 , 0 , 2 , 14},
		{1 , 0 , 5 , 1 , 20},
		{0 , 2 , 1 , 4 , 23},
	};

	double epsilon = 1e-3;

	ShowMatrix(matrix);
	double q = GetQ(matrix);

	if (q > 0) // the condition of the theorem is satisfied
	{
		int numOfIterations = log(epsilon * (1 - q)) / log(q) + 1;
		auto answer = SolveLinearSystems(matrix , numOfIterations);

		for (int i = 1; i <= matrix.size(); ++i)
		{
			cout << "X" << i << " = " << answer[i - 1] << endl;
		}
	}
	
	return 0;
}


void ShowMatrix(Matrix& matrix)
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


double GetQ(Matrix& matrix)
{
	vector<double> vec_q;
	vector<double> sums;

	for (size_t i = 0; i < matrix.size(); ++i)
	{
		double sum = 0;

		for (size_t j = 0; j < matrix.size(); ++j)
		{
			sum += abs(matrix[i][j]);
		}

		sum -= abs(matrix[i][i]);
		sums.push_back(sum);
		vec_q.push_back(matrix[i][i] - sum);
	}

	int it = min_element(vec_q.begin(), vec_q.end()) - vec_q.begin();

	return sums[it] / abs(matrix[it][it]);
}


vector<double> SolveLinearSystems(Matrix& matrix, int numOfIterations)
{
	vector<double> startX(matrix.size(), 0);
	vector<double> answer(matrix.size() , 0);

	for (int i = 0; i < numOfIterations; ++i)
	{
		for (size_t j = 0; j < matrix.size(); ++j)
		{
			double sum = 0;

			for (size_t k = 0; k < matrix.size(); ++k)
			{
				sum += matrix[j][k] * startX[k];
			}

			sum -= matrix[j][j] * startX[j];
			sum = matrix[j][matrix.size()] - sum;

			answer[j] = sum / matrix[j][j];
		}

		startX = answer;
	}

	return answer;
}

