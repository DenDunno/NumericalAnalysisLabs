#include <iostream>
using namespace std;

/*
	Solve x^3 - 7x - 6 = 0
	f(x) = x^3 - 7x - 6
	f'(x) = 3x^2 - 7
	f''(x) = 6x 

	f''
		 -               +
	 ---------  0  ---------

	f(2) = -12
	f(4) = 30
	A = [2 , 4]

	1) f(x) ∈ C^2(A)
	2) f(2) * f(4) < 0   ]

	∃ x ∈ A  :  f(x) = 0

	3) f''(x) doesn't change sign on A

	Let x0 = 4
	4) f(4) * f''(4) > 0
	1-4) conditions are met for using Newton's method
*/

long double f(long double x);

int main()
{
	long double x_first = 3.5;
	long double x_second = 4;
	long double temp;
	const int iterations = 5;

	for (int i = 0; i < iterations; ++i)
	{
		temp = x_second;
		cout << "x" << i << " = " << x_second << endl;
		x_second = x_second - ((x_second - x_first) * f(x_second)) / (f(x_second) - f(x_first));

		x_first = temp;
	}

	cout << "x" << iterations << " = " << x_second << endl;
}


long double f(long double x)
{
	return powl(x, 3) - 7 * x - 6;
}
