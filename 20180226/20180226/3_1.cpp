#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks 
{
public :
	SetOfStacks() {
		stack<int> tmp;
		stk.push_back(tmp);		
	}

	void push(int item) 
	{
		if (capacity++ < limit) {
			stk.back().push(item);
		}
		else {
			stack<int> newStack;
			capacity = 0;

			newStack.push(item);
			stk.push_back(newStack);
		}
	}

	void pop() {
		if (stk.back().empty())
		{
			stk.pop_back();
		}

		if (stk.size() != 0)
		{
			stk.back().pop();
		}
	}

private:
	vector<stack<int>> stk;
	int capacity = 0;
	const int limit = 5;
};

void main() {

	SetOfStacks stk;

	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(1);

	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.pop();
}