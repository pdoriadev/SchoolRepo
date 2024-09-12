#pragma once

namespace Algos
{/*1. f(x) must be a continuous and computable function.
2. A target value T for the function f(x) must be specified
3. An x-value A where f(A) < T must be specified. // “guessed” somehow
4. An x-value B where f(B) > T must be specified. // “guessed” too
5. A bound d on the absolute error in the approximation must be given.*/
	double bisectionAlgorithm(double lessThanTarget, 
								double greaterThanTarget, 
								double target,
								double deltaErrorTolerance )
	{
		double x = (greaterThanTarget - lessThanTarget) / 2;

		while ()

		return x;
	}
}