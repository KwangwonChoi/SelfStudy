#include "Structures.h"

using namespace std;

class MyQueue {
public:

	MyQueue() {
		NewStack = new Stack();
		OldStack = new Stack();
	}

	void enQueue(int item) 
	{
		NewStack->push(item);
	}

	int deQueue() {
		
		if (isEmpty())
			return NULL;

		if (OldStack->peek() == NULL)
			moveToOldStack();
		
		return OldStack->pop();
	}

	int peek() {

		if (isEmpty())
			return NULL;

		if (OldStack->peek() == NULL)
			moveToOldStack();

		return OldStack->peek();
	}

	bool isEmpty() {

		if (OldStack->peek() == NULL)
			if (NewStack->peek() == NULL)
				return true;

		return false;
	}

private:
	Stack* OldStack;
	Stack* NewStack;

	void moveToOldStack()
	{
		while (NewStack->peek() != NULL)
		{
			int item = NewStack->pop();
			OldStack->push(item);
		}
	}
};

void main() 
{
	MyQueue q;

	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);

	q.deQueue();
	q.deQueue();
	q.deQueue();

	
	cout << q.peek() << endl;
}