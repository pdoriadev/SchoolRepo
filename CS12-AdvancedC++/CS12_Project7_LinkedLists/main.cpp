#include <string>
#include <iostream>
#include <assert.h>

struct result
{
	bool success;
	std::string message;
	result(bool _success, std::string _mess)
	{
		success = _success;
		message = _mess;
	}
};

template <class T>
struct nodeType
{
	T data;
	nodeType<T>* next = nullptr;
	
	nodeType(T _data)
	{
		data = _data;
	}
};

template <class T>
class linkedListType
{
private:
	
	nodeType<T>* head;
	nodeType<T>* tail;
	int counter;

	result initializeList()
	{
		head = nullptr;
		tail = nullptr;
		counter = 0;
		return result(true, "List is initialized");
	}
	result destroyList()
	{
		nodeType<T>* current = head;
		nodeType<T>* next;
		while (current != nullptr)
		{
			next = current->next;
			delete current;
			current = next;
			counter -= 1;
		}
		
		assert(counter == 0 && "Did not delete all nodes OR counter logic is flawed.");

		return result(true, "List is destroyed");
	}

public:
	linkedListType()
	{
		initializeList();
	}
	~linkedListType()
	{
		destroyList();
	}

	int length() { return counter; }
	nodeType<T>* front() { return head; }
	nodeType<T>* back() { return tail; }

	result divideMid(linkedListType<T>& sublist)
	{
		if (head == nullptr) { return result(false, "List is empty"); }

		// find split-point
		int newLength = length() / 2;
		nodeType<T>* current = head;
		for (int i = 1; i < newLength; i++)
		{
			current = current->next;
			assert(current != nullptr && "Hit null node in linked list before end OR length does not match actual length.");
		}

		// Splitting lists
		tail = current;
		current = current->next;
		tail->next = nullptr;

		while (current != nullptr)
		{
			sublist.addNode(current->data);
			current = current->next;
			counter -= 1;
		}

		return result(true, "List has been split into two.");
	}

	result addNode(T x)
	{
		if (head == nullptr)
		{
			head = new nodeType<T>(x);
		}
		else if (tail == nullptr)
		{
			tail = new nodeType<T>(x);
			head->next = tail;
		}
		else
		{
			tail->next = new nodeType<T>(x);
			tail = tail->next;
		}

		counter += 1;
		return result(true, "Node added to list");
	}

	result deleteNode(nodeType<T> * n)
	{
		nodeType<T>* beforeCurrent = nullptr;
		nodeType<T>* current = head;
		while (current != nullptr)
		{
			if (current == n)
			{
				nodeType<T>* afterCurrent = current->next;
				if (afterCurrent == nullptr)
				{
					tail = beforeCurrent;
				}

				if (beforeCurrent != nullptr)
				{
					beforeCurrent->next = afterCurrent;
				}
				else
				{
					head = afterCurrent;
				}

				counter -= 1;
				return result(true, "Found and deleted node.");
			}

			beforeCurrent = current;
			current = current->next;
		}

		return result(false, "Node not found in list");
	}

	result printList()
	{
		if (head == nullptr) { return result(false, "List is empty."); }
	
		nodeType<T> * current = head;
		while (current != nullptr)
		{
			if (current->next != nullptr)
			{
				std::cout << "Data: " << current->data << ", Next Node: " << current->next << '\n';
			}
			else
			{
				std::cout << "Data: " << current->data << ", Next Node: nullptr" << '\n';
			}
			current = current->next;
		}

		return result(true, "Printed list");
	}
};



int main()
{
	linkedListType<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.addNode(i);
	}
	std::cout << "List 1\n============\n";
	list.printList();

	linkedListType<int> secondList;

	list.divideMid(secondList);
	std::cout << "List 1\n============\n";
	list.printList();
	std::cout << "List 2\n============\n";
	secondList.printList();
}