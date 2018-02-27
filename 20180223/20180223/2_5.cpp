#include <iostream>
#include <vector>

using namespace std;

class LinkedList
{
public:

	LinkedList * next;

	int getNum() 
	{
		return num;
	}

	void addData(int num)
	{
		LinkedList* lastNode = FindLastNode();

		size++;

		lastNode->next = new LinkedList();
		lastNode->next->num = num;
	}

	void deleteData(int num)
	{
		LinkedList* ptr;
		LinkedList* p_ptr;

		size--;

		p_ptr = FindParentNode(num);
		ptr = FindNode(num);

		p_ptr->next = ptr->next;
	}

	LinkedList* FindParentNode(int num) 
	{
		LinkedList* p_pointer = NULL;
		LinkedList* pointer = next;

		while (pointer)
		{
			if (pointer->num != NULL)
			{
				if (pointer->num == num)
				{
					return p_pointer;
				}
			}

			p_pointer = pointer;
			pointer = pointer->next;
		}
	
	}

	LinkedList* FindNode(int num)
	{
		LinkedList* pointer = next;

		while (pointer)
		{
			if (pointer->num != NULL)
			{
				if (pointer->num == num)
				{
					return this;
				}
			}

			pointer = pointer->next;
		}
	}

	void Print() 
	{
		LinkedList* ptr = next;
		
		if(!ptr)
		{
			cout << num << endl;
			ptr->Print();
		}
	}

private:
	int num;
	int size;

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


LinkedList* PlusTwoInteger(LinkedList* tgt1, LinkedList* tgt2)
{
	LinkedList* ret = new LinkedList();
	
	int restNum = 0;
	int addedNum = 0;
	int det;

	while(true)
	{
		ret->addData(restNum);

		int calculNum = tgt1->getNum() + tgt2->getNum();

		restNum = calculNum / 10;
		addedNum = calculNum % 10;

		ret->addData(addedNum);

		tgt1 = tgt1->next;
		tgt2 = tgt2->next;

		if (!tgt1) { det = 1; break; }
		if (!tgt2) { det = 0; break; }
	}
	if (det == 1) {
		while(tgt2)
		{
			ret->addData(tgt2->getNum());
			tgt2 = tgt2->next;
		}
	}
	if (det == 0) {
		while (tgt1)
		{
			ret->addData(tgt1->getNum());
			tgt1 = tgt1->next;
		}
	}
	
	return ret;
	
}

void main() 
{
	LinkedList* link1 = new LinkedList();
	LinkedList* link2 = new LinkedList();
	LinkedList* result = NULL;

	link1->addData(1);
	link1->addData(3);
	link1->addData(2);

	link2->addData(2);
	link2->addData(4);

	result = PlusTwoInteger(link1, link2);

	result->Print();

}