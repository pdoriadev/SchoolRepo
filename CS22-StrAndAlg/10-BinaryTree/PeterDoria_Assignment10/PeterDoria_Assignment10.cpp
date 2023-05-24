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
#include <iostream>
#include <ostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <unordered_set>

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
    treeNode(const std::string _word, treeNode * _left, treeNode * _right)
    {
        word = _word;
        left = _left;
        right = _right;
        count = 1;
    }
};

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

foundStatus searchForNodeWithValue(treeNode* node, std::string word);
treeNode* searchAndInsertValueInBST(treeNode* node, std::string word);
bool userSearchForWord(treeNode * node);
bool isValidInput(std::string input);

int main()
{
    std::ifstream file("USConstitution.txt");
    assert((("File not open."), file.is_open()));
    treeNode* root = NULL;
    std::string word;
    while (std::getline(file, word, ' '))
    {
        for (int i = 0; i < word.length(); )
        {
            if (validChars.count(std::tolower(word[i])) == 0)
            {
                word.erase(i, 1);
                continue;
            }
          
            if (i == 0 && std::isupper(word[i]))
            {
                word[i] = std::tolower(word[i]);
            }

            i++;
        }

        foundStatus status = searchForNodeWithValue(root, word);
    }

    userSearchForWord(root);
   
}

foundStatus searchForNodeWithValue(treeNode* node, std::string word)
{
    if (node == NULL)
    {
        return foundStatus(false, NULL);
    }

    assert(("Word has no length", word.length() > 0));

    if (word == node->word)
    {
        return foundStatus(true, node);
    }
    if (word < node->word)
    {
        if (node->left)
        {
            return searchForNodeWithValue(node->right, word);
        }

        return foundStatus(false, node);
    }
    if (word > node->word)
    {
        if (node->right)
        {
            return searchForNodeWithValue(node->left, word);
        }

        return foundStatus(false, node);
    }

    assert(("Missed a case when looking for a node value", true));
    return foundStatus(false, NULL);
}

treeNode* InsertValueIntoBST(foundStatus status, std::string word)
{
    if (status.found)
    {
        status.foundOrPreviousNode->count++;
        return status.foundOrPreviousNode;
    }
    if (status.found == false)
    {
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

bool userSearchForWord(treeNode * node)
{
    std::cout << "Do you want to search for a word? Input 'y' for yes. Input 'n' for no." << '\n';
    char yesOrNoInput;
    std::cin >> yesOrNoInput;
    bool validInput = yesOrNoInput == 'y' || yesOrNoInput == 'n';
    while (!validInput)
    {
        std::cout << yesOrNoInput << " is not valid input. Please type in 'y' for yes or 'n' for no." << '\n';
    }
    bool want = yesOrNoInput == 'y' ? true : false;
    while (want)
    {
        std::cout << "Type in a word you would like to search for : ";
        std::string searchWord; 
        while (!isValidInput(searchWord))
        {
            std::cout << searchWord << " is not valid search word. Please type in a word made of only letters. No spaces, punctuation, or special characters." << '\n';
            std::cin >> searchWord;
        }
        
        foundStatus status = searchForNodeWithValue(node, searchWord);
        if (status.found)
        {
            std::cout << "Found " << searchWord << " " << status.foundOrPreviousNode->count << " times!" << '\n';
        }
        else
        {
            std::cout << "Did not find word in document. Would you like to search for another word?" << '\n';
        }
    }

    std::cout << "User search time completed." << '\n';

    // want to search , return true
    // DONT want to search, return false
}

bool isValidInput(std::string input)
{
    std::string capitalInput = input;
    capitalInput[0] = std::toupper(capitalInput[0]);
    for (int i = 0; i < input.length();)
    {
        if (validChars.count(input[i]) == 0 || validChars.count(input[0]) == 0)
        {
            return false;
        }
    }

    return true;
}