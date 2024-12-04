#include "factorial.h"

int recFunc(int num)
{
    if (num >= 10)
        return 10;
    else
        return num * recFunc(num + 1);
}


int puzzle(int start, int end)
{
    if (start > end)
        return start - end;
    else if (start == end)
        return start + end;
    else
        return end * puzzle(start + 1, end - 1);
}

int mysteryOne(int list[], int first, int last)
{
    if (first == last)
        return list[first];
    else
        return list[first] + mysteryOne(list, first + 1, last);
}

int mysteryTwo(int first, int last)
{
    if (first > last)
        return 0;
    else if (first == last)
        return first;
    else
        return first + mysteryTwo(first + 1, last - 1);
}


int mysteryThree(int num)
{
    if (num <= 0)
        return 0;
    else if (num % 2 == 0)
        return num + mysteryThree(num - 1);
    else
        return num * mysteryThree(num - 1);
}

void printDescending(int num)
{
    if (num > 0)
    {
        std::cout << num << " ";
        printDescending(num - 1);
    }
}

int f(int n)
{
    if (n == 1) return 3;

    if (n > 1)
    {
        return f(n - 1) + 1;
    }
}

struct nodeType
{
    int info;
    nodeType* link;
};



int main()
{
    //std::cout << recFunc(10) << std::endl;
    //std::cout << puzzle(5, 10) << std::endl;
    /*std::cout << puzzle(3, 7) << std::endl;*/
    /*int beta[10] = { 2, 5, 8, 9, 13, 15, 18, 20, 23, 25 };   
    std::cout << mysteryOne(beta, 4, 7) << std::endl;
    std::cout << mysteryTwo(6, 10) << std::endl;
    std::cout << mysteryThree(5) << std::endl;
    printDescending(4);*/
    //std::cout << f(1) << '\n';
    std::cout << f(3) << '\n';

    nodeType* head, * p, * q, * newNode;
    newNode = new nodeType;
    newNode->info = 50;

	doFactorial();
}	