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
            // all right child's descendents m-ust be greater than the child's parent
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
        parentNode = new treeNode(arr[i], false);
        AddNewNodeToTree(arr, arrSize, i + 1, parentNode, false);
        return parentNode;
    }
    
    if(parentNode->Left == NULL)
    {
        if (parentNode->Parent == NULL)
        {
            parentNode->Left = new treeNode(arr[i], parentNode, false);
            return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left, false);
        }
        parentNode->Left = new treeNode(arr[i], parentNode, parentNode->onRightSideOfTree);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode, false);
    }

    if (parentNode->Right == NULL)
    {
        if (parentNode->Parent == NULL)
        {
            parentNode->Right = new treeNode(arr[i], parentNode, true);
            return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left, false);
        }
        parentNode->Right = new treeNode(arr[i], parentNode, parentNode->onRightSideOfTree);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->Left, false);
    }
}

/*************************************************** 
    Returns node where value is inserted
        i.e. node with data less than value param
        i.e. node with data greater than value param
****************************************************/
treeNode* InsertValueIntoCorrectPositionInTree(int value, treeNode * node)
{
    if (node->Parent == NULL && node == NULL)
    {
        node = new treeNode(value, false);
        return node;
    }

    if (node == NULL)
    {
        std::cout << "No null non-new-root nodes allowed" << '\n';
        return NULL;
    }

    bool greaterThanNode = value > node->data;
    bool equalToNode = value == node->data;

    if (equalToNode && node->Parent)
    {
        treeNode* newNode = new treeNode(value, node->onRightSideOfTree);
        if (node->Left == NULL)
        {
            node->Left = newNode;
            return node->Left;
        }

        if (node->Right == NULL)
        {
            node->Right = newNode;
            return node->Right;
        }

        newNode->Left = node->Left;
        InsertValueIntoCorrectPositionInTree(node->Left->data, node->Parent);
            // TODO --> may need to do recursive call here to find position for node that has been moved, starting from nearby position, either the
                // parent or the node that was just added
        delete node->Left;
        node->Left = newNode;
    }

    if (equalToNode && node->Parent == NULL)
    {
        treeNode* newNode = new treeNode(value, node->onRightSideOfTree);
        if (node->Left == NULL)
        {
            node->Left = newNode;
            node->Left->onRightSideOfTree = false;
            return node->Left;
        }

        if (node->Right == NULL)
        {
            node->Right = newNode;
            node->Right->onRightSideOfTree = true;
            return node->Right;
        }
    }

    if (node->onRightSideOfTree)
    {
        if (greaterThanNode && !equalToNode)
        {
            if (node->Right == NULL)
            {
                node->Right = new treeNode(value, node, node->onRightSideOfTree);
                return node->Right;
            }
            
            return InsertValueIntoCorrectPositionInTree(value, node->Right);
        }

        if (greaterThanNode && equalToNode)
        {
            if (node->Right == NULL)
            {

            }
        }
    }


    if (node->data >= value)
    {
        if (node->onRightSideOfTree)
        {

        }
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

