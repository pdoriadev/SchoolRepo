#pragma once
#include <vector>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

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
        const char separator = ' ';
        const int columnWidth = 8;
        std::cout << std:: left << std::setw(columnWidth) << 'A' << std::setfill(separator)
                    << std:: left << std::setw(columnWidth) << "x input" << std::setfill(separator)
                    << std:: left << std::setw(columnWidth) << 'B' << std::setfill(separator)
                    << std:: left << std::setw(columnWidth) << "|x - A|" << std::setfill(separator)
                    << std:: left << std::setw(columnWidth) << "f(x)" << std::setfill(separator) ;

        std::vector<std::pair<double, double>> domainCodomainTable;

        double input = (greaterThanTarget - lessThanTarget) / 2;
        double output = pow(input, 5.3) + pow(3.5, input);
        domainCodomainTable.push_back(std::make_pair(input ,output));

        return 0;

        while (output - target < deltaErrorTolerance)
        {
            if (output - target < 0)
            {

            }
            if (output > target)
            {
                greaterThanTarget = (greaterThanTarget - target) / 2;
            }
            else
            {
                lessThanTarget = (target - lessThanTarget) / 2;
            }

            output = pow(input, 5.3) + pow(3.5, input);

        }

        return output;
	}
}
