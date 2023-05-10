/*
Peter Doria
Assignment 8                     CS-22 DATA STRUCtURES AND ALGORITHMS
SPRING 2023                               PROFESSOR THURSTON
Section 33968

----------------------------------------------
INSTRUCTIONS 
----------------------------------------------

This program shell includes code that checks for job files in the current directory. The program shell includes a Windows system call to get a 
    directory listing of the files in the current directory matching the file name "Triangle*.txt" and will save the results in a text file 
    that looks like this: Assignment8JobQueue.txt Download Assignment8JobQueue.txt

Your program will parse (read and search through) the file resulting from the Windows system call (call it Assignment8JobQueue.txt) listing 
    all the files in the current directory that start with "triangle" and end with ".txt". The C++ function "getline" is useful for this. 
    Place these file names in a queue implemented as a linked list since you won't know how many files are in the directory.

Once you know the names of the files you will open them one by one by dequeueing the file names from the queue, read the user input saved in 
    the file, and draw the triangle using code you wrote or modified from prior assignments.

IMPORTANT: Delete or rename each file once you've read its contents and drawn the triangle so your program doesn't process it again.

The only output to the screen should be the triangles being drawn as the program processes the job queue. You can call the Windows sleep() 
    C++ function in Program 2 in between displaying lines of the triangle to slow down the drawing which will lengthen the time it takes 
    to process the queue, allowing you an opportunity to replenish the queue using Program 1.  (While debugging the program it may be 
    helpful to output/display the name of each file before you execute drawing the triangle with the number of lines specified in the file. 
    Then comment out this code before submitting.)

Once you've processed all the job files in the queue the program should loop back to the system call to look for more files.  
    If no files are found, the program should display a message "waiting for more files (type <Ctrl+C> to end." and then use 
    a "sleep(1000)" command to pause between checking for more files and redisplaying the "waiting for more files..." message.  
    If the user types "<Ctrl+C>, the operating system will end the program.

While Program 2 is running in one console window you should run Program 1 in another window and create additional job files 
    for Program 2 to process.

IMPORTANT: If you need clarification of any of these requirements, please ask in the "Course Questions" discussion page, or attend 
    office hours.  If my scheduled hours do not work for you, please request a couple of times you can attend alternatively and 
    I'll try to accommodate your schedule.

Rubric:

Maximum 3 pts. if program2 does not compile without errors and appears to have implemented the required functionality for the assignment.

4 pts. Creation of queue containing file names to process

3 pts. reading each .txt file and drawing the triangle on the screen (pausing between each triangle for a second or two so that 
    the display doesn't flash by so quickly that it is impossible to see the output clearly)

2 pt.  looping to replenish the queue with more file names

WHAT TO SUBMIT: Your source code file named <FirstName><LastName>_CS22_Assignment8.cpp

*/


// libraries
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>

struct ListNode
{
    std::string fileName;
    ListNode* nextNode;
    ListNode(std::string _fileName, ListNode* _nextNode = NULL)
    {
        fileName = _fileName;
        nextNode = _nextNode;
    }
};

void drawTriangle(int lines);
ListNode* searchForJobs(std::ifstream& triangleFileNameList);

int main()
{
    std::string assignmentName = "Assignment8jobQueue.txt";
    std::string dirCmd = "dir triangle*.txt > " + assignmentName;
    bool processJobs = true;

    while (processJobs)
    {
        // reads all file names that start with triangle into a file called Assignment8jobQueue.txt
        ListNode* jobQueue = NULL;
        while (jobQueue == NULL)
        { 
            system(dirCmd.c_str());
            std::ifstream triangleFileNameList(assignmentName);
            if (!triangleFileNameList)
            {
                std::cout << "Failed to open a file to write list of job files.";
            }

            jobQueue = searchForJobs(triangleFileNameList);
            triangleFileNameList.close();
            if (jobQueue != NULL)
                break;

            std::cout << "\n. . . waiting for more files (type <Ctrl+C> to end).";
            Sleep(1000);
        }

        Sleep(50);

        std::ifstream triangleFile;
        ListNode * node = jobQueue;
        while (node)
        {
            triangleFile.open(node->fileName);
            if (!triangleFile)
            {
                std::cout << "\nERROR opening triangle job file.";
                /*
                    dequeueing node
                */
                ListNode* nextNode = node->nextNode;
                delete node;
                node = nextNode;
                continue;
            }

            std::string linesInTriangle;
            std::getline(triangleFile, linesInTriangle);
            triangleFile.close();

            int lines = std::stoi(linesInTriangle);
            drawTriangle(lines);

            std::string renameFileCommand = "ren " + node->fileName + " ~" + node->fileName;
            system(renameFileCommand.c_str());

            /*
                dequeueing node
            */
            ListNode* nextNode = node->nextNode;
            delete node;
            node = nextNode;
        }
    }

    return 0;
}

/************************************************************
 *                        searchForJobs                     *
 * Function description                                     *
 *      Searches for files that match the naming format
 * for triangle jobs. If a file is found, its name is added
 * to a job queue to be processed.
 *      Returns head of job queue linked list.              *
 ************************************************************/
ListNode * searchForJobs(std::ifstream& triangleFileNameList)
{
    std::string extractedFileName;
    ListNode* jobQueue = NULL;
    ListNode* node = NULL;
    while (std::getline(triangleFileNameList, extractedFileName, 'M'))
    {
        if (extractedFileName[extractedFileName.length() - 1] != 'P')
        {
            std::getline(triangleFileNameList, extractedFileName);
            continue;
        }

        std::getline(triangleFileNameList, extractedFileName, '2');
        std::getline(triangleFileNameList, extractedFileName, ' ');
        std::getline(triangleFileNameList, extractedFileName); // <--- gets actual file name

        // add to head
        if (node == NULL)
        {
            jobQueue = new ListNode(extractedFileName, NULL);
            node = jobQueue;
        }
        else // add to tail - append to list
        {
            node->nextNode = new ListNode(extractedFileName, NULL);
            node = node->nextNode;
        }

    }
    std::cout << "\n\nNo more files to process . . . ";

    return jobQueue;
}

/************************************************************
 *                        drawTriangle                      *
 * Function description                                     *
 * Draw triangle using '*' character                        *
 * Triangle should look like the image below, will have     *
 * the number of lines specified by the user                *
 *  *                                                       *
 *  **                                                      *
 *  ***                                                     *
 *  ****                                                    *
 *  *****                                                   *
 *                                                          *
 ************************************************************/
void drawTriangle(int lines)
{
   int i,j;
    for (i=1; i<lines; i++)
    {
        for (j=0; j<i; j++)
        {
            std::cout << "*";
            Sleep(10);            // Make the Sleep parameter larger or smaller if you'd like
        }
        std::cout << "\n";

    }
}
