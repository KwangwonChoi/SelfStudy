#include <iostream>
#include <string>

using namespace std;

class BST
{
public:
	BST() 
	{
		num = 1;
	}
	bool Insert(char i,bool flag)
	{
		if (value == NULL)
		{
			value = i;
			return true;
		}
		if (i == NULL)
		{
			return false;
		}
		if (value == i) {
			if (flag)
				num++;
			else
				num--;
			return true;
		}

		if (value > i)
		{
			if (leftChild == NULL)
				leftChild = new BST();

			leftChild->Insert(i,flag);
		}
		else
		{
			if (rightChild == NULL)
				rightChild = new BST();

			rightChild->Insert(i,flag);
		}
	}

	void traverse(int* i)
	{
		*i += num;

		if (leftChild != NULL)
			leftChild->traverse(i);
		
		if (rightChild != NULL)
			rightChild->traverse(i);
	}
private:
	char value;
	int num;
	BST* leftChild;
	BST* rightChild;
};

void main() 
{
	BST* tree = new BST();

	string str1;
	string str2;

	int determinant = 0;

	cout << "문자를 입력하세요" << endl;
	cin >> str1;

	for (int i = 0; tree->Insert(str1[i], true); i++);

	cout << "비교할 문자를 입력하세요" << endl;
	cin >> str2;

	for (int i = 0; tree->Insert(str2[i], false); i++);

	tree->traverse(&determinant);

	if (determinant == 0)
		cout << "같은수열입니다." << endl;
	else
		cout << "다른수열입니다." << endl;

}