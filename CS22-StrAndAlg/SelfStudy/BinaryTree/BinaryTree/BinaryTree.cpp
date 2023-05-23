/*
Peter Doria
Sample code for a tree
*/

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>

enum Relation {None, Root, Parent, Left, Right};
static const char* relation_str[] = {"None", "Root", "Parent", "Left", "Right"};

struct treeNode
{
	int data;
	treeNode* Parent;
	treeNode* Left;
	treeNode* Right;
	bool onRightSideOfTree;
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


treeNode* makeGeneralTree(int * arr, int arrSize);
treeNode* makeBST(int * arr, int arrSize);
treeNode* traverseToRoot(treeNode* node);
treeNode* addNewNodeToTree(int* arr, int arrSize, const int i, treeNode* parentNode);
treeNode* insertNewValueIntoBST(int value, treeNode* node);
treeNode* traverseToPredecessor(treeNode* node);
treeNode* traverseToSuccessor(treeNode* node);
treeNode* traverseToLeftMostPredecessor(treeNode* node);
void outputTreeContentsFromRoot(treeNode* node, Relation relation, bool isFirstOutput = true);
void outputTreeContentsInOrder(treeNode* node, Relation relation, bool isFirstOutput = true);
treeNode* balanceBST(treeNode * node);

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

	outputTreeContentsFromRoot(sortedRoot, Relation(Root));
	outputTreeContentsInOrder(sortedRoot, Relation(Root));
	std::cout << "Root Predecessor: " << traverseToPredecessor(sortedRoot) << '\n';
	std::cout << "Root Successor: " << traverseToSuccessor(sortedRoot) << '\n';
	std::cout << "Left Most Predecessor: " << traverseToLeftMostPredecessor(sortedRoot) << '\n';
	std::cout << std::endl;
	outputTreeContentsFromRoot(unsortedRoot, Relation(Root));
	outputTreeContentsInOrder(unsortedRoot, Relation(Root));
	std::cout << "Root Predecessor: " << traverseToPredecessor(unsortedRoot) << '\n';
	std::cout << "Root Successor: " << traverseToSuccessor(unsortedRoot) << '\n';
	std::cout << "Left Most Predecessor: " << traverseToLeftMostPredecessor(unsortedRoot) << '\n';
	std::cout << std::endl;
	outputTreeContentsFromRoot(equalsMixRoot, Relation(Root));
	outputTreeContentsInOrder(equalsMixRoot, Relation(Root));
	std::cout << "Root Predecessor: " << traverseToPredecessor(equalsMixRoot) << '\n';
	std::cout << "Root Successor: " << traverseToSuccessor(equalsMixRoot) << '\n';
	std::cout << "Left Most Predecessor: " << traverseToLeftMostPredecessor(equalsMixRoot) << '\n';
	std::cout << std::endl;
}

/***************************************
	Constructs tree from a given array.
	Returns tree root node. 
*****************************************/
treeNode* makeGeneralTree(int * arr, int arrSize)
{
	treeNode* tree = addNewNodeToTree(arr, arrSize, 0, NULL);
	assert((("must return root"), tree->Parent == NULL));
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

		if (!node->Left->Left && !node->Left->Right)
		{ 
			int oldLeftValue = node->Left->data;
			treeNode* newLeft = new treeNode(value, node, node->Left->Left, node->Left->Right, node->Left->onRightSideOfTree);
			delete node->Left;
			node->Left = newLeft;
			return insertNewValueIntoBST(oldLeftValue, node->Left);
		}

		if (!node->Right->Left && !node->Right->Right)
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

treeNode* traverseToPredecessor(treeNode * node)
{
	assert((("Cannot search for a NULL node's predecessor. It doesn't exist.")), node != NULL);
	if (node->Left)
		return node->Left;
	if (node->onRightSideOfTree)
	{
		return traverseToPredecessor(node->Parent);
	}
	return node;
}

treeNode* traverseToLeftMostPredecessor(treeNode* node)
{
	assert(("Cannot search for NULL node's predecessor. It doesn't exist."), (node != NULL));
	treeNode* predecessor = NULL;
	treeNode* tempNode = traverseToPredecessor(node);
	while (predecessor != tempNode)
	{
		predecessor = tempNode;
		tempNode = traverseToPredecessor(predecessor);
	}
	if (predecessor == NULL)
		return node;

	return predecessor;
}

treeNode* traverseToSuccessor(treeNode * node)
{
	assert(("Cannot search for NULL node's successor. It doesn't exist."), node != NULL);
	if (node->Right)
		return node->Right;
	if (node->onRightSideOfTree == false && node->Parent)
	{
		return traverseToSuccessor(node->Parent);
	}
	return node;
}

/************************************************
	Recursively outputs data on each node in 
		tree to console
*************************************************/
void outputTreeContentsFromRoot(treeNode* node, Relation relation, bool isFirstOutput)
{
	assert((("Node passed to OutputTreeContents is Null"), node != NULL));
	
	std::stringstream nodeStream;
	nodeStream << node;

	if (node->Parent == NULL)
		std::cout << "Relation to previous node:" << relation_str[relation] 
		<< ", Data: " << std::to_string(node->data) 
		<< ", " << "Location " << nodeStream.str() 
		<< ", *IsRoot* " << '\n';
	else
		std::cout << "Relation to previous node:" << relation_str[relation] 
		<< ", Data: " << std::to_string(node->data) 
		<< ", " << "Location " << nodeStream.str() << '\n';
	

	if (node->Left != NULL)
		outputTreeContentsFromRoot(node->Left, Relation(Left), false);
	if (node->Right != NULL)
		outputTreeContentsFromRoot(node->Right, Relation(Right), false);

}

void outputTreeContentsInOrder(treeNode* node, Relation relation, bool isFirstOutput)
{
	assert(("Node passed to Ouput Tree is NULL"), node != NULL);
	if (node->Left)
		outputTreeContentsInOrder(node->Left, Relation(Right), false);

	std::stringstream nodeStream;
	nodeStream << node;
	if (node->Parent == NULL)
	{
		std::cout <<
			"Relation to next node:" << relation_str[relation] 
			<< ", Data: " << std::to_string(node->data) 
			<< ", Location: " << nodeStream.str() 
			<< ", *isRoot* " << '\n';
	}
	else
	{
		std::cout <<
			"Relation to next node:" << relation_str[relation]
			<< ", Data: " << std::to_string(node->data)
			<< ", Location: " << nodeStream.str() << '\n';
	}
	
	if (node->Right)
		outputTreeContentsInOrder(node->Right, Relation(Right), false);
}
