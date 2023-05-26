/*
Demonstrates trie data structure.
- tries contain sequences of linear characters.
    search for linear sequence within tree
    insert new sequences into tree
    remove sequences from tree
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
    bool isEndOfWord = false;
    trieNode()
    {
        letter = ' ';
        nextNodes[0] = NULL;
        isEndOfWord = false;
    }
    trieNode(char _letter, trieNode* _next, bool _isEnd)
    {
        letter = _letter;
        nextNodes.push_back(_next);
        isEndOfWord = _isEnd;
    }
    trieNode(char _letter, trieNode* _next, bool _isEnd)
    {
        letter = _letter;
        nextNodes.push_back(_next);
        isEndOfWord = _isEnd;
    }
};

int main()
{
    std::vector<std::string> arrOfStrings = { "sap", "sap", "cat", "cattle", "dung", "dungheap", "a", "apple", "appalachia", "appalachian", "cap" };
    trieNode* root = new trieNode();
    for (int i = 0; i < arrOfStrings.size(); i++)
    {
        trieInsert(root, arrOfStrings[i]);
    }

    std::cout << "========================" << '\n';
    std::cout << "         Trie" << '\n';
    std::cout << "========================" << '\n';

}

trieNode* trieSearch(trieNode* node, std::string wordToSearchFor)
{

}

trieNode* trieInsert(trieNode* node, std::string wordToInsert)
{

}


trieNode* trieRemoval(trieNode* node)
{

}

void outputAllTrieWordsInOrder(trieNode* node)
{
    if (node->letter != ' ')
    {
        while (node->isEndOfWord != true)
        {
            
            std::cout << node->letter;
            

        }
    }
    
    if (node->nextNodes.size() == 0)
    {
        return;
    }


    trieNode* node = node->nextNodes[0];
    int i = 1;
    while (i < root->nextNodes.size())
    {
        if (node->letter < root->nextNodes[i]->letter)
        {
             
        }
        i++;
    }
}

trieNode* getSuccessorNode(trieNode * node)
{
    trieNode* successorNode = node;
    for (int i = 0; i < node->nextNodes.size(); i++)
    {
        if (successorNode == node)
        {
            if (node->nextNodes[i]->letter > successorNode->letter)
            {
                successorNode = node->nextNodes[i];
            }
            continue;
        }

        if(node->nextNodes[i]->letter < successorNode->letter)
        { 
            successorNode = 
        }
    }
    if (successorNode == node)
        return NULL;
    return successorNode;
}