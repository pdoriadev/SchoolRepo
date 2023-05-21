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
    bool onRightSideOfTree;
    int depth;
    treeNode(const int _data, bool _onRightSideOfTree)
    {
        data = _data;
        Parent = NULL;
        Left = NULL;
        Right = NULL;
        onRightSideOfTree = _onRightSideOfTree;
    }
    treeNode(const int _data, treeNode* _parent, bool _onRightSideOfTree)
    {
        data = _data;
        Parent = _parent;
        Left = NULL;
        Right = NULL;
        onRightSideOfTree = _onRightSideOfTree;
    }
    treeNode(const int _data, treeNode * _parent, treeNode * _left, treeNode* _right, bool _onRightSideOfTree)
    {
        data = _data;
        Parent = _parent;
        Left = _left; 
        Right = _right;
        onRightSideOfTree = _onRightSideOfTree;
    }
};


treeNode* MakeGeneralTree(int * arr, int arrSize);
treeNode* MakeBST(int * arr, int arrSize);
treeNode* TraverseToRoot(treeNode* node);
treeNode* AddNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode);
treeNode* InsertNewValueIntoBST(int value, treeNode* node);
void outputTreeContents(treeNode* node, Relation relation);

int main()
{
    int sortedArray[5] = { 0, 1, 2, 3, 4 };
    int unSortedArray[5] = { 1, 0, 3, 4, 2 };

    treeNode* sortedRoot = MakeBST(sortedArray, 5);
    treeNode* unsortedRoot = MakeBST(unSortedArray, 5);

    outputTreeContents(sortedRoot, Relation(Root));
    outputTreeContents(unsortedRoot, Relation(Root));
}

/***************************************
    Constructs tree from a given array.
    Returns tree root node. 
*****************************************/
treeNode* MakeGeneralTree(int * arr, int arrSize)
{
    treeNode* tree = AddNewNodeToTree(arr, arrSize, 0, NULL);
    return tree;
}

treeNode* MakeBST(int* arr, int arrSize)
{
    treeNode* node = NULL;
    for (int i = 0; i < arrSize; i++)
    {
        if (i == 0)
        {
            node = InsertNewValueIntoBST(arr[i], node);
            continue;
        }
        
        InsertNewValueIntoBST(arr[i], node);
    }
    return TraverseToRoot(node);
}

/************************************************
    Recurively adds nodes to create tree
*************************************************/
treeNode* AddNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode)
{
    if (i >= arrSize)
        return NULL;

    if (parentNode == NULL)
    {
        parentNode = new treeNode(arr[i], false);
        AddNewNodeToTree(arr, arrSize, i + 1, parentNode);
        return parentNode;
    }
    
    if(parentNode->Left == NULL)
    {
        if (parentNode->Parent == NULL)
        {
            parentNode->Left = new treeNode(arr[i], parentNode, false);
            return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left);
        }
        parentNode->Left = new treeNode(arr[i], parentNode, parentNode->onRightSideOfTree);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode);
    }

    if (parentNode->Right == NULL)
    {
        if (parentNode->Parent == NULL)
        {
            parentNode->Right = new treeNode(arr[i], parentNode, true);
            return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left);
        }
        parentNode->Right = new treeNode(arr[i], parentNode, parentNode->onRightSideOfTree);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left);
    }
}

/*************************************************** 
    Returns node where value is inserted
    Compares value to value of node passed into function.
        i.e. node with data less than value param
        i.e. node with data greater than value param
    Passing null into node param creates a disconnected node
        (or new tree depeneding on how you look at it)
****************************************************/
treeNode* InsertNewValueIntoBST(int value, treeNode* node)
{
    if (node == nullptr)
    {
        node = new treeNode(value, false);
        return node;
    }

    bool greaterThanNode = value > node->data;
    bool equalToNode = value == node->data;
    bool isRoot = node->Parent == NULL;


    if (equalToNode)
    {
        if (node->Left == NULL)
        {
            bool rightSide = isRoot ? false : node->onRightSideOfTree;
            node->Left = new treeNode(value, node, rightSide);
            return node->Left;
        }
        if (node->Right == NULL)
        {
            bool rightSide = isRoot ? true : node->onRightSideOfTree;
            node->Right = new treeNode(value, node, rightSide);
            return node->Right;
        }

        bool hasLeft = node->Left->Left;
        bool hasRight = node->Right->Right;
        if (!hasLeft && !hasRight)
        {
            int oldLeftValue = node->Left->data;
            bool rightSide = node->Left->onRightSideOfTree;
            treeNode* newLeft = new treeNode(value, node, node->Left->Left, node->Left->Right, rightSide);
            delete node->Left;
            node->Left = newLeft;
            return InsertNewValueIntoBST(oldLeftValue, node->Left);
        }
        hasLeft = node->Right->Left;
        hasRight = node->Right->Right;
        if (!hasLeft && !hasRight)
        {
            int oldRightValue = node->Right->data;
            bool rightSide = node->Right->onRightSideOfTree;
            treeNode* newRight = new treeNode(value, node, node->Right->Left, node->Right->Right, rightSide);
            delete node->Right;
            node->Right = newRight;
            return InsertNewValueIntoBST(oldRightValue, node->Right);
        }
        
        int oldLeftValue = node->Left->data;
        bool rightSide = node->Left->onRightSideOfTree;
        treeNode* newLeft = new treeNode(value, node, node->Left->Left, node->Left->Right, rightSide);
        delete node->Left;
        node->Left = newLeft;
        return InsertNewValueIntoBST(oldLeftValue, node->Left);              
    }


    if (greaterThanNode == false)
    {
        if (node->Left == NULL)
        {
            bool rightSide = node->Parent == NULL ? true : node->onRightSideOfTree;
            node->Left = new treeNode(value, node, rightSide);
            return node->Left;
        }

        if (value <= node->Left->data)
        {
            int oldLeftValue = node->Left->data;
            bool rightSide = node->Left->onRightSideOfTree;
            treeNode* newLeft = new treeNode(value, node, node->Left->Left, node->Left->Right, rightSide);
            delete node->Left;
            node->Left = newLeft;
            return InsertNewValueIntoBST(oldLeftValue, node->Left);
        }

        return InsertNewValueIntoBST(value, node->Left);
    }

    if (greaterThanNode)
    {
        if (node->Right == NULL)
        {
            bool rightSide = node->Parent == NULL ? true : node->onRightSideOfTree;
            node->Right = new treeNode(value, node, rightSide);
            return node->Right;
        }

        if (value <= node->Right->data)
        {
            int oldRightValue = node->Right->data;
            bool rightSide = node->Right->onRightSideOfTree;
            treeNode * newRight = new treeNode(value, node, node->Right->Left, node->Right->Right, rightSide);
            delete node->Right;
            node->Right = newRight;
            return InsertNewValueIntoBST(oldRightValue, node->Right);
        }
        
        return InsertNewValueIntoBST(value, node->Right);
    }

    // possible later optimization: move nodes instead of deleting them?
}

treeNode* TraverseToRoot(treeNode* node)
{
    while (node->Parent)
    {
        node = node->Parent;
    }
    return node;
}


/************************************************
    Recursively outputs data on each node in 
        tree to console
*************************************************/
void outputTreeContents(treeNode* node, Relation relation)
{
    std::stringstream nodeStream;
    nodeStream << node;
    assert((("Node passed to OutputTreeContents is Null"), node != NULL));

    std::string message = std::string("treeNode ") + nodeStream.str() + std::string(" with data ") + std::to_string(node->data) + std::string(" passed to output tree contents");
    if (relation != Relation(Root))
        std::cout << relation_str[relation] << " of " << node->Parent << ", " << std::to_string(node->data) << ", " << "Location " << nodeStream.str() << '\n';
    else
        std::cout << relation_str[relation] << ", " << std::to_string(node->data) << ", " << "Location " << nodeStream.str() << '\n';

    if (node->Left != NULL)
        outputTreeContents(node->Left, Relation(Left));
    if (node->Right != NULL)
        outputTreeContents(node->Right, Relation(Right));

}

