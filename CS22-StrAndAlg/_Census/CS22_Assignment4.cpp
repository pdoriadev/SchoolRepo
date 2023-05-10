/*
STUDENT NAME: Peter Doria                    CS-22 DATA STRUCTURES AND ALGORITHMS
SPRING 2022              		                 PROFESSOR THURSTON

ASSIGNMENT #4
Instructions
Sort the state census records by the adult population (adultPop) in ascending order using two sort methods:  Bubble sort and Selection sort.
Write two new files containing the sorted values. Much of this program is already written. You will need to
finish writing the main logic of the two sort functions

Do not change any other code other than in the sort functions.

RUBRIC:
Your program must compile without errors or warnings in Code::Blocks version 20.03 to receive 3 points.

You will earn 2.0 pts. for each correctly coded sort function (both functions must display the data sorted
in ascending order by adult population (adultPop)

1 pt. for writing each output file (use the file names already defined in the code)

Total 6 pts.
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//create structure for CensusData
struct CensusData
    {
        string state, totPop, adultPop, percentPop;
    };

//Function Prototypes
void bubbleSort(CensusData CenDataArr[], int);
void selectionSort(CensusData CenDataArr[], int );
void startarray(CensusData CenDataArr[]);

int main()
{
    CensusData CenDataArr[52]; //create structure array

    startarray(CenDataArr); // run function to enter file values in to array

    // Execute the selection sort
    selectionSort(CenDataArr,52);

    cout<<endl; //give space between for next output

    startarray(CenDataArr); //run function again to rescramble the values to be used

    //Execute the bubble sort
    BubbleSort(CenDataArr,52);

    return 0;

}

/************************************************************
 *                        startarray                        *
 * This function initializes the array to be sorted so that *
 * each array sorting method can sort the new array equally *
 *                                                          *
 ************************************************************/

void startarray(CensusData CenDataArr[])
{
 //intermittent variable to hold string variables temporarily
    string holdData;

    //declare MyData as my designated file
    ifstream MyData;

    //open the file designated by MyData
    MyData.open ("CensusData.CSV");


    if (!MyData)
        cout<<"The file could not be found";
        //proceed with program if the file exists
    else
    {   //begin loop to enter in all string items of structure
        for (int i = 0; i <52;i++)
        {
            getline(MyData,CenDataArr[i].state,','); //each getline uses a comma as a delimiter

            getline(MyData,CenDataArr[i].totPop,',');

            getline(MyData,CenDataArr[i].adultPop,',');

            getline(MyData,CenDataArr[i].percentPop);
        }
    }
    //close input file now.
    MyData.close();
}

/************************************************************
 *                        bubbleSort                        *
 * This function performs an ascending-order bubble sort on *
 * array. The parameter size holds the number of elements   *
 * in the array.                                            *
 *                                                          *
 * UPDATE THIS FUNCTION FIRST, THEN DO THE SELECTION SORT   *
 ************************************************************/
void bubbleSort(CensusData CenDataArr[], int size)
{
	CensusData temp[1]; //temporary variable is struct object to hold values
	bool L_madeAswap;   //bool flag to determine if a swap was made
    int intData1 = 0, intData2 = 0; //int values to hold converted strings
    int swapsMade = 0;      //counter to determine how many swaps are made

	do      //do loop makes sure the swap goes through the list at least once
	{	L_madeAswap = false;
		for (int count = 0; count < (size - 1); count++) // for loop compares adjacent adultPop values in the whole array
		{
		    //Convert the string variables to int data types for comparison
            // INSERT YOUR CODE HERE TO CONVERT STRING CenDataArr.adultPop [count] and [count+1] VALUES TO INT (can use stoi for example)

			if (intData1 > intData2) //if the first value compared is greater, then it will swap it
			{
            // INSERT YOUR CODE HERE TO SWAP THE VALUES
			}
		}
    } while (L_madeAswap);  // Loop again if a swap occurred on this pass.

        cout<<"Bubble sort has made "<<swapsMade<<" swaps which created the following array:\n\n";

        // Format and display headings
        cout << "BUBBLE SORT:" << endl;
        cout<<fixed<<setw(21)<<left<<"State/Territory"
            <<fixed<<setw(20)<<"Total Population"
            <<fixed<<setw(20)<<"Adult Population"
            <<fixed<<setw(5)<<"Percentage"<<endl;
        cout<<"\n----------------------------------------------------------------------------\n\n";

        // Prepare to write data to file
        ofstream writeFile;
         writeFile.open("CensusDataBubbleSorted.csv");
    if (!writeFile)
        cout<<"Error, bubble sorted file couldn't be opened";
    else
    {
        // Display and write data in order
        for(int i = 0; i < size;i++)
        {
            cout<<fixed<<setw(21)<<CenDataArr[i].state
            <<fixed<<setw(20)<<CenDataArr[i].totPop
            <<fixed<<setw(20)<<CenDataArr[i].adultPop
            <<fixed<<setw(20)<<CenDataArr[i].percentPop
            <<endl;

            // Write to file
            writeFile << CenDataArr[i].state<<","<<CenDataArr[i].totPop<<","
                  <<CenDataArr[i].adultPop<<","<<CenDataArr[i].percentPop<<"\n";
        }
        writeFile.close();
    }
}

/**************************************************************
 *                        selectionSort                       *
 * This function performs an ascending-order selection sort   *
 * on array. The parameter size holds the number of elements  *
 * in the array.                                              *
 *                                                            *
 * UPDATE THIS FUNCTION AFTER UPDATING THE BUBBLESORT         *
 **************************************************************/
void selectionSort(CensusData CenDataArr[], int size)
{
    int num1,num2, minIndex,swapsMade2 = 0; //all of these will hold a temporary value

    CensusData minValue[1]; // this creates an object to hold temporary object values

	for (int startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;           //the first index starts at 0
		minValue[0] = CenDataArr[startScan];    //the minimum value is the very first number now
		for(int index = startScan + 1; index < size; index++)
		{
		    //Convert the string variables into usable integer types for comparison (similar to bubbleSort conversion)
            // INSERT YOUR CODE HERE FOR CONVERSION

			if (num1 < num2) //if the number we have is less than number 2
			{
             // INSERT YOUR CODE HERE
			}

      }
		// INSERT YOUR CODE HERE TO update the array of structs to reflect the lowest value we found

		// INSERT YOUR CODE HERE TO update the smallest value and repeat the loop

	}
    // Format headings

    // INSERT YOUR CODE HERE FOR SELECTION SORT HEADINGS

	ofstream writeFile;      //   create an ofstream object called writefile
         writeFile.open("CensusDataSelectionSorted.csv"); //determine new destination
    if (!writeFile)
        cout<<"Error, selection sorted file couldn't be opened";  //error handling if it cannot be found
    else
    {
    // INSERT YOUR CODE HERE TO DISPLAY THE SELECTION SORT OUTPUT WHILE WRITING EACH RECORD
    for(int i = 0; i < size;i++)

        writeFile << CenDataArr[i].state<<","<<CenDataArr[i].totPop<<","<<CenDataArr[i].adultPop<<","<<CenDataArr[i].percentPop<<"\n";

    writeFile.close();}

	cout<<"selection sort made "<<swapsMade2<<" swaps.";
}
