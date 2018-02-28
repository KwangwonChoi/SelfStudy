#include "DataStructures.h"

using namespace std;

int main() {
	
	BinaryTree<int>* tree = new BinaryTree<int>(5, 0);

	tree->Insert(3);
	tree->Insert(7);
	tree->Insert(2);
	tree->Insert(4);
	tree->Insert(1);
	tree->Insert(6);
	tree->Insert(8);
	tree->Insert(9);

	if (tree->IsBtree())
		cout << "B-Tree" << endl;

	
}