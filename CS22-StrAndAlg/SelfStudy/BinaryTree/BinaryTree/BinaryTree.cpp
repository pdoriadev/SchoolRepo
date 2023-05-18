// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>

enum Relation {Root, Parent, Left, Right};
static const char* relation_str[] = { "Root", "Parent", "Left", "Right"};

struct treeNode
{
    int data;
    treeNode* Parent;
    treeNode* Left;
    treeNode* Right;
    int depth;
    treeNode(const int _data)
    {
        data = _data;
        Parent = NULL;
        Left = NULL;
        Right = NULL;
    }
    treeNode(const int _data, treeNode* _parent)
    {
        data = _data;
        Parent = _parent;
        Left = NULL;
        Right = NULL;
    }
    treeNode(const int _data, treeNode * _parent, treeNode * _left, treeNode* _right)
    {
        data = _data;
        Parent = _parent;
        Left = _left; 
        Right = _right;
    }
};


treeNode* MakeGeneralTree(int * arr, int arrSize);
treeNode* AddNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode);
void outputTreeContents(treeNode* node, Relation relation);

int main()
{
    int sortedArray[5] = { 0, 1, 2, 3, 4 };
    int unSortedArray[5] = { 1, 0, 3, 4, 2 };

    treeNode* sortedRoot = MakeGeneralTree(sortedArray, 5);
    treeNode* unsortedRoot = MakeGeneralTree(unSortedArray, 5);

    outputTreeContents(sortedRoot, Relation(Root));
    outputTreeContents(unsortedRoot, Relation(Root));
}

/***************************************
    Constructs tree from a given array.
    Returns tree root node. 
*****************************************/
treeNode* MakeGeneralTree(int * arr, int arrSize)
{
    treeNode* tree = AddNewNodeToTree(arr, arrSize, 0, NULL, false);
    return tree;
}

/************************************************
    Recurively adds nodes to create tree
*************************************************/
treeNode* AddNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode, bool isBSP = false)
{
    if (i >= arrSize)
        return NULL;
    
    // Make BSP tree
    if (isBSP)
    {
        // dynamically change BSP hierarchy as new values are encountered in order to match BSP rules
        // left child is less than parent. right child is greater than parent.
            // all right child's descendents must be greater than the child's parent
            // all left child's descendents must be less than the child's parent
        bool greaterThan = arr[i] > parentNode->data;
        bool equal = arr[i] == parentNode->data;
        if (greaterThan && arr[i] > parentNode->Parent->data)
        {
            return AddNewNodeToTree(arr, arrSize, i, parentNode->Parent, true);
        }
        if (greaterThan &&)


    }

    if (parentNode == NULL)
    {
        parentNode = new treeNode(arr[i]);
        AddNewNodeToTree(arr, arrSize, i + 1, parentNode, false);
        return parentNode;
    }
    else if(parentNode->Left == NULL)
    {
        parentNode->Left = new treeNode(arr[i], parentNode);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode, false);
    }
    else if (parentNode->Right == NULL)
    {
        parentNode->Right = new treeNode(arr[i], parentNode);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left, false);
    }
}

treeNode* TraverseTreeForNode(treeNode * nodeToMatch)
{

}

/*************************************************** 
    Returns node that matches condition
****************************************************/
treeNode* TraverseTreeForValue(int value, bool greaterThanOrEqual, treeNode * node)
{
    if (greaterThanOrEqual)
    {
        if (value < node->Parent->data)
            return TraverseTreeForValue(value, greaterThanOrEqual, node->Parent);

    }
    
     
}


/************************************************
    Recursively outputs data on each node in 
        tree to console
*************************************************/
void outputTreeContents(treeNode* node, Relation relation)
{
    std::stringstream nodeStream;
    nodeStream << node;
    std::string message = std::string("treeNode ") + nodeStream.str() + std::string(" with data ") + std::to_string(node->data) + std::string(" passed to output tree contents");
    assert(((message), node != NULL));

    if (relation != Relation(Root))
        std::cout << relation_str[relation] << " of " << node->Parent << ", " << std::to_string(node->data) << ", " << "Location " << nodeStream.str() << '\n';
    else
        std::cout << relation_str[relation] << ", " << std::to_string(node->data) << ", " << "Location " << nodeStream.str() << '\n';


    if (node->Left != NULL)
        outputTreeContents(node->Left, Relation(Left));
    if (node->Right != NULL)
        outputTreeContents(node->Right, Relation(Right));

}

