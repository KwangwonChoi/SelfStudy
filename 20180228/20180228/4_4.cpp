#include "DataStructures.h"
#define MAX_DEPTH 10

template<typename T>
void MakeLinkBetweenSameDepth(BinaryTree<T>* tree) 
{
	LinkedList<BinaryTree<T>*>* LinkList = new LinkedList<BinaryTree<T>*>()[MAX_DEPTH];

	for (int i = 0; i < MAX_DEPTH; i++)
	{
		LinkedList[i] = new LinkedList<BinaryTree<T>*>();
	}


}

void BFS() {

}