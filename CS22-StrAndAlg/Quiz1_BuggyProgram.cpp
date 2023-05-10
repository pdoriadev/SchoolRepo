/*
STUDENT NAME: Peter Doria                           CS-22 Data Structures and Algorithms
SEMESTER: Spring 2023                                      PROFESSOR THURSTON
SECTION: 33968
ASSIGNMENT #: 1
-------------------------------------------------------------------------------------------
Instructions
Fix the coding syntax and logic errors in this C++ program Download C++ program.

Place comments in the code where you fixed the errors (you should find and fix 10 errors for full credit although there may be 11 errors total).

Save your file with the name <YourFirstName>_<YourLastName>_CS22_Quiz1Program.cpp. Substitute your name and leave out the '<' and '>' characters.

Upload your debugged program for credit (.1 pt. for each repaired error, 1 pt. for full credit, an extra .1 pt. if you find 11 errors).
-------------------------------------------------------------------------------------------
[COPY FROM CANVAS]


*/

// libraries
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

// Function Prototypes
void average();
void greeting();
void brownies();
void drawTriangle();
void timeConverter();
void percentageScore();

int main()
{
    int choice = 0;
    while (choice != 99) // menu loop
    {

	// display menu
        cout << "CS22 QUIZ 1: P R O G R A M   M E N U" << endl;
        cout << "====================================" << endl;
        cout << "[1]  Calculate the average of 2 numbers" << endl;
        cout << "[2]  Display a greeting" << endl;
        cout << "[3]  Calculate the number of brownies that will fit in a pan" << endl;
        cout << "[4]  Draw Triangle" << endl;
        cout << "[5]  Convert seconds to days/hours/minutes/seconds" << endl;
        cout << "[6]  Calculate grade percentage" << endl;
        cout << "[99] Quit" << endl << endl;

        cout << "ENTER A CHOICE ABOVE: ";
        cin >> choice;
        cout << "\n\n\n";

        switch(choice) // calls functions for each option
        {
        case 1:
            average();
            break;
        case 2:
            greeting();
            break;
        case 3:
            brownies();
            break;
        case 4:
            drawTriangle();
            break;
        case 5:
            timeConverter();
            break;
        case 6:
            percentageScore();
            break;
        case 99:
            exit(1);
        default:
            cout << "Invalid option, try again." << endl;
        }
        for (int i=0; i<5; i++)
          cout << "\n";
        for (int i=0; i<4000; i++);  // delay
    }
    return 0;
}

/************************************************************
 *                        Average                           *
 * Function description:                                    *
 * Calculate the average of two integers enter by user      *
 *                                                          *
 ************************************************************/
void average()
{
    int size = 2;             // The number of values to be averaged
    double num1,num2,average;           // Average of num1 and num2

    // Get the two numbers
    cout << "Enter two numbers separated by one or more spaces: ";
    cin  >> num1 >> num2;

    // Calculate the average
    average = num1 + num2 / size;

    // Display the average
    cout << "The average of the two numbers is: " << average << endl;
}

/************************************************************
 *                        Greeting                          *
 * Function description:                                    *
 * Prints a "Hello" greeting with the user's first name     *
 *                                                          *
 ************************************************************/
void greeting()
{
    string name;             // This declares a variable to
                             // hold the user's name
    // Get the user's name
    cout << "Please enter your first name: ";
    cin  >> name;

    // Print the greeting
    cout << "Hello, " << name << "." << endl;
}

/************************************************************
 *                        Brownies                          *
 * Function description:                                    *
 * Calculate the number of who brownies that will fit       *
 * in a baking pan with the size being input by the user.   *
 ************************************************************/
void brownies()
{
    int panLength, panWidth, brownieSize, surfaceArea, resultOne, resultTwo;

    brownieSize = 1;

    cout << "Please enter the pan width in inches: ";
    cin >> panWidth;

    cout << "Please enter the pan length in inches: ";
    cin >> panLength;

    surfaceArea = panWidth * panLength;

    resultOne = surfaceArea / brownieSize;

    brownieSize = 4;

    resultTwo = surfaceArea / brownieSize;

    cout << resultOne << " 1x1 inch brownies can fit\n";
    cout << resultTwo << " 2x2 inch brownies can fit";

}

/************************************************************
 *                        drawTriangle                      *
 * Function description                                     *
 * Draw triangle using '*' character                        *
 * Triangle should look like the image below:               *
 *                                                          *
 *  *                                                       *
 *  **                                                      *
 *  ***                                                     *
 *  ****                                                    *
 *  *****                                                   *
 *                                                          *
 ************************************************************/
void drawTriangle()
{
    int i,j;
    for (i=1; i<6; i++)
    {
        for (j=0; j<6; j++)
            cout << "*";
        cout << "\n";

    }
}

/************************************************************
 *                       timeConverter                      *
 * Function description:                                    *
 * Convert number of seconds entered by the user into       *
 * hours, minutes, and seconds                              *
 ************************************************************/
void timeConverter()
{
    int days, hours, minutes, seconds;
    long int userSeconds;

    cout << "Please enter the seconds in positive integer form: ";
    cin >> userSeconds;

    days = userSeconds / 86400;
    userSeconds = userSeconds - (days*86400);

    hours = userSeconds / 3600;
    userSeconds = userSeconds - (hours*3800);

    minutes = userSeconds / 60;
    userSeconds = userSeconds - (minutes*60);

    seconds = userSeconds;

    cout << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.";
}


/************************************************************
 *                        Percentage Score                  *
 * Function description:                                    *
 * Calculate grade percentage based on score                *
 *                                                          *
 ************************************************************/
void percentageScore()
{
    string name;
    int numQuestions, numCorrect;
    double percentage;

    // Get student's test data
    cout << "Enter student's first and last name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Number of questions on the test: ";
    cin  >> numQuestions;
    cout << "Number of answers the student got correct: ";
    cin  >> numCorrect;


    // Compute and display the student's % correct
    percentage = (numCorrect /  static_cast<doble>(numQuestions))*100;

    cout << name << " got a " << setprecision(1) << fixed << percentage << "% on their test.";
}
