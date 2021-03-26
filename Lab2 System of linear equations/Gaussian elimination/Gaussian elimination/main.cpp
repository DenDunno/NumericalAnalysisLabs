#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
	Solve

	7	2	3	0	    Õ1	     20
	0	3	2	6	õ   Õ2   =   36
	2	5	1	0		Õ3		 15
	0	1	4	2	    Õ4		 22
*/

typedef vector<vector<float>> Matrix;

void ShowMatrix(Matrix& matrix);

void SetTriangleForm(Matrix& matrix);
vector<float> SolveSystemOfLinearEquations(Matrix& matrix);


int main()
{
	Matrix matrix
	{
		{7 , 2 , 3 , 0 , 20} ,
		{0 , 3 , 2 , 6 , 36} ,
		{2 , 5 , 1 , 0 , 15} ,
		{0 , 1 , 4 , 2 , 22} ,
	};
	
	ShowMatrix(matrix);
	SetTriangleForm(matrix);

	cout << endl << endl;
	ShowMatrix(matrix);

	auto answer = SolveSystemOfLinearEquations(matrix);

	cout << endl << endl;
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << "    ";
}


void ShowMatrix(Matrix& matrix)
{
	cout << fixed;
	cout.precision(2);

	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << '\t';
		}

		cout << endl;
	}
}


void SetTriangleForm(Matrix& matrix)
{
	const size_t SIZE = matrix.size();

	for (size_t k = 0; k < SIZE; k++)
	{
		for (size_t i = k + 1; i < SIZE; i++)
		{
			float divider = matrix[i][k] / matrix[k][k];

			for (size_t j = 0; j < SIZE + 1; j++)
			{
				matrix[i][j] -= matrix[k][j] * divider;
			}
		}
	}
}


vector<float> SolveSystemOfLinearEquations(Matrix& matrix)
{
	const size_t SIZE = matrix.size();

	vector<float> X;
	X.push_back(matrix[SIZE - 1][SIZE] / matrix[SIZE - 1][SIZE - 1]);

	for (int i = SIZE - 2; i >= 0; --i)
	{
		float sum = 0;

		for (size_t j = 0; j < X.size(); ++j)
		{
			sum += matrix[i][SIZE - 1 - j] * X[j];
		}

		X.push_back((matrix[i][SIZE] - sum) / matrix[i][SIZE - 1 - X.size()]);
	}

	return X;
}
