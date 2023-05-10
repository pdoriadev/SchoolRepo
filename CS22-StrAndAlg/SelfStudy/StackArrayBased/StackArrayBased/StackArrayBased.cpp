/*
NAME: Peter Doria
5/2/2023

--------------------
Implements an array-based stack class
- Class has a default allocation size and options for initializing as a bounded vs unbounded stack
- Max Length for stack
- Length for stack
- Allocation Size to track size of dynamic array (alternatively could be implemented using vector. Probably easier)
- Push()
- Pop()
- Peek()
- IsEmpty()
- GetLength()
- Array resize funcionality
-------------------

Example cases for unbounded vs bounded stack for similarly sized arrays
*/

#include <iostream>

struct StackItem
{
    int data;
    StackItem(int newData = 0)
    {
        data = newData;
    }
};


/*
    Requires an initial allocation size upon construction
    Resizing happens automatically if stack length exceeds the size of the array 
        Unbounded: No maxLength check
        Bounded: Additional check if size of array is equal to maxLength. If so, 
            array size cannot be increased.
*/
class ArrayStack
{
private:
    unsigned int maxStackLength;
    unsigned int currentStackLength;
    unsigned int allocationSize; 
    StackItem* arr = new StackItem{};


    /*
        doubles current size of array by default.
            Returns false if a bounded array's max length is equal to current stack length
    */
    bool resize(unsigned int newSize = NULL)
    {

        // Returns false if bounded array is already at max size
        if (maxStackLength != 0 && currentStackLength == maxStackLength)
        {
            std::cout << "\nMax stack length reached at " << currentStackLength << ". "
                << "Cannot resize bounded array stack to size greater than max stack length.";
            return false;
        }

        // Valid new size value checks
        if (newSize == NULL)
        {
            allocationSize *= 2;
        }
        else if (newSize <= currentStackLength)
        {
            allocationSize *= 2;
            std::cout << "\nArray's new size must be larger than current stack length. Changing new size";
        }

        // Bounded Array bounds check for new size
        if (maxStackLength != 0 && allocationSize > maxStackLength)
        {
            allocationSize = maxStackLength;
        }

        StackItem* newArr = new StackItem[static_cast<size_t>(allocationSize)];
        for (int i = 0; i < currentStackLength; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;

        resizes++;

        return true;
    }


public:
    unsigned int resizes = 0;
    
    /*
        default initializes to unbounded array that will "infinitely" resize until out of memory.
    */ 
    ArrayStack(unsigned int maxLength = 0, unsigned int initialSize = 1)
    {
        maxStackLength = maxLength;
        currentStackLength = 0;
        if (initialSize <= 0)
        {
            std::cout << "\nInitial size of array stack must be one or greater. Setting initial size to a default value.";
            initialSize = 1;
        }
        allocationSize = initialSize;
        resize(allocationSize);
    }

    ~ArrayStack()
    {
        delete[] arr;
    }

    StackItem * push(StackItem item)
    {
        if (currentStackLength == allocationSize)
        {
            if (!resize())
                return NULL;
        }

        arr[currentStackLength] = item;
        currentStackLength++;
        return &(arr[currentStackLength]);
    }

    StackItem * pop()
    {
        if (isEmpty()) 
        {
            std::cout << "\nNo items to pop off stack. Stack is empty.";
            return NULL;
        }

        currentStackLength--;
        return &(arr[currentStackLength]);
    }

    StackItem * peek()
    {
        if (isEmpty())
            return NULL;
        return &(arr[currentStackLength - 1]);
    }

    bool isEmpty()
    {
        return currentStackLength == 0;
    }

    unsigned int getLength()
    {
        return currentStackLength;
    }
};



int main()
{
    ArrayStack unboundStack = ArrayStack();
    ArrayStack boundStack = ArrayStack(400, 399);
    
    std::cout << "\n\n --- Unbound Stack Pushing --- ";
    for (int i = 0; i < 400; i++)
    {
        unboundStack.push(StackItem(i));
    }
    std::cout << "\n Unbound Stack Resize Count: " << unboundStack.resizes;

    std::cout << "\n\n--- Bounded Stack Pushing --- ";
    for (int i = 0; i < 400; i++)
    {
        StackItem * hitMax = boundStack.push(StackItem(i));
        if (hitMax == NULL)
            break;
    }
    std::cout << "\n --- Bounded Stack Resize Count: " << boundStack.resizes;

    std::cout << "\n\n --- Unbound Stack Popping --- ";
    while (!unboundStack.isEmpty())
    {
        StackItem* popped = unboundStack.pop();
        std::cout << "\n" << (*popped).data << " at " << popped;
    }
    std::cout << "\n --- Unbound Stack Popped Off --- " << std::endl;
    
    std::cout << "\n\n --- Bound Stack Popping --- ";
    while (!boundStack.isEmpty())
    {
        StackItem* popped = boundStack.pop();
        //std::cout << "\n" << (*popped).data << " at " << popped;
    }
    std::cout << "\n --- Bound Stack Popped Off --- " << std::endl;
}

