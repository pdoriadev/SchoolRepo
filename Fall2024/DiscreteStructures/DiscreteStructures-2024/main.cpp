#include <iostream>

#include "EuclidAlgo.h"
#include "UnitConversion.h"
#include "BisectionAlgorithm.h"
#include "IncreasingSequences.h"

int main()
{
	std::cout << "Discrete Structures - 2024" << '\n';

	//std::cout << "Greatest Commond Divisor: " << Algos::EuclidGCD(1996, 7548609);
	//std::cout << std::endl;
	//
	//Algos::decimalToBinary(22, true);

    /*Algos::bisectionAlgorithm(10, 13, 7548609);*/

	int first = 1;
	int last = 9;
	std::vector<std::vector<int>> increasingSequences = Problem::IncreasingSequences(first, last);

	for (int i = 0; i < increasingSequences.size(); i++)
	{
		for (int j = 0; j < increasingSequences[i].size(); j++)
		{
			if (increasingSequences[i][j] == first - 1)
			{
				break;
			}

			std::cout << increasingSequences[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;

	return 0;
}
