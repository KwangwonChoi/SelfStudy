#include "Structures.h"

Stack* AscendingSort(Stack * stk) {
	Stack * tmp = new Stack();
	int num1, num2;

	if (!stk->isEmpty())
		num1 = stk->pop();
	else
		return stk;
	if (!stk->isEmpty())
		num2 = stk->pop();
	else
		return stk;

	if (num1 < num2) {
		tmp->push(num1);
		tmp->push(num2);
	}
	else
	{
		tmp->push(num2);
		tmp->push(num1);
	}

	while (!stk->isEmpty()) {
		int num = 0;

		num1 = stk->pop();
		num2 = tmp->pop();

		for (; !(num1 > num2);) {
			stk->push(num2);
			num2 = tmp->pop();
			num++;
		}

		tmp->push(num2);
		tmp->push(num1);

		for (int i = 0; i < num; i++)
		{
			tmp->push(stk->pop());
		}
	}

	return tmp;
}

void main() {
	Stack * ascendedStack;
	Stack * stk = new Stack();

	stk->push(5);
	stk->push(6);
	stk->push(4);
	stk->push(3);
	stk->push(1);
	stk->push(5);
	stk->push(4);
	stk->push(7);
	stk->push(9);
	stk->push(11);
	stk->push(5);

	ascendedStack = AscendingSort(stk);

}