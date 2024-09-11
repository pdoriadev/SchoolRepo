#pragma once
namespace Algos
{
	static int EuclidGCD(long lowerOrEqual, long long higherNumber)
	{
		if (lowerOrEqual > higherNumber)
			return -1;
		int rem = higherNumber % lowerOrEqual;
		std::cout << lowerOrEqual << "  " << higherNumber << "  " << rem << '\n';
		while (rem > 0)
		{
			higherNumber = lowerOrEqual;
			lowerOrEqual = rem;
			rem = higherNumber % lowerOrEqual;
			std::cout << lowerOrEqual << "  " << higherNumber << "  " << rem << '\n';
		}

		return lowerOrEqual;
	}

};