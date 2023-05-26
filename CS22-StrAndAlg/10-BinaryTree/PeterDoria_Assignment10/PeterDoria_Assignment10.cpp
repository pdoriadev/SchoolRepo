/******************************************************************************************************************************************************
                                                      CS22 Data Structures and Algorithms
                                                           Professor Karen Thurston
Peter Doria
Section 33968
Assignment 10

******************************************************************************************************************************************************
                                                                Instructions
******************************************************************************************************************************************************
Design and code a binary search tree to 
    1. store words from a file
    2. store the number of times each word appears in the file

Use this text file Download text file of over seven thousand words created from the United States Constitution found on this website: 
    National Constitution CenterLinks to an external site.

The file has already been modified to remove all punctuation with one word on each line.If you are ambitious and want to earn 
    3 points of extra credit, you can code a function to create the word list from the original text fileDownload original text file

You will read each word in the file and place it in the binary search tree in alphabetical order.
    Each node in the tree shall contain the word and the count of the number of times it appears in the text file.
    Therefore, each node in the tree will need to contain the word, a count value, and links to the leftand right child nodes.

Ignore case (treat all upper and lower case values the same). Count numbersand roman numerals as words. 
    Numbers should be considered to be less in value than all letters in the alphabet.So any word starting with 
    '0' through '9' should be considered less than any word beginning with 'A' or greater.

Once you have read the whole file and stored each word in the binary search tree, traverse the tree in order and display 
    each word on the screen(in alphabetical order) along with the number of times it appears in the file.

Rubric:

    Read the input file(word list) : 1 pt.
        Create a function to insert a node into a binary tree : 4 pts.
        Create a function to search a binary tree : 4 pts.
        Create a function to allow a user to search the tree for a word by typing the word, and then display the number of times the word appears : 1 pt.
        Create a function to do an inorder traversal of the binary treeand display each word with the number of times it appears : 2 pts.
        Extra credit : Add a function to process the original input file to create the word list file : 3 pts.
        What to submit :
    Your source code file or files zipped together and named <firstName><lastName>_Assignment10.cpp or <firstName><lastName>_Assignment10.zip.

******************************************************************************************************************************************************/
// Libraries for program
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <unordered_set>
//Libraries for asserts
#include <assert.h>
#include <sstream>

static const std::unordered_set<char> validChars
{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

struct treeNode
{
    std::string word;
    int count = 0;
    treeNode* left;
    treeNode* right;
    treeNode(const std::string _word)
    {
        word = _word;
        count = 1;
        left = NULL;
        right = NULL;
    }
    treeNode(const std::string _word, treeNode* _left, treeNode* _right)
    {
        word = _word;
        left = _left;
        right = _right;
        count = 1;
    }
};

/********************************************************************
    Info on whether a value exists in a BST.
        If exists, 
            found = true 
            foundOrPreviousNode caches the found node. 
        If does not exists
            found = false
            foundOrPreviousNode caches the node previous to where
                we were last looking. 
********************************************************************/
struct foundStatus
{
    bool found;
    treeNode* foundOrPreviousNode;
    foundStatus(bool isFound, treeNode * _foundOrPreviousNode)
    {
        found = isFound;
        foundOrPreviousNode = _foundOrPreviousNode;
    }
};


treeNode * addWordToBST(treeNode* node, std::string word);
foundStatus searchForNodeWithValue(treeNode* node, std::string word);
treeNode* insertValueIntoBST(foundStatus status, std::string word);
void userSearchForWord(treeNode * node);
bool userWantsTo();
bool isValidWord(std::string input);
bool wordHasAnyValidLetters(std::string word);

int invalidCharsCount = 0;
int main()
{
    std::ifstream inputFile("USConstitution.txt");
    assert((("File not open."), inputFile.is_open()));
    std::ofstream outputFile("MatchingDocument.txt");
    assert(("Output file failed to open.", inputFile.is_open()));
    treeNode* root = new treeNode("");
    std::string word;

    while (std::getline(inputFile, word, ' '))
    {
        if (!wordHasAnyValidLetters(word))
        {
            continue;
        }

        treeNode* returnedNode = addWordToBST(root, word);
        if (returnedNode == NULL)
        {
            std::stringstream message;
            message << "Failed to add " << word << " to BST. ";
            assert((message, false));
        }

        outputFile << returnedNode->word << '\n';
    }
    outputFile.close();
    inputFile.close();
    std::cout << "Do you want to search for a word? " ;
    while (userWantsTo())
    {
        userSearchForWord(root);
        std::cout << "Want to search for another word? ";
    }
    std::cout << "User search time completed." << '\n';
    
    std::cout << std::endl
        << "=======================================" << '\n'
        << "        Output Tree In Order" << '\n'
        << "=======================================" << '\n';
    outputTreeContentsInOrder(root);

}


/*******************************************************************
    Main control function for adding new words into BST.
********************************************************************/
treeNode * addWordToBST(treeNode* node, std::string word)
{
    std::string additionalWord = "";           
    for (int i = 0; i < word.length(); )
    {
        if (validChars.count(std::tolower(word[i])) == 0)
        {
            word.erase(i, 1);
            invalidCharsCount++;
            continue;
        }

        if (i == 0 && std::isupper(word[i]))
        {
            word[i] = std::tolower(word[i]);
        }
        else if (std::isupper(word[i]))
        {
            for (int j = i; j < word.length(); j++)
            {
                additionalWord.push_back(word[j]);
            }
            word.erase(i);
            continue;
        }

        i++;
    }

    if (word.length() > 0)
    {

        if (node->word == "")
        {
            node->word = word;
            return node;
        }

        foundStatus status = searchForNodeWithValue(node, word);
        treeNode * wordNode = insertValueIntoBST(status, word);
        if (additionalWord.length() == 0)
        {
            return wordNode;
        }

        return addWordToBST(node, additionalWord);
    }

    assert(("Didn't think execution would get here. Missed a case when writing function", false));
    return NULL;
}

/********************************************************************
    Searches node with particular value in BST. 
    Returns different foundStatus depending on if the value was 
        found and where it was/wasn't found.
********************************************************************/
foundStatus searchForNodeWithValue(treeNode* node, std::string word)
{
    assert(("Passed in NULL pointer", node != NULL));
    assert(("Word has no length", word.length() > 0));

    if (word == node->word)
    {
        return foundStatus(true, node);
    }
    if (word < node->word)
    {
        if (node->left)
        {
            return searchForNodeWithValue(node->left, word);
        }

        return foundStatus(false, node);
    }
    if (word > node->word)
    {
        if (node->right)
        {
            return searchForNodeWithValue(node->right, word);
        }

        return foundStatus(false, node);
    }

    assert(("Missed a case when looking for a node value", false));
    return foundStatus(false, NULL);
}

/********************************************************************
    Inserts values into BST. If value is not in BST, creates 
        a new node for the value. If value is already in BST,
        iterates the count in that value's node. 
********************************************************************/
treeNode* insertValueIntoBST(foundStatus status, std::string word)
{
    if (status.found)
    {
        status.foundOrPreviousNode->count++;
        return status.foundOrPreviousNode;
    }
    if (status.found == false)
    {
        if (status.foundOrPreviousNode == NULL)
        {
            return new treeNode(word);
        }
        if (word < status.foundOrPreviousNode->word)
        {
            status.foundOrPreviousNode->left = new treeNode(word);
            return status.foundOrPreviousNode->left;
        }
        if (word > status.foundOrPreviousNode->word)
        {
            status.foundOrPreviousNode->right = new treeNode(word);
            return status.foundOrPreviousNode->right;
        }
    }
}

/********************************************************************
    Asks the user to type in a word they would like to search for
        from the document. 
    Checks if user's search word is valid.
    Searches for user's search word in document. 
    Outputs result of search. 
********************************************************************/
void userSearchForWord(treeNode * node)
{    
    std::cout << "Type in a word you would like to search for: ";
    std::string searchWord = "";
    std::cin >> searchWord;
    while (!isValidWord(searchWord))
    {
        std::cout 
            << "'" <<  searchWord << "'"
            << " is not valid search word. Please type in a word made of only letters. No spaces, punctuation, or special characters." 
            << '\n' << "New word: ";

        std::cin >> searchWord;
    }
        
    foundStatus status = searchForNodeWithValue(node, searchWord);
    if (status.found)
    {
        std::cout << "Found " << searchWord << " " << status.foundOrPreviousNode->count << " times!" << '\n';
    }
    else
    {
        std::cout << "Did not find" << " '" << searchWord << "'" << " in document. " << '\n';
    }
}

/******************************************************************** 
    Asks the user to input confirmation if they want to do something. 
        Returns true if they want to. 
        Returns false if they don't want to.
********************************************************************/
bool userWantsTo()
{
    std::cout << " Input 'y' for yes. Input 'n' for no: ";
    char yesOrNoInput;
    std::cin >> yesOrNoInput;
    bool validInput = yesOrNoInput == 'y' || yesOrNoInput == 'n';
    while (!validInput)
    {
        std::cout << "'" << yesOrNoInput << "'" <<  " is not valid input. Please type in 'y' for yes or 'n' for no: ";
        std::cin >> yesOrNoInput;
        validInput = yesOrNoInput == 'y' || yesOrNoInput == 'n';
    }
    if (yesOrNoInput == 'y')
        return true;
    return false;
}

/********************************************************************
    Checks if given string has all valid symbols.
        Returns false if an invalid symbol is found.
        Returns true if there are no invalid symbols.
********************************************************************/
bool isValidWord(std::string word)
{
    for (int i = 0; i < word.length();i++)
    {
        if (validChars.count(word[i]) == 0 || validChars.count(std::tolower(word[0])) == 0)
        {
            return false;
        }
    }

    return true;
}

/********************************************************************
    Returns true if the string has any valid symbols.
    Returns false if no valid symbols are found. 
********************************************************************/
bool wordHasAnyValidLetters(std::string word)
{
    for (int i = 0; i < word.length();i++)
    {
        if (validChars.count(word[i]) > 0 || validChars.count(std::tolower(word[0])) > 0)
        {
            return true;
        }
    }

    return false;
    
}


void outputTreeContentsInOrder(treeNode* node)
{
    assert(("Node passed to Ouput Tree is NULL", node != NULL));
    if (node->left)
        outputTreeContentsInOrder(node->left);

    std::cout
        << "Location: " << node
        << ", Data : " << node->word << '\n';

    if (node->right)
        outputTreeContentsInOrder(node->right);
}