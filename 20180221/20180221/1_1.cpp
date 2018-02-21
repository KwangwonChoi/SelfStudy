#include <iostream>
#include <string>

using namespace std;

class BST 
{
public :
	bool Insert(char i, bool& flag) 
	{
		if (value == NULL)
		{
			value = i;
			return true;
		}
		if (i == NULL)
		{
			flag = true;
			return false;
		}
		if (value == i)
			return false;

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
private :
	char value;
	BST* leftChild;
	BST* rightChild;
};

void main() 
{
	BST* tree = new BST();
	string str;
	bool flag = false;
	
	cin >> str;

	for (int i = 0; tree->Insert(str[i], flag); i++);

	if (flag)
		cout << "중복된 글자가 없습니다" << endl;
	else
		cout << "중복된 글자가 있습니다." << endl;
	


}