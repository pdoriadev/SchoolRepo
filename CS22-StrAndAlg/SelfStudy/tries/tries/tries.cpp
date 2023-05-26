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

int main()
{
    std::vector<std::string> arrOfStrings = { "sap", "sap", "cat", "cattle", "dung", "dungheap", "a", "apple", "appalachia", "appalachian", "cap" };
    trieNode* root = new trieNode();
    

    std::cout << "========================" << '\n';
    std::cout << "         Trie" << '\n';
    std::cout << "========================" << '\n';

}

foundStatus trieSearchForLetterConnectedToNode(trieNode* node, char letter)
{
    if (letter == node->letter)
    {
        return foundStatus(true, node);
    }

    for (int i = 0; i < node->nextNodes.size(); i++)
    {
        if (letter == node->nextNodes[i]->letter)
        {
            return foundStatus(true, node->nextNodes[i]);
        }
    }

    return foundStatus(false, node);
}

std::vector<foundStatus>& trieSearchForWord(trieNode* node, std::string wordToSearchFor)
{
    std::vector<foundStatus> sequenceOfNodeFinds;
    sequenceOfNodeFinds.reserve(wordToSearchFor.size());
    for (int i = 0; i < wordToSearchFor.size(); i++)
    {
        sequenceOfNodeFinds.push_back(trieSearchForLetterConnectedToNode(node, wordToSearchFor[i]));
        if (sequenceOfNodeFinds[i].found == false)
        {
            return sequenceOfNodeFinds;
        }
    }
    return sequenceOfNodeFinds;
}

trieNode* trieInsertLetter(trieNode* node, char letter)
{

}

std::vector<foundStatus>& trieInsertWord(trieNode* node, std::string wordToInsert)
{
    std::vector<foundStatus> finds = trieSearchForWord(node, wordToInsert);
 
    if (finds.size() == wordToInsert.size())
    {
        return finds;
    }

    if (finds.empty())
    {
        // insert whole word into trie from root
    }

    std::vector<foundStatus> fullWordSequence = finds;
    trieNode* insertionNode = finds[finds.size() - 1].foundOrLastMatchingNode; 
    for (int i = wordToInsert.size() - finds.size() - 1; i < wordToInsert.size(); i++)
    {
        insertionNode->nextNodes.push_back(new trieNode(wordToInsert[i], nullptr, false));
        insertionNode = insertionNode->nextNodes[0];
        finds.push_back(foundStatus(true, insertionNode->nextNodes[0]));
    }

    return fullWordSequence;
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