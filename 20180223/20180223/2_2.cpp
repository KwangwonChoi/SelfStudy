#include <iostream>
#include <vector>

using namespace std;

class LinkedList
{
public:
	char c;

	void addData(char character)
	{
		if (c == NULL)
			c = character;

		else
		{
			LinkedList* lastNode = FindLastNode();

			lastNode->next = new LinkedList();
			lastNode->next->c = character;
		}
	}

	LinkedList* deleteData(char character)
	{
		LinkedList* ptr;
		LinkedList* p_ptr;

		if (character == c)
			return next;

		if (next == NULL)
			return this;

		p_ptr = this;
		ptr = next;

		while (ptr)
		{
			if (ptr->c == character)
			{
				p_ptr->next = ptr->next;
			}

			p_ptr = p_ptr->next;
			ptr = ptr->next;
		}
	}

	void FindByLastIdx(int* idx,LinkedList** tgt) 
	{
		if (next != NULL)
			next->FindByLastIdx(idx,tgt);

		(*idx)--;

		if ((*idx) == 0) 
		{
			*tgt = this;
		}
	}

private:
	LinkedList* next;

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
	link->addData('a');
	link->addData('c');
	link->addData('b');
	link->addData('e');
	link->addData('c');
	link->addData('b');
	link->addData('e');
	link->addData('a');

	link->FindByLastIdx(&findNum, &tgt);
	cout << tgt->c << endl;


}
