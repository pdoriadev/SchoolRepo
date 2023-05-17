// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>

enum Relation {root, parent, left, right};
static const char* enum_str[] = { "Root", "Parent", "Left", "Right"};

struct treeNode
{
    int data;
    treeNode* parent;
    treeNode* left;
    treeNode* right;
    treeNode(const int _data)
    {
        data = _data;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    treeNode(const int _data, treeNode* _parent)
    {
        data = _data;
        parent = _parent;
        left = NULL;
        right = NULL;
    }
    treeNode(const int _data, treeNode * _parent, treeNode * _left, treeNode* _right)
    {
        data = _data;
        parent = _parent;
        left = _left; 
        right = _right;
    }
};

treeNode* MakeTree(int * arr, int arrSize);
treeNode* AddNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode);
void outputTreeContents(treeNode* node, Relation relation);

int main()
{
    int sortedArray[5] = { 0, 1, 2, 3, 4 };
    int unSortedArray[5] = { 1, 0, 3, 4, 2 };

    treeNode* sortedRoot = MakeTree(sortedArray, 5);
    treeNode* unsortedRoot = MakeTree(unSortedArray, 5);

    outputTreeContents(sortedRoot, Relation(root));
    outputTreeContents(unsortedRoot, Relation(root));
}

/*******************************
    Constructs tree from a given array.
    Returns tree root node. 
*********************************/
treeNode* MakeTree(int * arr, int sizeOfArr)
{
    treeNode* tree = AddNewNodeToTree(arr, sizeOfArr, 0, NULL);
    return tree;
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
        parentNode = new treeNode(arr[i]);
        AddNewNodeToTree(arr, arrSize, i + 1, parentNode);
        return parentNode;
    }
    else if(parentNode->left == NULL)
    {
        parentNode->left = new treeNode(arr[i], parentNode);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode);
    }
    else if (parentNode->right == NULL)
    {
        parentNode->right = new treeNode(arr[i], parentNode);
        return AddNewNodeToTree(arr, arrSize, i + 1, parentNode->left);
    }
}


/********************************************
    Recursively outputs data on each node in 
        tree to console
*********************************************/
void outputTreeContents(treeNode* node, Relation relation)
{
    std::stringstream nodeStream;
    nodeStream << node;
    std::string message = std::string("treeNode ") + nodeStream.str() + std::string(" with data ") + std::to_string(node->data) + std::string(" passed to output tree contents");
    assert(((message), node != NULL));

    if (relation != Relation(root))
        std::cout << enum_str[relation] << " of " << node->parent << ", " << std::to_string(node->data) << ", " << "Location " << nodeStream.str() << '\n';
    else
        std::cout << enum_str[relation] << ", " << std::to_string(node->data) << ", " << "Location " << nodeStream.str() << '\n';


    if (node->left != NULL)
        outputTreeContents(node->left, Relation(left));
    if (node->right != NULL)
        outputTreeContents(node->right, Relation(right));

}

