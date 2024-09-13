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
    void bisectionAlgorithm(double startingInputFloor,
		double startingInputCeiling,
        int target)
	{
		const char separator = ' ';
        const int columnWidth = 16;
        std::cout
            << std::left << std::setw(columnWidth) << "ITERATION" << std::setfill(separator)
            << std::left << std::setw(columnWidth) << "FLOOR" << std::setfill(separator)
            << std::left << std::setw(columnWidth) << "CEILING" << std::setfill(separator)
            << std::left << std::setw(columnWidth) << "z" << std::setfill(separator)
            << std::left << std::setw(columnWidth) << "|z - A|" << std::setfill(separator)
            << std::left << std::setw(columnWidth) << "TARGET" << std::setfill(separator)
            << std::left << std::setw(columnWidth) << "f(z)" << std::setfill(separator);

        double inputFloor = startingInputFloor;
        double inputCeiling = startingInputCeiling;
        double input = (inputCeiling - inputFloor) / 2;
        double output;

        std::vector<std::pair<double, double>> inputsOutputs;

        int iteration = 0;
        const double deltaErrorTolerance = 0.00000000005;
        while (true)
		{
            // compute new value
            input = inputFloor + (inputCeiling - inputFloor) / 2;
			output = std::pow(input, 5.3) + std::pow(3.5, input);

            // update table
            inputsOutputs.push_back(std::make_pair(input, output));

            // output results of computation
            iteration++;
            std::cout <<  std::setfill('_') << std::setw(columnWidth * 7) <<'\n' << std::setfill(' ') << std::endl;

            std::cout
                << std::left << std::setw(columnWidth) << std::setprecision(7) << iteration
                << std::left << std::setw(columnWidth) << std::setprecision(7) << inputFloor
                << std::left << std::setw(columnWidth) << std::setprecision(7) << inputCeiling << std::setfill(separator)
                << std::left << std::setw(columnWidth) << std::setprecision(7) << input << std::setfill(separator)
                << std::left << std::setw(columnWidth) << std::setprecision(7) << input - inputFloor << std::setfill(separator)
                << std::left << std::setw(columnWidth) << std::setprecision(7) << target << std::setfill(separator)
                << std::left << std::setw(columnWidth) << std::setprecision(7) << output << std::setfill(separator)
                << '\n';

            // Test to see if equal up to decimal places.
            if (static_cast<int>(output) == static_cast<int>(target))
            {
                std::cout << std::setw(columnWidth * 7) << std::setfill('=') << '\n' << std::endl;
                std::cout << "\n==== FOUND 'z' EQUAL TO TARGET (up to decimal places): " << input << '\n';
                break;
            }

            // validate input ceiling/floor values
                // if this happens a lot, then the initial guessess
                // should be improved.
            if (inputCeiling - inputFloor < deltaErrorTolerance)
            {
                std::cout << "--> GUESSES INVALID " << '\n';
                if (output - target < 0)
                {
                    startingInputCeiling *= 2;
                    inputCeiling = startingInputCeiling;
                    std::cout << "------> Decreasing starting ceiling." << '\n';
                }
                else
                {
                    startingInputFloor *= .5;
                    inputFloor = startingInputFloor;
                    std::cout << "------> Decreasing starting floor." << '\n';
                }
            }

            //adjust input floor/ceiling
            if (output > target)
            {
                inputCeiling = inputCeiling - (inputCeiling - inputFloor) / 2;
                std::cout << "--> DECREASING CEILING";
            }
            else if (output < target)
            {
                inputFloor = inputFloor + (inputCeiling - inputFloor) / 2;
                std::cout << "--> INCREASING FLOOR";
            }

            std::cout << std::endl;
		}

        ////////////////////////////////////////////////////
        /// Find z value correct up to two significant digits
        int placesTilTwoSignificant = 0;
        {
            int targetForRoundingTest = static_cast<int>(target);
            int tens = 10;
            while (targetForRoundingTest > 9)
            {
                targetForRoundingTest -= targetForRoundingTest % tens;
                tens *= 10;
                placesTilTwoSignificant++;
            }

            if (placesTilTwoSignificant > 3)
            {
                placesTilTwoSignificant -= 2;
            }
            else if (placesTilTwoSignificant > 2)
            {
                placesTilTwoSignificant -= 1;
            }
        }

        int targetRoundedToTwoSignificant = static_cast<int>(target);
        for (int i = 1; i < placesTilTwoSignificant + 1; i++)
        {
            int tens = std::pow(10, i);
            int moduloResult = targetRoundedToTwoSignificant % tens;
            targetRoundedToTwoSignificant -= moduloResult;
        }

        double zValCorrectToTwoSignificant;
        for (int i = 0; i < inputsOutputs.size(); i++)
        {
            int outputInt = inputsOutputs[i].second;
            for (int j = 1; j < placesTilTwoSignificant + 1; j++)
            {
                int tens = std::pow(10, j);
                int moduloResult = outputInt % tens;
                outputInt -= moduloResult;
            }
            if (outputInt == targetRoundedToTwoSignificant)
            {
                zValCorrectToTwoSignificant = inputsOutputs[i].first;
                std::cout << "\n==== FOUND 'z' CORRECT UP TO TWO SIGNIFICANT FIGURES: " << zValCorrectToTwoSignificant << std::endl;
                break;
            }
        }

        /////////////////////////////////////////////////////
        /// Final Answers
        std::cout << "\n=================================================================\n"
                  << "a) z value correct to 2 significant figures: "
                  << std::right << std::setw(columnWidth / 2) << zValCorrectToTwoSignificant
                  << "\n================================================================="
                  << std::endl;

        std::cout << "=================================================================\n"
                  << "b) z value correct to the decimal place: "
                  << std::right << std::setw(columnWidth / 2) << inputsOutputs[inputsOutputs.size() - 1].first
                  << "\n================================================================="
                  << std::endl;
	}
}
