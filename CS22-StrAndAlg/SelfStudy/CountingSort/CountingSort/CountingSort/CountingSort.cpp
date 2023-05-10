// CountingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.youtube.com/watch?v=OKd534EWcdk 

#include <iostream>
#include<vector>

void countingSort(int arr[], int size);
void outputArrayToConsole(int arr[], int size);
void outputVectorToConsole(std::vector<int> vec);
void doPreSortSetup(int arr[], int arrSize, std::string listName);
void doPostSortFinish(int arr[], int arrSize);
void resetSortStats();
void outputSortStats();
void outputArrayToConsole(int arr[], int size);

/* GLOBAL SORT STATS */
int loopCount = 0;

int main()
{
	int unsortedArr[] = { 5, 1, 9, 7, 34, 99, 16, 7, 99, 100, 1, 4, 6 };
	int nearlySortedArr[] = { 1, 1, 4, 6, 5, 7, 9, 7, 16, 34, 99, 99, 100 };
	int sortedArr[] = { 1, 1, 4, 5, 6, 7, 7, 9, 16, 34, 99, 99, 100 };
	int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

	doPreSortSetup(unsortedArr, size, "UNSORTED ARR");
	countingSort(unsortedArr, size);
	doPostSortFinish(unsortedArr, size);

	doPreSortSetup(nearlySortedArr, size, "NEARLY SORTED ARR");
	countingSort(unsortedArr, size);
	doPostSortFinish(nearlySortedArr, size);

	doPreSortSetup(sortedArr, size, "SORTED ARR");
	countingSort(unsortedArr, size);
	doPostSortFinish(sortedArr, size);

}

void countingSort(int arr[], int size)
{
	// get maximimum value in array
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	std::cout << '\n' << "Step 1 - Max value: " << max;

	// create temp array of size: max+1
	// count number of occurrences of a number in temp array
	std::vector<int> count(max + 1);
	for (int i = 0; i < size; i++)
	{
		count[arr[i]]++; // increment value at index that matches value of arr[i]
	}
	
	std::cout << '\n' << "Step 2 - Count Array: ";
	outputVectorToConsole(count);

	// cumulative sum of occurrences of values in array
	for (int i = 0; i < max; i++)
	{
		count[i + 1] += count[i];
	}
	std::cout << '\n' << "Step 3 - Cumulative Sum: ";
	outputVectorToConsole(count);

	// shift array to the right by one
	for (int i = max; i > 0; i--)
	{
		count[i] = count[i - 1];
	}
	std::cout << '\n' << "Step 4 - Shift array: ";
	outputVectorToConsole(count);

	// assign values to array based on how many times they pop up
	std::vector<int> tempSorted(size);
	for (int i = 0; i < size; i++)
	{
		// the element at count[arr[i]] corresponds to where arr[i] should 
			// go when sorted. count[arr[i]] represents the sorted index
			// for arr[i] in a sorted array.
		tempSorted[count[arr[i]]] = arr[i];
		count[arr[i]]++;
	}
	std::cout << '\n' << "Step 5 - Temp Sorted Array: ";
	outputVectorToConsole(tempSorted);

	// copy values into original array
	for (int i = 0; i < size; i++)
	{
		arr[i] = tempSorted[i];
	}
	std::cout << '\n' << "Step 6 - Sorted Array: ";
	outputArrayToConsole(arr, size);
}

void outputArrayToConsole(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i + 1 < size)
			std::cout << ", ";
	}
}

void outputVectorToConsole(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i + 1 < vec.size())
			std::cout << ", ";
	}
}


void doPreSortSetup(int arr[], int arrSize, std::string listName)
{
	std::cout << '\n' << "--> " << listName << " <--";
	std::cout << '\n' << "Presort: ";
	outputArrayToConsole(arr, arrSize);
	resetSortStats();
}

void doPostSortFinish(int arr[], int arrSize)
{
	std::cout << '\n' << "Post-sort: ";
	outputArrayToConsole(arr, arrSize);
	outputSortStats();
}

void outputSortStats()
{
	std::cout << '\n' << "Loops: " << loopCount;
}

void resetSortStats()
{
	loopCount = 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
