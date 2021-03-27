#include <iostream>
#include <vector>

using namespace std;

/*
	Solve 

	1	2	0		’1		8
	2	2	3	ı	’2	=	21
	0	3	2		’3		17

*/

typedef vector<vector<float>> Matrix;

struct —oefficients
{
	float* a;
	float* b;

	—oefficients(const int SIZE)
	{
		a = new float[SIZE];
		b = new float[SIZE];
	}

	~—oefficients()
	{
		delete a;
		delete b;
	}
};


void ShowMatrix(Matrix& matrix);

—oefficients* Get—oefficients(Matrix& matrix);
vector<float> SolveSystemOfLinearEquations(Matrix& matrix , —oefficients* coeff);


int main()
{	
	Matrix matrix
	{
		{ 1  ,  2  ,  0  ,  8}  ,
		{ 2  ,  2  ,  3  ,  21} ,
		{ 0  ,  3  ,  2  ,  17} ,
	};

	ShowMatrix(matrix);

	—oefficients* coeff  = Get—oefficients(matrix);
	vector<float> answer = SolveSystemOfLinearEquations(matrix, coeff);

	for (int i = answer.size() - 1, j = 1; i >= 0; --i, ++j)
		cout << "x" << j << "  =  " << answer[i] << endl;
}


void ShowMatrix(Matrix& matrix)
{
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << '\t';
		}

		cout << endl;
	}

	cout << endl << endl;
}


—oefficients* Get—oefficients(Matrix& matrix) // 1)
{
	const size_t  SIZE = matrix.size();
	—oefficients* coeff = new —oefficients(SIZE - 1);

	coeff->a[0] = matrix[0][1] / (-matrix[0][0]);
	coeff->b[0] = matrix[0][SIZE] / matrix[0][0];
	float z  = -matrix[1][1] - matrix[1][0] * coeff->a[0];

	for (size_t i = 1 ; i < SIZE - 1; ++i)
	{
		coeff->a[i] = matrix[i][i + 1] / z;
		coeff->b[i] = (-matrix[i][SIZE] + matrix[i][i - 1] * coeff->b[i - 1]) / z;
	}

	return coeff;
}


vector<float> SolveSystemOfLinearEquations(Matrix& matrix, —oefficients* coeff)
{
	const size_t  SIZE = matrix.size();
	vector<float> X;
	
	float x_n = (-matrix[SIZE - 1][SIZE]     + matrix[SIZE - 1][SIZE - 2] * coeff->b[SIZE - 2]) / // 2)
				(-matrix[SIZE - 1][SIZE - 1] - matrix[SIZE - 1][SIZE - 2] * coeff->a[SIZE - 2]);
				
	X.push_back(x_n);

	for (int i = SIZE - 2; i >= 0; --i) // 3)
	{
		X.push_back(coeff->a[i] * X.back() + coeff->b[i]);
	}

	return X;
}


