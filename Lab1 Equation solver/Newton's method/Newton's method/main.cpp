#include <iostream>
#include <cmath>
using namespace std;

/*
	Solve x^3 - 4x^2 + x + 6 = 0

	f(x) = x^3 - 4x^2 + x + 6
	f'(x) = 3x^2 - 8x + 1
	f''(x) = 6x - 8

	f''
         -               +
	 ---------  4/3  ---------

	f(0) = 6
	f(-2) = -19
	A = [-2 , 0]


	1) f(x) ∈ C^2(A)     
	2) f(0) * f(-2) < 0   ]  

	∃ x ∈ A  :  f(x) = 0

	3) f''(x) doesn't change sign on A
	
	Let x0 = -1.5

	4) f(-1.5) * f''(-1.5) > 0

	1-4) conditions are met for using Newton's method
*/


long double f(long double x);
long double f_derivative(long double x);


int main()
{
	long double x = -1.5;
	long double f_der2 = f_derivative(-1.5);

	const int iterations = 12;

	for (int i = 0; i < iterations; ++i)
	{
		cout << "x" << i << " = " << x << endl;
		x = x - f(x) / f_der2;
	}

	cout << "x" << iterations << " = " << x << endl;

	return 0;
}


long double f(long double x)
{
	return powl(x, 3) - 4 * powl(x, 2) + x + 6;
}


long double f_derivative(long double x)
{
	return 3 * powl(x, 2) - 8 * x + 1;
}

