/*

STUDENT NAME: Peter Doria                            CS-22 Data Structures and Algorithms
SEMESTER: Spring                                    PROFESSOR THURSTON
SECTION: 33968
ASSIGNMENT #7
-------------------------------------------------------------------------------------------
Instructions
-------------------------------------------------------------------------------------------

Write a recursive function to generate the following pattern of stars when the user inputs the value 4 
    (you do not need to use a linked list for this program) :

   *   
  
  * *

 * * *

* * * *

 * * *

  * *
   
   * 
  

Write a program to prompt the user to enter the number of lines(between 4 and 12) in the pattern.
Your program should use a recursive function(a function that calls itself) to generate the pattern.For example, 
    specifying 4 as the number of lines generates the above pattern.

    Your program should create an output file described below.Run your program three times using 4, 8, and 12 
        as the number of lines.

    Output file requirements :
For each of the three executions of the display logic, on the line before and on the line after each
    recursive call to the function that prints the lines, write the address of the first local variable
    in your function to the output file.

"variableName" address = &variableName

where variableName is the name of a variable in your function, and& variableName is the address of the variable.

Name the file "VariableAddresses.txt". Here is an example Download exampleof how your file might look to 
demonstrate the memory being allocated at each call to the recursive function and being restored upon reaching 
the base case.

After your program creates the output file, use a text editor to write your analysis below the data your program created :

Describe any patterns you observe in the address values.

What to submit :

Zip together your source code fileand your output fileand name the file <firstName><lastName>Assignment7.zip.

Do not submit a project file from your IDE, only your source file(.cpp) and your output file.

RUBRIC :

    3 points max if your program does not compile

    2 points for correctly executing code

    1 point for analysis of address values

*/


#include <iostream>
#include <ostream>
#include <fstream>

void outputDiamond(std::ofstream& outputFile,  int maxStars);
void outputLineOfDiamond(std::ofstream& outputFile, int maxStars, int starsToPrintThisCall, bool maxReached);

/************************************************************
 * Takes in max number of Stars we want in our diamond and
 *   a reference to the file the diamond to output the file to.
 * Kicks off the recursive function calls that
 *  output our diamond
 ************************************************************/
void outputDiamond(std::ofstream& outputFile, int maxStarsInALine)
{
    outputFile << "\nMax stars in a line: " << maxStarsInALine;
    outputLineOfDiamond(outputFile, maxStarsInALine, 1, false);
    outputFile << "\nDiamond Complete. \n";
}

/************************************************************
 * Recursive Function that outputs diamond shape 
 * made of stars to a file
 ************************************************************/
void outputLineOfDiamond(std::ofstream& outputFile, int maxStars, int starsToPrintThisCall, bool maxReached)
{
    if (maxStars == starsToPrintThisCall)
        maxReached = true;
    int starsToPrintNextCall;
    if (maxReached)
    {
        if (starsToPrintThisCall == 0)
            return;
        starsToPrintNextCall = starsToPrintThisCall - 1;
    }
    else
    {
        starsToPrintNextCall = starsToPrintThisCall + 1;
    }

    outputFile << "\n Pre-Call:  i = " << starsToPrintThisCall << "   Address = " << &maxStars;
    outputLineOfDiamond(outputFile, maxStars, starsToPrintNextCall, maxReached);
    outputFile << "\n Post-Call: i = " << starsToPrintThisCall << "   Address = " << &maxStars;

    // Print initial spaces before first asterisk 
    std::cout << std::endl;
    for (int spaces = 0; spaces < maxStars - starsToPrintThisCall; spaces++)
    {
        std::cout << ' ';
    }

    // Print asterisks
    for (int i = 0; i < starsToPrintThisCall; i++)
    {
        std::cout << "* ";
    }
    std::cout << std::endl;

}

int main()
{
    std::ofstream outputFile("VariableAddresses.txt");

    int maxNumberOfStarsInDiamond;
    std::cout << "Enter max star length in new diamond: ";
    std::cin >> maxNumberOfStarsInDiamond;
    outputDiamond(outputFile, maxNumberOfStarsInDiamond);

    std::cout << "Enter max star length in new diamond: ";
    std::cin >> maxNumberOfStarsInDiamond;
    outputDiamond(outputFile, maxNumberOfStarsInDiamond);

    std::cout << "Enter max star length in new diamond: ";
    std::cin >> maxNumberOfStarsInDiamond;
    outputDiamond(outputFile, maxNumberOfStarsInDiamond);
}

