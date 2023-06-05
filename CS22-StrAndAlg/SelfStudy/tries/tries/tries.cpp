/*
Demonstrates trie data structure.
- tries contain sequences of linear characters.
    search for linear sequence within trie
    insert new sequences into trie
    remove sequences from trie
    no duplicate sequences.
*/

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
struct trieNode
{
    char letter;
    std::vector< trieNode*> nextNodes;
    bool isEndOfWord;
    trieNode()
    {
        letter = ' ';
        nextNodes.reserve(1);
        isEndOfWord = false;
    }
    trieNode(char _letter, trieNode* _next, bool _isEnd)
    {
        letter = _letter;
        if (_next == NULL)
            nextNodes.reserve(1);
        else nextNodes.push_back(_next);
        isEndOfWord = _isEnd;
    }
};

struct foundStatus
{
    bool found;
    trieNode* foundOrLastMatchingNode;
    foundStatus(bool _found, trieNode* _foundOrLastMatchingNode)
    {
        found = _found;
        foundOrLastMatchingNode = _foundOrLastMatchingNode;
    }
};

foundStatus const trieSearchForLetterConnectedToNode(trieNode* node, char letter);
std::vector<foundStatus> * trieSearchForWord(trieNode* node, std::string wordToSearchFor);
std::vector<foundStatus>* trieInsertWord(trieNode* root, std::string wordToInsert);
trieNode* trieRemoval(trieNode* node);
void outputAllWords(trieNode* node);
void outputWord(trieNode* node, std::string);

int main()
{
    std::vector<std::string> arrOfStrings = { "sap", "sap", "cat", "cattle", "dung", "dungheap", "a", "apple", "appalachia", "appalachian", "cap" };
    trieNode* root = new trieNode();
    for (int i = 0; i < 5; i++)
    {
        trieInsertWord(root, arrOfStrings[i]);
        std::cout << '\n';
        outputAllWords(root);
    }

    std::cout << "========================" << '\n';
    std::cout << "         Trie" << '\n';
    std::cout << "========================" << '\n';

}

foundStatus const trieSearchForLetterConnectedToNode(trieNode* node, char letter)
{

    for (int i = 0; i < node->nextNodes.size(); i++)
    {
        if (letter == node->nextNodes[i]->letter)
        {
            return foundStatus(true, node->nextNodes[i]);
        }
    }

    return foundStatus(false, node);
}

std::vector<foundStatus>* trieSearchForWord(trieNode* node, std::string wordToSearchFor)
{
    std::vector<foundStatus> * sequenceOfNodeFinds = new std::vector<foundStatus>;
    sequenceOfNodeFinds->reserve(wordToSearchFor.size());
    foundStatus lastFind = foundStatus(false, node);
    for (int i = 0; i < wordToSearchFor.size(); i++)
    {
        lastFind = trieSearchForLetterConnectedToNode(node, wordToSearchFor[i]);
        if (lastFind.found == false)
        {
            return sequenceOfNodeFinds;
        }
        sequenceOfNodeFinds->push_back(lastFind);
        node = lastFind.foundOrLastMatchingNode;
    }
    sequenceOfNodeFinds->at(sequenceOfNodeFinds->size() - 1).foundOrLastMatchingNode->isEndOfWord = true;
    return sequenceOfNodeFinds;
}

std::vector<foundStatus> * trieInsertWord(trieNode* root, std::string wordToInsert)
{
    assert(("Root node is null", root != NULL));
    assert(("String is empty", wordToInsert.empty() == NULL));

    std::vector<foundStatus> * finds = trieSearchForWord(root, wordToInsert);
    trieNode* parentToNextInsertedNode;


    if (finds->size() > 0)
    {
        for (int i = 0; i < finds->size(); i++)
        { 
            if (finds->at(i).foundOrLastMatchingNode->letter != wordToInsert[i] && 
                    finds->at(i).found)
            {
                assert(("Last letter in finds does not match expected letter in word to insert", false));
            }
        }

        if (finds->size() == wordToInsert.size())
        {
            return finds;
        }

        parentToNextInsertedNode = finds->at(finds->size() - 1).foundOrLastMatchingNode;
    }
    else
    {
        parentToNextInsertedNode = root;
    }
    
    for (int i = finds->size(); i < wordToInsert.size(); i++)
    {
        bool isEndOfWord = i + 1 == wordToInsert.size();
        parentToNextInsertedNode->nextNodes.push_back(new trieNode(wordToInsert[i], nullptr, isEndOfWord)); 
        
        parentToNextInsertedNode = parentToNextInsertedNode->nextNodes[parentToNextInsertedNode->nextNodes.size() - 1];
        finds->push_back(foundStatus(true, parentToNextInsertedNode));
    }

    return finds;
}

trieNode* trieRemoval(trieNode* node)
{
    return NULL;
}

void outputAllWords(trieNode* node)
{
    std::cout << "Words: " << '\n';
    outputWord(node, "");
    std::cout << '\n';
}

void outputWord(trieNode* node, std::string word)
{
    if (node->letter != ' ')
    {
        word += node->letter;
    }
    for (int i = 0; i < node->nextNodes.size(); i++)
    {
        outputWord(node->nextNodes[i], word);
    }
    if (node->isEndOfWord)
    {
        std::cout << word << '\n';
    }
}