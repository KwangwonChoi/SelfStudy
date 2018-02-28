#include "DataStructures.h"

template<typename T>
BinaryTree<T>* MakeMinimumBST(int left, int right, int* arr) {

	BinaryTree<T>* ret;
	int mid = (left + right) / 2;

	if (left > right)
		return NULL;
		
	ret = new BinaryTree<T>(arr[mid],0);

	ret->_leftChild = MakeMinimumBST<T>(left, mid - 1, arr);
	ret->_rightChild = MakeMinimumBST<T>(mid + 1, right, arr);
	
	return ret;
}

void main() 
{
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	BinaryTree<int>* bst = MakeMinimumBST<int>(0,8,a);

}