#include <iostream>
#include <string>

using namespace std;

class Stack 
{
public :
	Stack() 
	{
		next = NULL;
	}

	void push(char a) 
	{
		if (value != NULL)
		{
			Stack *stk = new Stack();
			stk->value = value;
			stk->next = next;
			
			next = stk;
		}

		value = a;
	}

	char pop() 
	{
		char ret = value;

		if (value == NULL)
			return NULL;
		
		if (next != NULL) {
			value = next->value;
			next = next->next;
		}

		return ret;
	}

private:
	char value;
	Stack* next;

};

void main() 
{
	Stack* stk = new Stack();
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++) 
	{
		stk->push(str[i]);
	}

	for (int i = 0; i < str.size(); i++)
		printf("%c", stk->pop());

}