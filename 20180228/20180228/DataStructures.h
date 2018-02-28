#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#define max(x,y) x > y ? x : y
#define min(x,y) x < y ? x : y

using namespace std;

int maxDepth = 0;
int minDepth = 100;

template<class T> class Queue {
public:
	Queue<T>() {
		_first = _last = new LinkedList<T>();
	}
	
	void EnQueue(T item)
	{
		

			

		

	}

private:
	T _data;
	LinkedList * _first;
	LinkedList * _last;

};

template<class T>class LinkedList {
public:
	LinkedList * next;

	LinkedList<T>() {
		next = NULL;
		_data = NULL;
	}

	void AddList(T data) {
		if (_data == NULL)
			_data = data;
		else {
			if (next == NULL)
				next = new LinkedList();

			next->AddList(data);
		}
	}

	void AddItem(T data) {
		_data = data;
	}
	

private :
	T _data;

};

template <class T>class BinaryTree {
public:
	BinaryTree<T>* _leftChild;
	BinaryTree<T>* _rightChild;

	BinaryTree<T>(T item,int depth) {
		_data = item;
		_leftChild = NULL;
		_rightChild = NULL;
		_depth = depth;
	}

	void AddLeftChild(T item)
	{
		_leftChild = new BinaryTree(item, _depth + 1);
	}

	void AddRightChild(T item)
	{
		_rightChild = new BinaryTree(item, _depth + 1);
	}

	void Insert(T item)
	{
		if (_data == NULL)
			_data = item;
		else
		{
			if (_data > item)
			{
				if (_leftChild != NULL)
					_leftChild->Insert(item);
				else
					AddLeftChild(item);
			}
			else
			{
				if (_rightChild != NULL)
					_rightChild->Insert(item);
				else
					AddRightChild(item);
			}
		}
	}

	//4_1
	bool IsBtree() {
		
		if (_leftChild == NULL && _rightChild == NULL) {
			minDepth = min(minDepth, _depth);
			if (abs(maxDepth - minDepth) > 1)
				return false;
		}

		maxDepth = max(maxDepth, _depth);

		if (_leftChild != NULL)
			if (!_leftChild->IsBtree()) return false;
		if (_rightChild != NULL)
			if (!_rightChild->IsBtree()) return false;

		return true;
	}

protected:
	T _data;
	int _depth;
};

template <class T> class Graph
{
public :

	Graph<T>(T item) {
		_data = item;
	}

	void Link(Graph<T>* graph) 
	{
		_linkList.push_back(graph);
	}
	//4_2
	bool hasRouteByDFS(Graph<T>* graph)
	{
		visited = true;
		if (_linkList.size() != 0) {
			for (Graph<T>* link : _linkList) {
				if (link == graph)
					return true;
				else
				{
					if(!link->visited)
					if (link->hasRouteByDFS(graph))
						return true;
				}
			}
		}

		return false;
	}
private : 
	T _data;
	vector<Graph<T>*> _linkList;
	bool visited;
};