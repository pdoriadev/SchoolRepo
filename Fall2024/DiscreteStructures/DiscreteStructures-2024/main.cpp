#include <iostream>

#include "EuclidAlgo.h"
#include "UnitConversion.h"

int main()
{
	std::cout << "Discrete Structures - 2024" << '\n';

//	std::cout << "Greatest Commond Divisor: " << Algos::EuclidGCD(1996, 7548609);
//	std::cout << std::endl;
	
//	Algos::decimalToBinary(22, true);
	
    Algos::bisectionAlgorithm(0, 7548609);

	return 0;
}
