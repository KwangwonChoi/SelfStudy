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
	}

	void deleteData(char character)
	{
		LinkedList* ptr;
		LinkedList* p_ptr;

		p_ptr = this;
		ptr = next;

		while (ptr)
		{
			if (ptr->c != NULL)
			{
				if (ptr->c == character)
				{
					p_ptr->next = ptr->next;
					return;
				}
			}

			p_ptr = p_ptr->next;
			ptr = ptr->next;
		}
	}

	void FindByIdxFromLast(int* idx, LinkedList** tgt)
	{
		if (next != NULL)
			next->FindByIdxFromLast(idx, tgt);

		(*idx)--;

		if ((*idx) == 0)
		{
			*tgt = this;
		}
	}

private:
	char c;
	LinkedList * next;

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
	int findNum = 7;
	LinkedList* tgt = NULL;

	link->addData('a');
	link->addData('c');
	link->addData('b');
	link->addData('e');

	link->deleteData('e');
	link->deleteData('a');
}
