#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Problem: Integrate 2x^4 + 2x^2 from 0 to 1

double f(double x);
double IntegrateFunction(const double A, const double B, const double EPSILON);


int main() 
{
	const double A = 0;
	const double B = 1;
	const double EPSILON = 0.001f;

	auto answer = IntegrateFunction(A , B , EPSILON);

	cout << answer << endl;

	return 0;
}


double f(double x)
{
	return 2 * powl(x, 4) + 2 * powl(x, 2);
}


double IntegrateFunction(const double A, const double B, const double EPSILON)
{
	double I = EPSILON + 1;
	double I1 = 0; 

	for (int n = 2; (n <= 4) || (fabs(I1 - I) > EPSILON); n *= 2)
	{
		double distance = (B - A) / (2.0 * n);
		double sum = 0;
		double sum2 = 0;
		double sum4 = 0;

		for (int i = 1; i <= 2 * n - 1; i += 2)
		{
			sum4 += f(A + distance * i);
			sum2 += f(A + distance * (i + 1.0));
		}

		sum = f(A) + 4 * sum4 + 2 * sum2 - f(B);

		I = I1;
		I1 = (distance / 3) * sum;
	}

	return I1;
}
