// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void quickSort(int arr[], int lowIndex, int highIndex);
int partition(int arr[], int lowIndex, int highIndex);
void incrementSwapCount();
void incrementComparisonCount();
void resetSortStats();
void outputSortStats();
void outputArrayToConsole(int arr[], int size);

int swapCount = 0;
int comparisonCount = 0;
int quickSortCalls = 0;
int partitionCalls = 0;

int main()
{
    // measure number of swaps in arrays of equal size. 
    int unsortedArr[] = { 5, 1, 9, 7, 34, 99, 16, 7, 99, 100, 1, 4, 6 };
    int nearlySortedArr[] = { 1, 1, 4, 6, 5, 7, 9, 7, 16, 34, 99,99, 100 };
    int sortedArr[] = { 1, 1, 4, 5, 6, 7, 7, 9, 16, 34, 99, 99, 100 };
    int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

    int quizArr[] = { 36, 55, 89, 95, 65, 75, 13, 62, 86 };
    std::cout << '\n' << "--> UNSORTED LIST <--";
    std::cout << '\n' << "Presort: ";
    outputArrayToConsole(quizArr, 9);
    quickSort(quizArr, 0, 8);
    std::cout << '\n' << "Post-sort: ";
    outputArrayToConsole(quizArr, 9);
    outputSortStats();
    resetSortStats();


    std::cout << '\n' << "--> UNSORTED LIST <--";
    std::cout << '\n' << "Presort: ";
    outputArrayToConsole(unsortedArr, size);
    quickSort(unsortedArr, 0, size - 1);
    std::cout << '\n' << "Post-sort: ";
    outputArrayToConsole(unsortedArr, size);
    outputSortStats();
    resetSortStats();

    std::cout << "\n\n" << "--> NEARLY SORTED LIST <--";
    std::cout << '\n' << "Presort: ";
    outputArrayToConsole(nearlySortedArr, size);
    quickSort(nearlySortedArr, 0, size - 1);
    std::cout << '\n' << "Post-sort: ";
    outputArrayToConsole(nearlySortedArr, size);
    outputSortStats();
    resetSortStats();

    std::cout << "\n\n" << "--> SORTED LIST <--";
    std::cout << '\n' << "Presort: ";
    outputArrayToConsole(sortedArr, size);
    quickSort(sortedArr, 0, size - 1);
    std::cout << '\n' << "Post-sort: ";
    outputArrayToConsole(sortedArr, size);
    outputSortStats();
    resetSortStats();

    return 0;
}

void quickSort(int arr[], int lowIndex, int highIndex)
{
    quickSortCalls++;
    if (lowIndex >= highIndex)
    {
        return;
    }

    int lowEndIndex = partition(arr, lowIndex, highIndex);
    std::cout << '\n';
    outputArrayToConsole(arr, 9);
    quickSort(arr, lowIndex, lowEndIndex);
    quickSort(arr, lowIndex + 1, highIndex);
}

int partition(int arr[], int lowIndex, int highIndex)
{
    partitionCalls++; // for stat tracking

    int midPoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = arr[midPoint];
    bool done = false;
    // move low or high indexes until they encounter an num that is greater than or less than pivot. 
        // then (1) swap, (2) set index values for next loop
    while (!done)
    {
        // low index, high index. move each one by one.
        while (arr[lowIndex] < pivot)
        {
            lowIndex++;
            incrementComparisonCount();
        }
        while (arr[highIndex] > pivot)
        {
            highIndex--;
            incrementComparisonCount();
        }

        // if low index >= high index, iterated through whole list
        if (lowIndex >= highIndex)  done = true;
        else 
        {
            //swap logic
            int temp = arr[lowIndex];
            arr[lowIndex] = arr[highIndex];
            arr[highIndex] = temp;

            // adjust indexes
            lowIndex++;
            highIndex--;

            incrementSwapCount();
        }
    }

    return highIndex;
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
    std::cout << '\n' << "Quick Sort Calls: " << quickSortCalls;
    std::cout << '\n' << "Partition Calls: " << partitionCalls;
}

void resetSortStats()
{
    swapCount = 0;
    comparisonCount = 0;
    quickSortCalls = 0;
    partitionCalls = 0;
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
