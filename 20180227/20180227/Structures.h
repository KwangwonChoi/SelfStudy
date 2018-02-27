#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<class T> class Node {
public :
	Node<T> * next;
	
	Node<T>(T item) 
	{
		value = item;
	}

	T getItem() {
		return value;
	}

private :
	T value;
};

template<class T> class Stack {
public:
	Node<T> * top;

	Stack<T>() {
		top = NULL;
	}

	T pop() {
		if (top != NULL) {
			T item = top->getItem();
			top = top->next;
			return item;
		}

		return NULL;
	}

	void push(T item) {
		Node* t = new Node<T>(item);
		t->next = top;
		top = t;
	}

	T peek()
	{
		if(top != NULL)
		return top->getItem();

		return NULL;
	}
	bool isEmpty() 
	{
		if (peek() == NULL)
			return true;
		else
			return false;
	}
};

template<class T> class Queue{
public:
	Node<T> *first, *last;

	void Enqueue(T item) 
	{
		if (first == NULL) {
			last = new Node<T>(item);
			first = last;
		}
		else {
			last->next = new Node<T>(item);
			last = last->next;
		}
	}

	T dequeue() {
		if (first != NULL)
		{
			T item = first->getItem();

			first = first->next;

			return item;
		}

		return NULL;
	}

	T peek() {
		if (first != NULL)
		{
			return item = first->getItem();
		}

		return NULL;
	}
};
