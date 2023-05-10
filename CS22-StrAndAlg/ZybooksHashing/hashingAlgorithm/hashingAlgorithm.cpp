// hashingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ostream>
#include<fstream>

int doubleHash(int key, int tableSize, int i)
{
    return (key % tableSize + i * (5 - key % 5)) % tableSize;
}

int main()
{
    std::ofstream outputSequence("81asKey");
    for (int i = 0; i < 11; i++)
    {
        outputSequence << doubleHash(81, 11, i);
        if (i < 10)
            outputSequence << ',';
    }
}

