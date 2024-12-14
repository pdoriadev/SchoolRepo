#pragma once
# include <iostream>

namespace Factorial
{
	///////////////////////////////////////////
	// Factorial
	///////////////////////////////////////////
	// example of directly recursive function
	int factorial(int n, bool verbose)
	{	
		static int calls = 0;
		calls++;
		if (calls > 5)
		{
			std::cout << "\n\t\t";
			calls = 0;
		}

		// base case
		if (n == 0)
		{
			if (verbose)
			{
				std::cout << 1;
			}

			return 1;
		}

		if (verbose)
		{
			std::cout << n << " * ";
		}
		// general case
		return n * factorial(n - 1, true); // tail recursive
	}
}
//////////////////////////////////////////////
// 	So I don't need to find which things to comment out in main
//		every time I want to test out a different recursive
//		algorithm
static void doFactorial()
{
	int n = 10;
	std::cout << "Factorial of " << n << " = ";
	std::cout << " = " << Factorial::factorial(n, true);
	std::cout << "\n";
}