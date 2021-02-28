#include<iostream>
#include <cmath>
using namespace std;


/*
	Solve x^3 - 2x^2 - x + 2 = 0

	f(x) = x^3 - 2x^2 - x + 2
	f'(x) = 3x^2 - 4x - 1

	   +                  -                 +
	-------  -0.21  -------------  1.55  -------
	          max                   min

	f(-0.8) = 1
	f(-2) = -12

	f(-0.8) * f(-2) < 0

	A = [-2 , -0.8]

	∃ x ∈ A  :  f(x) = 0
	f'(x) > 0   x ∈ A


	m1 = min |f'(x)| x ∈ A  = 4.12
	M1 = max |f'(x)| x ∈ A  = 19

	t_op = 2 / (m1 + M1) = 0.0865
*/

long double f(long double x);
long double f_derivative(long double x);

	
int main()
{
	long double epsilon = 1e-3;
	long double x = -0.8;
	long double z = -x;

	long double m = abs(f_derivative(-0.8));
	long double M = abs(f_derivative(-2));

	long double t_opt = 2 / (m + M);
	long double q = (M - m) / (m + M);

	int iterations = int(log((abs(z) / epsilon) / (abs(1 / q)))) + 1;
	
	for (int i = 0; i < iterations; ++i)
	{
		cout << "x" << i << " = " << x << endl;
		x = x - t_opt * f(x);
	}

	cout << "x" << iterations << " = " << x << endl;

	return 0;
}


long double f(long double x)
{
	return powl(x, 3) - 2 * powl(x, 2) - x + 2;
}


long double f_derivative(long double x)
{
	return 3 * powl(x, 2) - 4 * x - 1;
}
