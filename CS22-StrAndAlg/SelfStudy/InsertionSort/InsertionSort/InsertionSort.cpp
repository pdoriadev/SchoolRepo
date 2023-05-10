// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void insertionSort(int arr[], int size);
int main()
{
    int arr[] = { 30, 20, 35, 27, 96, 82, 56, 60, 48, 75, 5, 80 };
   
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i + 1 < size)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    insertionSort(arr, size);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i + 1 < size)
        {
            std::cout << ", ";
        }
    }
    std::cout << '\n';
}

// O(n^2) If array was arranged in descending order. 
// Ω(n) If array is already arranged in ascending order (used alt+234 to type uppercase omega symbol)
void insertionSort(int arr[], int size)
{
    // compare unorted element with sorted elements until found place to sort the element.
    int shiftsAndSwapsMade = 0;
    int swapsMade = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int insertPos = 0;
        for (int j = i + 1; j > -1; j--)
        {
            if (arr[i+1] > arr[j])
            {
                insertPos = j+1;
                break;
            }
        }
        int temp = arr[i+1];
        
        for (int p = i; p >= insertPos; p--) // shifts values over to make room for value at arr[i+1]
        {
            arr[p + 1] = arr[p];
            shiftsAndSwapsMade++;
        }
        arr[insertPos] = temp;
        swapsMade++;
        shiftsAndSwapsMade++;
    }

    std::cout << "\n" << "Swaps Made: " << swapsMade;
    std::cout << '\n' << "Shifts And Swaps Made: " << shiftsAndSwapsMade << std::endl;
    std::cout << '\n';
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
