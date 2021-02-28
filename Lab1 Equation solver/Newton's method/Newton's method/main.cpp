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

	f(-0.8) = 1
	f(-2) = -12

	f(-0.8) * f(-2) < 0

	A = [-2 , -0.8]

	∃ x ∈ A  :  f(x) = 0
	f'(x) > 0   x ∈ A
	f''(x) < 0  x ∈ A


	m1 = min |f'(x)| x ∈ A  = 4.12
	M1 = max |f'(x)| x ∈ A  = 19

	t_op = 2 / (m1 + M1) = 0.0865
*/


int main()
{

}