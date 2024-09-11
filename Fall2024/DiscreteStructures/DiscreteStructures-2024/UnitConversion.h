#pragma once
#include <string>
#include <iostream>

namespace Algos
{
	std::string decimalToBinary(int decimal, bool consoleStatementsOn = false)
	{
		if (consoleStatementsOn)
		{
			std::cout << "Decimal to Binary Conversion for " << decimal << '\n';
			std::cout << "--------------------------------" << std::endl;
		}

		std::string binary = "";
		while (decimal != 0)
		{
			if (decimal % 2 == 0)
			{
				binary.insert(binary.begin(), '0');
			}
			else
			{
				binary.insert(binary.begin(), '1');
			}

			if (consoleStatementsOn)
			{
				std::cout << decimal << " / " << '2' << " --> remainder: " << decimal % 2 << std::endl;
			}

			decimal /= 2;
		}

		return binary;
	}
}