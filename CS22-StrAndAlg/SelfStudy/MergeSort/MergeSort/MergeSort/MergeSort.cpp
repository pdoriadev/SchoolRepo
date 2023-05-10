// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Merge sort is a sorting algorithm that 
    divides an array into two halves, 
    recursively sorts each half, 
    and merges the sorted halves to produce a sorted array. 

Merge sort uses two functions: Merge() and MergeSort(). 
    The Merge() function merges two sequential, sorted partitions within an array and has four parameters:
        The array of numbers containing the two sorted partitions to merge
        The start index of the first sorted partition
        The end index of the first sorted partition
        The end index of the second sorted partition
    The MergeSort() function sorts a partition in an array and has three parameters:
        The array containing the partition to sort
        The start index of the partition to sort
        The end index of the partition to sort
        If the partition size is greater than 1, the MergeSort() function recursively sorts the left 
            and right halves of the partition, then merges the sorted halves together. 
            When the start index is 0 and the end index is the array length minus 1, 
            MergeSort() sorts the entire array.

    MergeSort recursively divides the list into two halves.
    The list is divided until a list of 1 element is found.
    A list of 1 element is already sorted.
    At each level, the sorted lists are merged together while maintaining the sorted order.
*/

#include <iostream>
#include <vector>

void mergeSort(int arr[], int i, int k);
void merge(int arr[], int i, int j, int k);
void doPreSortSetup(int arr[], int arrSize, std::string listName);
void doPostSortFinish(int arr[], int arrSize);
void incrementSwapCount();
void incrementComparisonCount();
void resetSortStats();
void outputSortStats();
void outputArrayToConsole(int arr[], int size);

int swapCount = 0;
int comparisonCount = 0;
int mergeSortCalls = 0;
int mergeCalls = 0;

int main()
{
    // measure number of swaps in arrays of equal size. 
    int unsortedArr[] = { 5, 1, 9, 7, 34, 99, 16, 7, 99, 100, 1, 4, 6 };
    int nearlySortedArr[] = { 1, 1, 4, 6, 5, 7, 9, 7, 16, 34, 99, 99, 100 };
    int sortedArr[] = { 1, 1, 4, 5, 6, 7, 7, 9, 16, 34, 99, 99, 100 };
    int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

    doPreSortSetup(unsortedArr, size, "UNSORTED ARR");
    mergeSort(unsortedArr, 0, size - 1);
    doPostSortFinish(unsortedArr, size);

    doPreSortSetup(nearlySortedArr, size, "NEARLY SORTED ARR");
    mergeSort(nearlySortedArr, 0, size - 1);
    doPostSortFinish(nearlySortedArr, size);

    doPreSortSetup(sortedArr, size, "SORTED ARR");
    mergeSort(sortedArr, 0, size - 1);
    doPostSortFinish(sortedArr, size);
}

/*
int i = starting index of left partition
int j = last index of right partition
*/
void mergeSort(int arr[], int i, int k)
{
    mergeSortCalls++;
    int j = 0;
    if (i < k)
    {
        j = (i + k) / 2;
        
        mergeSort(arr, i, j);
        mergeSort(arr, j + 1, k);

        merge(arr, i, j, k);
    }
}

/*
Create a temporary list for merged numbers. Initialize mergePos, leftPos, and rightPos to the first element of each of the corresponding list.
Compare the element in the left and right partitions. Add the smallest value to the temporary list and update the relevant indices.
Continue to compare the elements in the left and right partitions until one of the partitions is empty.
If a partition is not empty, copy the remaining elements to the temporary list. The elements are already in sorted order.
Lastly, the elements in the temporary list are copied back to the original list.

Params i, j, and k represent a low index, a midpoint, and a high index in an array.
iterate through values on left side and right side of arr at the same time.
Add whichever value is less than the other to a temp array. 
    Example:
        if (arr[leftPos] <= arr[rightPos])
            tempArr[i] = arr[leftPos];
            i++;
        else 
            tempArr[i] = arr[rightPos];
            i++;
*/
void merge(int arr[], int leftFirst, int leftLast, int rightLast)
{
    mergeCalls++;

    int leftPos = leftFirst;
    int rightPos = leftLast + 1;

    // k-leftFirst + 1 represents the number of elements between k and leftFirst (inclusive)
    std::vector<int> mergeArr(rightLast -leftFirst+1); // dynamically allocated array. 
    int mergePos = 0;

    // iterate through left and right array partitions simultaneously. 
        // assign the lesser value between the currently accessed values to
        // the temp array. We will eventually assign the values in the temp array
        // to the original array.
    while (leftPos <= leftLast && rightPos <= rightLast)
    {
        if (arr[leftPos] <= arr[rightPos])
        {
            mergeArr[mergePos] = arr[leftPos];
            leftPos++;
        }
        else
        {
            mergeArr[mergePos] = arr[rightPos];
            rightPos++;
        }

        mergePos++;
        comparisonCount++;
    }

    while (leftPos <= leftLast)
    {
        mergeArr[mergePos] = arr[leftPos];     
        leftPos++;
        mergePos++;
        comparisonCount++;
    }
    while (rightPos <= rightLast)
    {
        mergeArr[mergePos] = arr[rightPos];
        rightPos++;
        mergePos++;
        comparisonCount++;
    }

    for (int pos = 0; pos < rightLast-leftFirst+1; pos++)
    {
        arr[pos + leftFirst] = mergeArr[pos];
        swapCount++;
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

void incrementSwapCount()
{
    swapCount++;
}

void incrementComparisonCount()
{
    comparisonCount++;
}

void outputSortStats()
{
    std::cout << '\n' << "Comparisons: " << comparisonCount;
    std::cout << '\n' << "Swaps: " << swapCount;
    std::cout << '\n' << "mergeSort() Calls: " << mergeSortCalls;
    std::cout << '\n' << "merge() Calls: " << mergeCalls;
}

void resetSortStats()
{
    swapCount = 0;
    comparisonCount = 0;
    mergeSortCalls = 0;
    mergeCalls = 0;
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
