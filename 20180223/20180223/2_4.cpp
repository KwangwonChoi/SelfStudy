#include <iostream>
#include <vector>

using namespace std;

class LinkedList
{
public:

	void addData(char character)
	{
		LinkedList* lastNode = FindLastNode();

		lastNode->next = new LinkedList();
		lastNode->next->c = character;
		lastNode->next->prev = lastNode;
	}

	void deleteData(char character)
	{
		LinkedList* ptr;

		ptr = FindNode(character);

		ptr->prev->next = ptr->next;
	}

	LinkedList* FindNode(char character)
	{
		LinkedList* pointer = next;

		while (pointer)
		{
			if (pointer->c != NULL)
			{
				if (pointer->c == character)
				{
					return this;
				}
			}

			pointer = pointer->next;

		}
	}

	void SemiQuickSort(char key)
	{
		LinkedList* ptr = NULL;
		vector<LinkedList*> smallNodes;
		LinkedList* keyNode = NULL;
		vector<LinkedList*> largeNodes;

		ptr = next;
		while (ptr)
		{
			if (ptr->c < key)
				smallNodes.push_back(ptr);
			else if (ptr->c > key)
				largeNodes.push_back(ptr);
			else
				keyNode = ptr;

			ptr = ptr->next;
		}

		//merge
		ptr = this;
		for (; smallNodes.size() != 0; ptr = ptr->next)
		{
			ptr->next = smallNodes.back();
			ptr->next->prev = ptr;
			smallNodes.pop_back();
		}

		ptr->next = keyNode;
		ptr = ptr->next;

		for (; largeNodes.size() != 0; ptr = ptr->next)
		{
			ptr->next = largeNodes.back();
			ptr->next->prev = ptr;
			largeNodes.pop_back();
		}


	}

private:
	char c;
	LinkedList * next;
	LinkedList * prev;

	LinkedList* FindLastNode()
	{
		LinkedList* ptr;

		ptr = next;

		if (ptr == NULL)
			return this;
		else
		{
			while (ptr->next) {
				ptr = ptr->next;
			}
			return ptr;
		}
	}
};

void main() 
{
	LinkedList* link = new LinkedList();


	link->addData('i');
	link->addData('j');
	link->addData('k');
	link->addData('a');
	link->addData('b');
	link->addData('c');
	link->addData('d');
	link->addData('e');
	link->addData('f');
	link->addData('g');
	link->addData('h');

	link->SemiQuickSort('h');
	
}