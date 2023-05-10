//#include "Peter_Doria_CS22_Program1.h"
/*
STUDENT NAME: Peter Doria                           CS-22 Data Structures and Algorithms
SEMESTER: Spring 2023                                      PROFESSOR THURSTON
SECTION: 33968
ASSIGNMENT #: 1
-------------------------------------------------------------------------------------------
Instructions

Write a C++ program that reads students’ names and test scores from a text file.
The program should output each student’s name followed by their test score and the grade.
You will create the data for each student, using fictitious names, scores, and grades.

Student data should be stored in a struct variable of type studentType, which has four components:
studentFirstName and studentLastName of type string,
testScore of type int (testScore is between 0 and 100),
and grade of type char. (1 pt.)

Assume that the class has 20 students. Use an array of 20 structs of type studentType. (1 pt.)

Your program must contain at least the following functions and the function "main" should only be a collection of function calls.

a. A function to read the students’ data from the input text file into the array of structs. (1 pt.)

b. A function to assign the relevant grade to each student and find the highest score. (1 pt.)

c. A function to print each student's name followed by their test score and their grade to the console. (1 pt.)

d. A function to print the highest test score and the name of the student(s) having the highest test score. (1 pt.)

Your program must output the file information in three columns (no need to print a column separator character, but you should align each type of data left justified):

LastName, FirstName                                       Score                      Grade

--------------------------------------------------------------------------------

SampleLastName1, SampleFirstName1        80                              B

SampleLastName2, SampleFirstName2        90                              A


---------------------------------------------------------------------------------
***************************************/


// libraries
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct studentType              // Updated by instructor
{
	string first = "fake name";
	string last = "fake name";
	int score = 999;
	char grade = 'X';
};

// function prototypes
int assignStudentData(studentType studentData[20] );
int assignGradesAndFindHighestScore(studentType studentData[20]);
void outputStudentData(studentType studentData[20], int maxNameLength);
void outputHighestScoringStudents(int highScore, studentType studentData[20]);

// main
int main()
{
	studentType studentData[20];
	int nameLengthBuffer = 4; // space required required to output student names into a nice column.
	int hScore = 0;

	nameLengthBuffer += assignStudentData(studentData);
	hScore = assignGradesAndFindHighestScore(studentData);
	outputStudentData(studentData, nameLengthBuffer);
	outputHighestScoringStudents(hScore, studentData);
}

// functions
	/************************************************************
	*                  AssignStudentData                        *
	* Function description:                                     *
	* Take in reference to text file and empty array of			*
	*	studentType. read through text file for each student's  *
	* unique data (name, score)									*
	* Assign each student's data to a unique struct in the		*
	* struct values to unique struct in array.					*
	* Returns length of longest name.							*
	************************************************************/
int assignStudentData(studentType studentData[20])
{
	ifstream studentDataFile;
	string studentDataStr;
	int lengthOfLongestName = 0;

	// read ifstream into a string
	studentDataFile.open("PeterDoria_CS22_Program1.txt");
    if (studentDataFile.fail())
    {
		cout << "No student data file provided \n";
		exit(1);
	}
    int i=0;
	while (!studentDataFile.eof())
	{
        studentDataFile >> studentData[i].first >> studentData[i].last >> studentData[i].score;       // You can read the whole line in C++ like this: studentDataFile >> s[i].first >> s[i].last >> s[i].score
        // if this name is longer than any other name we've looked at, update the longest length value.
		lengthOfLongestName = (studentData[i].first.length() + studentData[i].last.length()) > lengthOfLongestName
                                ? (studentData[i].first.length() + studentData[i].last.length()): lengthOfLongestName;
        i++;
    }
		studentDataFile.close();
		return lengthOfLongestName;
	}

	/************************************************************
	*                  Function Name                           *
	* Function description:                                    *
	*  Assigns relevant grade to each student. Finds highest   *
	* score.												   *
	*                                                          *
	************************************************************/
	// assignGradesAndFindHighestScore
int assignGradesAndFindHighestScore(studentType studentData[20])
{
	int hScore = 0;
	for (int i = 0; i < 20; i++)
	{
		// Assigns high score
		if (studentData[i].score > hScore)
		{
			hScore = studentData[i].score;
		}

		// Assigns relevant grade
		if (studentData[i].score > 89)
		{
			studentData[i].grade = 'A';
		}
		else if (studentData[i].score > 79)
		{
			studentData[i].grade = 'B';
		}
		else if (studentData[i].score > 69)
		{
			studentData[i].grade = 'C';
		}
		else if (studentData[i].score > 59)
		{
			studentData[i].grade = 'D';
		}
		else
		{
			studentData[i].grade = 'F';
		}
	}

	return hScore;
}


	/************************************************************
	*                  outputStudentData                           *
	* Function description:                                    *
	*													       *
	*                                                          *
	************************************************************/
void outputStudentData(studentType studentData[20], int maxNameLength)
{
	cout << left << setw(maxNameLength) << "Name" << left << setw(8) << "Score" << left << setw(8) << "Grade" << '\n' << '\n';
	cout << "----------------------------------------" << "\n\n";
	for (int i = 0; i < 20; i++)
	{
		cout << left << setw(maxNameLength) << studentData[i].last + ',' + studentData[i].first;
		cout << right << setw(8)<< studentData[i].score;
        cout << right << setw(8) << studentData[i].grade << "\n";
	}
	cout << "----------------------------------------" << "\n";
}


	/***********************************************************
	*               outputHighestScoringStudents               *
	* Function description:                                    *
	*													       *
	*                                                          *
	************************************************************/
void outputHighestScoringStudents(int highScore, studentType studentData[20])
{
	bool oneHighScorerAlreadyAssigned = false;
	cout << "HIGH SCORE: " << highScore << '\n';

	cout << setw(4) << "High Score Record Holders \n";
	cout << "-------------------------\n";
	for (int i = 0; i < 20; i++)
	{
		if (studentData[i].score == highScore)
		{
			cout << " - " << studentData[i].last << ',' << studentData[i].first << "\n";
			oneHighScorerAlreadyAssigned = true;

		}
	}
	cout << "\n\n\n\n";
}
