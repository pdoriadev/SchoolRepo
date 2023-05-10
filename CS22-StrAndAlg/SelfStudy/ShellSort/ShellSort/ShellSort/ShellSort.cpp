// ShellSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void shellSort(int arr[], int size, int gapSequence[], int sequenceSize);
int insertionSortInterleaved(int arr[], int size, int gap, int startIndexOfLeaf, int* totalSwaps);
int main()
{
	// measure number of swaps in arrays of equal size. 
	int unsortedArr[] = { 5, 1, 9, 7, 34, 99, 16, 7, 99, 100, 1, 4, 6 };
	int nearlySortedArr[] = { 1, 1, 4, 6, 5, 7, 9, 7, 16, 34, 99,99, 100 };
	int sortedArr[] = { 1, 1, 4, 5, 6, 7, 7, 9, 16, 34, 99, 99, 100 };
	int gapSequence[] = { 7, 3, 1 };
	int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
	int sequenceSize = sizeof(gapSequence) / sizeof(gapSequence[0]);
	
	std::cout << '\n' << "--> UNSORTED LIST - Gap = 5 <--" << std::endl;
	shellSort(unsortedArr, size, gapSequence, sequenceSize);

	std::cout << '\n' << "--> NEARLY SORTED LIST - Gap = 5 <--" << std::endl;
	shellSort(nearlySortedArr, size, gapSequence, sequenceSize);

	std::cout << '\n' << "--> SORTED LIST - Gap = 5 <--" << std::endl;
	shellSort(sortedArr, size, gapSequence, sequenceSize);
}
/*
	separate array into different "leaves" by leafSize value. for every upperBoundsOfLeaf, sort upperBoundsOfLeaf elements.
		for every upperBoundsOfLeaf elements sorted, upperBoundsOfLeaf += upperBoundsOfLeaf;

*/
void shellSort(int arr[], int size, int gapSequence[], int sequenceSize)
{
	std::cout << "BEFORE SHELL-SORT: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i + 1 < size)
		{
			std::cout << ", ";
		}
	}

	int totalSwaps = 0;
	int totalComparisons = 0;
	for (int i = 0; i < sequenceSize; i++)
	{
		for (int startIndex = 0; startIndex < gapSequence[i] && startIndex + gapSequence[i] < size; startIndex++)
		{
			totalComparisons += insertionSortInterleaved(arr, size, gapSequence[i], startIndex, &totalSwaps);
		}
	}

	std::cout << "\n\n" << "AFTER SHELL SORT: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i + 1 < size)
		{
			std::cout << ", ";
		}
	}
	std::cout << "\n";
	std::cout << "TOTAL COMPARISONS: " << totalComparisons;
	std::cout << '\n' << "TOTAL SWAPS: " << totalSwaps << '\n';

}

// returns comparisons made this sort
int insertionSortInterleaved(int arr[], int size, int gap, int startIndexOfLeaf, int* totalSwaps)
{
	std::cout << "\n\n" << "UNSORTED LEAF: ";
	for (int i = startIndexOfLeaf; i < size; i += gap)
	{
		std::cout << arr[i];
		if (i + gap < size)
		{
			std::cout << ", ";
		}
	}
	std::cout << '\n' << "Gap Value: " << gap;

	int comparisons = 0;
	int swapsMadeThisLeaf = 0;
	// iterate across gaps in list. Sort those indexes accessed. For every index+gap, access values at indices and compare them using 
		// an insertion sort. 
	for (int i = startIndexOfLeaf + gap; i < size; i+=gap) 
	{
		int num = arr[i];
		int insertPos = -1;
		for (int j = i-gap; j >= startIndexOfLeaf; j-=gap) // iterates backward through "sorted" part of list to see where to sort arr[i]
		{
			if (num < arr[j]) // arr [i] is less than the value at arr[j]. arr[i] should be inserted at arr[j]
			{
				insertPos = j;
			}
			comparisons++;
		}

		if (insertPos > -1)
		{
			for (int p = i; p > insertPos; p-=gap) // shifts values over to make room for value at arr[i+1]
			{
				arr[p] = arr[p - gap];
				swapsMadeThisLeaf++;
			}
			arr[insertPos] = num;
			swapsMadeThisLeaf++;
		} 
		// else, no swaps.
	}

	std::cout << "\n" << "SORTED LEAF: ";
	for (int i = startIndexOfLeaf; i < size; i+=gap)
	{
		std::cout << arr[i];
		if (i + gap < size)
		{
			std::cout << ", ";
		}
	}
	std::cout << '\n' << "Swaps Made this Leaf: " << swapsMadeThisLeaf;
	std::cout << '\n' << "Comparisons made this leaf: " << comparisons;

	*totalSwaps += swapsMadeThisLeaf;
	return comparisons;
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
