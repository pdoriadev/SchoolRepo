#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

namespace Algos
{/*1. f(x) must be a continuous and computable function.
2. A target value T for the function f(x) must be specified
3. An x-value A where f(A) < T must be specified. // “guessed” somehow
4. An x-value B where f(B) > T must be specified. // “guessed” too
5. A bound d on the absolute error in the approximation must be given.*/
	double bisectionAlgorithm(double startingInputFloor,
		double startingInputCeiling,
		double target,
		double deltaErrorTolerance)
	{

		double inputFloor = startingInputFloor;
		double inputCeiling = startingInputCeiling;
		double input = (inputCeiling - inputFloor) / 2;
		double output = inputCeiling;
		std::vector<std::pair<double, double>> orderedPairs;

		orderedPairs.push_back(std::make_pair(input, output));

		const char separator = ' ';
		const int columnWidth = 8;
		std::cout << std::left << std::setw(columnWidth) << "Floor" 
			<< std::left << std::setw(columnWidth) << "Target" << std::setfill(separator) << '|'
			<< std::left << std::setw(columnWidth) << "Ceiling" << std::setfill(separator) << '|'
			<< std::left << std::setw(columnWidth) << "|z - A|" << std::setfill(separator) << '|'
			<< std::left << std::setw(columnWidth) << "f(z)" << std::setfill(separator) << '|'
			<< std::endl;

		while (inputCeiling - output < deltaErrorTolerance)
		{
			if (output > target)
			{
				inputCeiling = target + (inputCeiling - target) / 2;
			}
			else if (output < target)
			{
				inputFloor = inputFloor + (target - inputFloor) / 2;
			}

			input = (inputCeiling - inputFloor) / 2;
			output = std::pow(input, 5.3) + std::pow(3.5, input);

			std::cout << std::left << std::setw(columnWidth) << inputFloor 
				<< std::left << std::setw(columnWidth) << target << std::setfill(separator) << '|'
				<< std::left << std::setw(columnWidth) << inputCeiling << std::setfill(separator) << '|'
				<< std::left << std::setw(columnWidth) << input - inputFloor << std::setfill(separator) << '|'
				<< std::left << std::setw(columnWidth) << output << std::setfill(separator) << '|' 
				<< std::endl;

			orderedPairs.push_back(std::make_pair(input, output));
			
			if (orderedPairs.size() > 2)
			{
				int timesGettingFarther = 0;
				for (int i = 3; i > 0; i--)
				{
					if (std::abs(target - orderedPairs[orderedPairs.size() - i].second)
						< std::abs(target - orderedPairs[orderedPairs.size() - i - 1].second))
					{
						timesGettingFarther++;
					}
				}

				if (timesGettingFarther >= 3)
				{
					inputFloor = startingInputFloor * 0.01;
					inputCeiling = startingInputCeiling * 100;

					orderedPairs.clear();
				}
			}
		}

		return output;
	}
}