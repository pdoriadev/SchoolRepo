/*
STUDENT NAME: Peter Doria                            CS-22 Data Structures and Algorithms
SEMESTER: Spring 2023                                        PROFESSOR THURSTON
SECTION: 33968
ASSIGNMENT #: 5
-------------------------------------------------------------------------------------------
Instructions
-------------------------------------------------------------------------------------------
1) Read the census data file (LinkedListNode.csv Download LinkedListNode.csv)  (used in a prior assignment) and store each state's data (name and other fields too) as a struct in a singly linked list.
     THIS IS ALREADY DONE FOR YOU AND STORES EACH NEW NODE AT THE HEAD OF THE LIST RATHER THAN THE TAIL. AFTER READING THE
     COMPLETE FILE THE HEAD WILL POINT TO THE LAST RECORD IN THE FILE. (0 pts.)

2) Write the state name, the memory address of the current node containing that state, and the memory address of the "next" node, 
    to a line in a text output file named CensusNodes.txt (separate each of these three values by a comma). The last line you write
    at this point in the program will be "End of Original Node List". THE DISPLAY FUNCTION CAN BE USED TO CREATE A FUNCTION TO WRITE 
    THIS DATA. COPY THIS FUNCTION AND CREATE A NEW FUNCTION NAMED "writeList" TO WRITE THE DATA TO THE FILE. (1 pt.)

3) Once you've read the file with the data and created the linked list, prompt the user to enter a single letter of the alphabet and display the states in the linked list beginning 
    with that letter. Restrict the choices to valid letters which you should store in a variable (such as an array of characters or a string) as you read in the data.
    COPY THE displayList FUNCTION TO A NEW FUNCTION NAMED displayPartialList (1 pt.)

4) Ask the user to confirm their wish to remove the states from the linked list. Write a function named deleteNode to perform the node deletion. (3 pts.)

5) Write the state name(s) and node addresses of each remaining node in the linked list to its own line in the same output text file as the original addresses (CensusNodes.txt).  
    The last line you write in this file should be "End of Updated Node List". (1 pt.)

Here is an example of how the CensusNodes.txt file should be formatted (your memory addresses will likely be different). Notice how the states beginning with the letter 'D' have
    been removed from the list and the pointer to the next node points to the state beginning with the letter 'F'. (Don't print the lines beginning with "..." which is just
    explanatory text in the example below.) Depending on whether you added new nodes to the head or the tail of the linked list, your states might be in reverse alphabetical 
    order, which is OK:

STATE, CURRENT NODE ADDRESS, NEXT NODE ADDRESS
... (other states stored before "California" in the linked list)
California, 0x8e7288, 0x8e72f8
Colorado, 0x8e72f8, 0x8e7368
Connecticut, 0x8e7368, 0x8e73d8
Delaware, 0x8e73d8, 0x8e7468
District of Columbia, 0x8e7468, 0x8e7500
Florida, 0x8e7500, 0x8e7570
... (other states after "Florida" stored in linked list)
End of Original Node List

UPDATED NODE LIST
... (other states stored before "California" in the linked list)
California, 0x8e7288, 0x8e72f8
Colorado, 0x8e72f8, 0x8e7368
Connecticut, 0x8e7368, 0x8e73d8
Florida, 0x8e73d8, 0x8e7468
... (other states after "Florida" stored in linked list)
END OF UPDATED NODE LIST

6) Run your program twice removing the same states from the original list (first rename the first CensusNodes.txt file to CensusNodes.sav;
    do this in Windows, not in your program) and compare the new output file, CensusNodes.txt to CensusNodes.sav and answer the following questions:

(7) Are the node addresses different or the same between the two different runs of the program?
If so, how do you explain why they are the same or different?
Are the node addresses in the linked lists adjacent to each other in memory in each of the files or not?
Why would the addresses be adjacent if they are, or why would they not be adjacent if they are not?
Write your answers in a text file named CensusNodesAnalysis.txt (5 pts.)

Zip together your source code file(s) (main.cpp plus any header or external .cpp files) and your three output files (CensusNodes.sav, CensusNodes.txt, and CensusNodesAnalysis.txt).

Submit the .zip file named <FirstName><LastName>Assignment5.zip. (Don't include the '<' and '>' characters in the file name and don't include any other files such as CodeBlock project files, executable or object files, or extra directories) (1 pt.)


*/

// Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <unordered_map>


#pragma region CLASSES AND STRUCTS
/************************************************************
 *                        CensusRecord                      *
 * Description                                                *
        Contains Census data for a state in the U.S.
 ************************************************************/
struct CensusRecord
{
    std::string state = "state";
    int totalPop = 0;
    int adultPop = 0;
    double perc = 0.0f; // percentage of total population that are adults
    CensusRecord() { } // default constructor
};

/************************************************************
 *                        LinkedListNode                      *
 * Description                                                *
        Node meant to be used in a Linked List.
        Contains a data value.
        Contains a pointer to the next node in a LinkedList.
 ************************************************************/
struct LinkedListNode
{
    CensusRecord record;
    LinkedListNode* next;
    LinkedListNode(CensusRecord _record, LinkedListNode* _next)
    {
        record = _record;
        next = _next;
    }
};

/************************************************************
Stores collection of letters that are at the beginning of
    any given state in our census records.
 ************************************************************/
std::unordered_map<char, int> stateLetters;

/************************************************************
 *                        LinkedList                      *
 *  Maintains a pointer to the first LinkedListNode in the LinkedList.
 * Tracks the number of nodes in the linkedlist.
 * Functionality for adding LinkedListNodes at different points in the LinkedList.
   Functionality for removing nodes from LinkedList.
 *                                                          *
 ************************************************************/
class LinkedList // singly linked list class
{
    LinkedListNode* head;
    int totalNodes = 0;

    /************************************************************

       Call every time a node is added to the linkedlist.
       Iterates value tracking total nodes.
       Updates keys and values in stateLetters unordered_map
    ************************************************************/
    void nodeAdded(char startLetter)
    {
        if (stateLetters.count(startLetter) == 0)
            stateLetters[startLetter] = 1;
        else
        {
            stateLetters.at(startLetter) += 1;
        }
        totalNodes++;
    }
    /************************************************************
        Call every time a node is removed from the linkedlist.
        Decreases value tracking total nodes by one.
        Updates keys and values in stateLetters unordered_map.
            If a key's count in the LinkedList drops to 0, then
            its associated key,value pair in the unordered_map
            is removed.
    ************************************************************/
    void nodeRemoved(char startLetter)
    {
        if (stateLetters.count(startLetter) == 0)
            std::cout << "\nSHOULD NOT HAPPEN";
        else
        {
            stateLetters.at(startLetter) -= 1;
            if (stateLetters[startLetter] == 0)
            {
                stateLetters.erase(startLetter);
            }
        }
        totalNodes--;
    }

public:
    LinkedList(LinkedListNode* _head)
    {
        head = _head;
        nodeAdded(head->record.state[0]);
    }
    LinkedList() {}

    LinkedListNode* getHead() { return head; }

    int getTotalNodes() { return totalNodes; }

    /************************************************************
    Returns first node in list who's "state" starts with the
        given letter.
    Returns NULL if no node's "state" starts with the given letter.
    Optional LinkedListNode param for where to start the search
        in the linked list. Defaults to head if no param provided.
************************************************************/
    LinkedListNode* findNodeThatStartsWithLetter(char letter, LinkedListNode* startSearchNode)
    {
        if (startSearchNode == NULL)
            startSearchNode = head;
        LinkedListNode* temp = startSearchNode;

        while (temp != NULL)
        {
            if (temp->record.state[0] == letter)
                break;
            temp = temp->next;
        }

        return temp;
    }

    /************************************************************
    preAppend the given already initialized node
************************************************************/
    void prependExistingNode(LinkedListNode* node)
    {
        (*node).next = head;
        head = node;

        nodeAdded(head->record.state[0]);
    }

    /************************************************************
    create a new node with the given record. PreAppend it to the list
************************************************************/
    void prependNewNode(CensusRecord record)
    {
        head = new LinkedListNode(record, head);

        nodeAdded(head->record.state[0]);
    }
    /************************************************************
    append the given already initialized node to the end of the LinkedList
************************************************************/
    void append(LinkedListNode* node)
    {
        if (head == NULL)
        {
            head = node;
            nodeAdded(head->record.state[0]);
            return;
        }

        LinkedListNode* temp1 = head;
        LinkedListNode* temp2 = head->next;
        while (temp2 != NULL)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp2 = node;

        nodeAdded(node->record.state[0]);
    }

    /************************************************************
insert a given already initialized node after a specific node in the LinkedList
************************************************************/
    void insertAfter(LinkedListNode* nodeToInsertAfter, LinkedListNode* newNode)
    {
        if (head == NULL)
        {
            std::cout << '\n' << "Node to insert after does not exist in list. ";
            return;
        }

        LinkedListNode* temp1 = head;
        while (temp1 != nodeToInsertAfter)
        {
            temp1 = temp1->next;
        }
        if (temp1 == NULL)
        {
            std::cout << '\n' << "Node to insert after does not exist in list. ";
            return;
        }
        // like laying railroad tracks backwards
        LinkedListNode* temp2 = temp1->next; // cache variable for where newNode is going to point to
        newNode->next = temp2; // newNode's new pointer value is nodeToInsertAfter's previous
        temp2->next = newNode;
        nodeAdded(newNode->record.state[0]);
    }

    /************************************************************
remove a node from linked list. fix pointers before and after it. delete the node.
returns node at the deleted Node's old position
    If deleteNode() return null, either (a) the given node does not exist in the list
    or (b) there are 0 nodes left in the list after deletion
************************************************************/
    LinkedListNode* deleteNode(LinkedListNode* node)
    {
        LinkedListNode* nodeAtDeletedNodesOldPosition = NULL;
        char letter = node->record.state[0]; // caching letter before deleting node it is associated with. Need for nodeRemoved(char)

        if (totalNodes == 0)
        {
            std::cout << '\n' << "Node does not exist in list";
            return NULL;
        }

        if (node == head)
        {
            LinkedListNode* temp1 = head; // cache current head
            head = (*head).next; // assign node after current head as the new head
            nodeAtDeletedNodesOldPosition = head;
            delete temp1; // delete old head
        }
        else
        {
            LinkedListNode* temp1 = head;
            LinkedListNode* temp2 = head->next;
            while (temp2 != NULL)
            {
                if (temp2 == node)
                {
                    nodeAtDeletedNodesOldPosition = temp2->next;
                    break;
                }
                else
                {
                    temp1 = temp2;
                    temp2 = (*temp2).next;
                }
            }
            if (temp2 == NULL)
            {
                std::cout << '\n' << "Node does not exist in list";
                return NULL;
            }
            else // temp2 == node
            {
                // swap functionality. 
                temp1->next = temp2->next;
                delete temp2;
            }
        }

        nodeRemoved(letter);
        return nodeAtDeletedNodesOldPosition;
    }

    /************************************************************
    Uses the deleteNode() function to delete all nodes in the
    LinkedList with the given letter
************************************************************/
    void deleteAllNodesWithGivenLetter(char letter)
    {
        // delete all nodes that start with letterInput
        LinkedListNode* temp = findNodeThatStartsWithLetter(letter, head);
        while (temp != NULL)
        {
            LinkedListNode* nodeToStartSearchFrom = deleteNode(temp);
            if (nodeToStartSearchFrom == NULL)
                break;
            temp = findNodeThatStartsWithLetter(letter, nodeToStartSearchFrom);
        }
    }
};
#pragma endregion

// METHODS
LinkedList createLinkedListFromCensusFile(std::ifstream& file );
int size(LinkedListNode * node);
void displayList(LinkedListNode * node);
void writeList(LinkedListNode* head, std::ofstream& file, std::string finalLine);
void displayPartialList(LinkedListNode * node, char letter);
bool isGoodConfirmationInput(char confirmationInput);

int main()
{   
    std::ifstream censusFile("CensusData.csv");
    LinkedList censusList = createLinkedListFromCensusFile(censusFile);

    std::cout << std::endl << "The contents of the list are: ";
    displayList(censusList.getHead());

    std::cout << std::endl << "The number of items in the list is: "
        << censusList.getTotalNodes();

    std::ofstream outputFile("CensusNodes.txt");
    writeList(censusList.getHead(), outputFile, "End of Original List");

    unsigned char letterInput;
    std::cout << "\n\nEnter a single letter of the alphabet to display all states with that given letter: ";
    std::cin >> letterInput;
    while (stateLetters.count(letterInput) == 0 && stateLetters.count(static_cast<unsigned char>(std::toupper(letterInput))) == 0)
    {
        std::cout << "\n No state starts with that letter. Try typing in another letter: ";
        std::cin >> letterInput;
    }
    // makes sure the letterInput is equal to its upper case variant (i.e. 'A' vs. 'a')
    letterInput = static_cast<unsigned char>(std::toupper(letterInput));
    
    displayPartialList(censusList.getHead() , letterInput);

    unsigned char confirmationInput;
    std::cout << "\n Are you sure you want to delete these nodes from the Linked List? Please confirm by entering y (or Y) or n (or N): ";
    std::cin >> confirmationInput;
    while (!isGoodConfirmationInput(confirmationInput))
    {
        std::cout << "Invalid input. Please confirm by entering y(or Y) or n(or N) : ";
        std::cin >> confirmationInput;
    }
    if (confirmationInput == 'y' || confirmationInput == 'Y')
    {
        censusList.deleteAllNodesWithGivenLetter(letterInput);
    }

    outputFile.open("CensusNodes.txt", std::ios::app);
    writeList(censusList.getHead(), outputFile, "End of Updated Node List");
        
    return 0;
}

/************************************************************
Reads in data from a census data file. Records data into a 
CensusRecord struct. Creates a new LinkedListNode for each
new CensusRecord.
 ************************************************************/
LinkedList createLinkedListFromCensusFile(std::ifstream& file)
{
    if (!file)
    {
        std::cout << '\n' << "file failed to open";
        return NULL;
    }

    LinkedList censusList;
    while (!(file).eof())
    {
        std::string fileData;
        CensusRecord record;

        std::getline((file), record.state, ',');
        std::getline((file), fileData, ',');
        record.totalPop = std::stoi(fileData);
        std::getline((file), fileData, ',');
        record.adultPop = std::stoi(fileData);
        std::getline((file), fileData, '\n');
        record.perc = std::stoi(fileData);

        censusList.prependNewNode(record);

        if ((file).eof())
            break;
    }

    return censusList;
}

/************************************************************
Computes number of nodes in a linked list
 ************************************************************/
int size(LinkedListNode * node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + size(node->next);
}

/************************************************************
Prints data for every node in the list
Displays ptr address of node, node->next, and the state
    who's data the node stores.
 ************************************************************/
void displayList(LinkedListNode * node)
{
    if (node == NULL)
    {
        std::cout << '\n' << "Node ptr is null";
        return;
    }

    std::cout << '\n'
        << node->record.state << ", "
        << node << ", "
        << node->next;

    if (node->next != NULL)
        displayList(node->next);

}

/************************************************************
Writes LinkedList data to a file.
Creates new file if writeFile is null. 
Writes a line at the end of the file provided by the user
Flushes and Closes file once writing is complete
 ************************************************************/
void writeList(LinkedListNode * head, std::ofstream& writeFile, std::string finalLine)
{
    LinkedListNode* temp = head;
    bool first = true;
    while (temp != NULL)
    {
        if (first)
        {
            writeFile << temp->record.state << ", "
                << temp << ", "
                << temp->next;
            temp = temp->next;
        
            first = false;
        }
        else
        {
            writeFile << std::endl << temp->record.state << ", "
                << temp << ", "
                << temp->next;
            temp = temp->next;
        }

    }

    writeFile << std::endl << finalLine << '\n' << std::endl;
    writeFile.close();
}

/************************************************************
Prints data for every node in the list that start with the 
    given letter.
Displays ptr address of node, node->next, and the state
    who's data the node stores.
 ************************************************************/
void displayPartialList(LinkedListNode * node, char letter)
{
    if (node == NULL)
        return;

    if (node->record.state[0] == letter)
    {
        std::cout << '\n'
            << "Node's state: " << node->record.state << ", "
            << "Node Address: " << node << ", "
            << "Next Node: " << node->next;;
            
    }

    if (node->next != NULL)
        displayPartialList(node->next, letter);
}

/************************************************************
Returns a bool based on whether the char is equivalent to a
valid "yes" or "no" input by the user
 ************************************************************/
bool isGoodConfirmationInput(char confirmationInput)
{
    if (confirmationInput == 'y'
        || confirmationInput == 'Y'
        || confirmationInput == 'n'
        || confirmationInput == 'N')
        return true;
    else
        return false;
}