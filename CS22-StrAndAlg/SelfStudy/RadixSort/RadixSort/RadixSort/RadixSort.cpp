/*
FILE: RadixSort.cpp
PURPOSE: Illustrate how radix sort works with comments, examples, and stats for each example 'run' of a radix sort
AUTHOR: Peter Doria


*/

/* LIBRARIES */
#include <iostream>
#include <vector>

/* METHODS */
void radixSort(int arr[], int size);
// get max "place" for any digit in the array (i.e. 1's place, 10's place, 100's place, etc.)
int getMaxPlace(int arr[], int size);
void countingSort(int arr[], int size, int place);
void doPreSortSetup(int arr[], int arrSize, std::string listName);
void doPostSortFinish(int arr[], int arrSize);
void resetSortStats();
void outputSortStats();
void outputArrayToConsole(int arr[], int size);
void outputVectorToConsole(std::vector<int> vec);

/* GLOBAL SORT STATS */
int n = 0; // array size
int loops = 0;
int swapCount = 0;

/* IMPLEMENTATION */
int main()
{
    // measure number of swaps in arrays of equal size. 
    int unsortedArr[] = { 5, 1, 9, 7, 34, 99, 16, 7, 99, 100, 1, 4, 6 };
    int nearlySortedArr[] = { 1, 1, 4, 6, 5, 7, 9, 7, 16, 34, 99, 99, 100 };
    int sortedArr[] = { 1, 1, 4, 5, 6, 7, 7, 9, 16, 34, 99, 99, 100 };
    int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

    // represents the max base 10 digit found in the array
	int maxPlace = getMaxPlace(unsortedArr, size);
    
    doPreSortSetup(unsortedArr, size, "UNSORTED ARR");
    radixSort(unsortedArr, size);
    doPostSortFinish(unsortedArr, size);

    doPreSortSetup(nearlySortedArr, size, "NEARLY SORTED ARR");
    radixSort(nearlySortedArr, size);
    doPostSortFinish(nearlySortedArr, size);

    doPreSortSetup(sortedArr, size, "SORTED ARR");
    radixSort(sortedArr, size);
    doPostSortFinish(sortedArr, size);
}

// place each element into a bucket
void radixSort(int arr[], int size)
{
	int maxPlace = getMaxPlace(arr, size);
	
	for (int place = 1; place <= maxPlace; place *= 10)
	{
		countingSort(arr, size, place);
		loops++;
	}
}

// best, worst, and average time complexity of O(n)
int getMaxPlace(int arr[], int size)
{
	int maxPow = 1;
	// what is element's greatest base digit (i.e. the 1's place, the 10's place)
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= maxPow * 10)
        {
            while (arr[i] >= maxPow * 10)
            {
                maxPow *= 10;
            }
        }

		loops++;
    }

	// i.e. if maxPow returned is 1, then 10 bukcets will be created for the 1's place from 0-9
	return maxPow;
}

// Modified Counting Sort
// see for normal counting sort algorithm: https://www.youtube.com/watch?v=OKd534EWcdk
// count the number of digits that pop up in the array that match that base (i.e. base 1, base 10, base 100, etc.)
    // 5 goes into the 5 bucket for base 1
    // 50's "5" goes into the 5 bucket for base 10. 50's '0' will go into the 0 bucket if the base is 1.
void countingSort(int arr[], int size, int place)
{
	std::vector<int> placeValues(size);
	for (int i = 0; i < size; i++)
	{
		// calculation that extratcts the digit in the decimal place we are looking for.
			// The "i" location in arr[] matches its' single digit counterpart's 'i' location in placeValues
		/* https://www.quora.com/How-can-you-mathematically-extract-a-single-digit-from-a-number */
		placeValues[i] = (arr[i] / place) % 10;
		loops++;
	}
	std::cout << '\n' << "Step 0 - Create array based on correct 'place' in element: ";
	outputVectorToConsole(placeValues);

	// get maximimum value in array
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (placeValues[i] > max)
			max = placeValues[i];
		loops++;
	}
	std::cout << '\n' << "Step 1 - Max value: " << max;

	// create temp array of size: max+1
	std::vector<int> count(max + 1);
	// count number of occurrences of a number in temp array
	for (int i = 0; i < size; i++)
	{
		count[placeValues[i]]++; 
		loops++;
	}

	std::cout << '\n' << "Step 2 - Count Array: ";
	outputVectorToConsole(count);

	// cumulative sum of occurrences of values in array
	for (int i = 0; i < max; i++)
	{
		count[i + 1] += count[i];
		loops++;
	}
	std::cout << '\n' << "Step 3 - Cumulative Sum: ";
	outputVectorToConsole(count);

	// shift array to the right by one
	for (int i = max; i > 0; i--)
	{
		count[i] = count[i - 1];
		loops++;
	}
	count[0] = 0;
	std::cout << '\n' << "Step 4 - Shift array: ";
	outputVectorToConsole(count);

	// assign values to array based on how many times they pop up
	std::vector<int> tempSorted(size);
	for (int i = 0; i < size; i++)
	{
		// the element at count[placeValues[i]] corresponds to where placeValues[i]'s corresponding 
			// arr[i] should go when sorted. count[arr[i]] represents the sorted index
			// for arr[i] in a sorted array.
		tempSorted[count[placeValues[i]]] = arr[i];
		count[placeValues[i]]++;
		loops++;
	}
	std::cout << '\n' << "Step 5 - Temp Sorted Array: ";
	outputVectorToConsole(tempSorted);

	// copy values into original array
	for (int i = 0; i < size; i++)
	{
		arr[i] = tempSorted[i];
		swapCount++;
		loops++;
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
		{
			std::cout << ", ";
		}
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
	n = arrSize;
}

void doPostSortFinish(int arr[], int arrSize)
{
    std::cout << '\n' << "Post-sort: ";
    outputArrayToConsole(arr, arrSize);
    outputSortStats();
}

void outputSortStats()
{
    std::cout << '\n' << "n = " << n;
	std::cout << '\n' << "Loops: " << loops;
    std::cout << '\n' << "Swaps: " << swapCount;
}

void resetSortStats()
{
	n = 0;
	loops = 0;
    swapCount = 0;
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
