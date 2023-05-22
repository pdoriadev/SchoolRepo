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
	bool full;
	int depth;
	treeNode(const int _data, bool _onRightSideOfTree)
	{
		data = _data;
		Parent = NULL;
		Left = NULL;
		Right = NULL;
		full = Left && Right;
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


treeNode* makeGeneralTree(int * arr, int arrSize);
treeNode* makeBST(int * arr, int arrSize);
treeNode* traverseToRoot(treeNode* node);
treeNode* addNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode);
treeNode* insertNewValueIntoBST(int value, treeNode* node);
treeNode* balanceBST(treeNode * node);
void outputTreeContents(treeNode* node, Relation relation);

int main()
{
	int sortedArray[5] = { 0, 1, 2, 3, 4 };
	int unSortedArray[5] = { 1, 0, 3, 4, 2 };
	int equalsMixArr[6] = { 3, 3, 3, 4, 3, 2 };

	treeNode* sortedRoot = makeBST(sortedArray, 5);
	treeNode* sortedRootGeneral = makeGeneralTree(sortedArray, 5);

	treeNode* unsortedRoot = makeBST(unSortedArray, 5);
	treeNode* unsortedRootGeneral = makeGeneralTree(unSortedArray, 5);

	treeNode* equalsMixRoot = makeBST(equalsMixArr, 6);
	treeNode* equalsMixRootGeneral = makeGeneralTree(equalsMixArr, 6);

	outputTreeContents(sortedRoot, Relation(Root));
	std::cout << std::endl;
	outputTreeContents(unsortedRoot, Relation(Root));
	std::cout << std::endl;
	outputTreeContents(equalsMixRoot, Relation(Root));
	std::cout << std::endl;
}

/***************************************
	Constructs tree from a given array.
	Returns tree root node. 
*****************************************/
treeNode* makeGeneralTree(int * arr, int arrSize)
{
	treeNode* tree = addNewNodeToTree(arr, arrSize, 0, NULL);
	assert(("must return root"), tree->Parent == NULL);
	return tree;
}

treeNode* makeBST(int* arr, int arrSize)
{
	treeNode* node = NULL;
	for (int i = 0; i < arrSize; i++)
	{
		if (i == 0)
		{
			node = insertNewValueIntoBST(arr[i], node);
			continue;
		}
		
		insertNewValueIntoBST(arr[i], node);
	}
	return node;
}

/************************************************
	Recurively adds nodes to create tree
*************************************************/
treeNode* addNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode)
{
	if (i >= arrSize)
		return NULL;

	if (parentNode == NULL)
	{
		parentNode = new treeNode(arr[i], false);
		addNewNodeToTree(arr, arrSize, i + 1, parentNode);
		return parentNode;
	}

	if(parentNode->Left == NULL)
	{
		if (parentNode->Parent == NULL)
		{
			parentNode->Left = new treeNode(arr[i], parentNode, false);
			return addNewNodeToTree(arr, arrSize, i + 1, parentNode->Left);
		}
		parentNode->Left = new treeNode(arr[i], parentNode, parentNode->onRightSideOfTree);
		return addNewNodeToTree(arr, arrSize, i + 1, parentNode);
	}

	if (parentNode->Right == NULL)
	{
		if (parentNode->Parent == NULL)
		{
			parentNode->Right = new treeNode(arr[i], parentNode, true);
			return addNewNodeToTree(arr, arrSize, i + 1, parentNode->Left);
		}
		parentNode->Right = new treeNode(arr[i], parentNode, parentNode->onRightSideOfTree);
		return addNewNodeToTree(arr, arrSize, i + 1, parentNode->Left);
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
treeNode* insertNewValueIntoBST(int value, treeNode* node)
{
	if (node == nullptr)
	{
		return new treeNode(value, false);
	}

	if (value == node->data)
	{
		if (node->Left == NULL)
		{
			bool rightSide = node->Parent == NULL ? false : node->onRightSideOfTree;
			node->Left = new treeNode(value, node, rightSide);
			return node->Left;
		}

		if (node->Right == NULL)
		{
			bool rightSide = node->Parent == NULL ? true : node->onRightSideOfTree;
			node->Right = new treeNode(value, node, rightSide);
			return node->Right;
		}

		if (!node->Left->full)
		{ 
			int oldLeftValue = node->Left->data;
			treeNode* newLeft = new treeNode(value, node, node->Left->Left, node->Left->Right, node->Left->onRightSideOfTree);
			delete node->Left;
			node->Left = newLeft;
			return insertNewValueIntoBST(oldLeftValue, node->Left);
		}

		if (!node->Right->full)
		{
			int oldRightValue = node->Right->data;
			bool rightSide = node->Right->onRightSideOfTree;
			treeNode* newRight = new treeNode(value, node, node->Right->Left, node->Right->Right, rightSide);
			delete node->Right;
			node->Right = newRight;
			return insertNewValueIntoBST(oldRightValue, node->Right);
		}
		
		int oldLeftValue = node->Left->data;
		bool rightSide = node->Left->onRightSideOfTree;
		treeNode* newLeft = new treeNode(value, node, node->Left->Left, node->Left->Right, rightSide);
		delete node->Left;
		node->Left = newLeft;
		return insertNewValueIntoBST(oldLeftValue, node->Left);              
	}


	if (value < node->data)
	{

		if (node->Left == NULL)
		{
			bool rightSide = node->Parent == NULL ? false : node->onRightSideOfTree;
			node->Left = new treeNode(value, node, rightSide);
			return node->Left;
		}

		return insertNewValueIntoBST(value, node->Left);
	}

	if (value > node->data)
	{
		if (node->Right == NULL)
		{
			bool rightSide = node->Parent == NULL ? true : node->onRightSideOfTree;
			node->Right = new treeNode(value, node, rightSide);
			return node->Right;
		}

		return insertNewValueIntoBST(value, node->Right);
	}

	// possible later optimization: move nodes instead of deleting them?
}

treeNode* traverseToRoot(treeNode* node)
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

