#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

template <class T>
class Stack 
{
public:
	Stack() { count = 0; head = NULL; }
	~Stack();
	void push(T);
	int count() { return count; }
	T top();
	void pop();
	void reset();

private:
	int count;
	Node<T>* head;
};

template <class T>
Stack<T>::~Stack()
{
	Node<T>* cur = head, prev = NULL;

	while (prev->getNext != NULL)
	{
		delete prev;

		prev = cur;
		cur = prev->getNext;
	}

	head = NULL;
	count = 0;
}

template <class T>
void Stack<T>::push(T x)
{
	Node<T> n = new Node<T>;
	n.setData(x);
	n.setNext(NULL);

	if (count == 0)
	{
		head = &n;
	}
	else
	{
		Node<T>* cur = head, prev = NULL; 

		while (cur->getNext != NULL)
		{
			prev = cur;
			cur = prev->getNext;
		}

		cur->setNext(&n);
	}
	count++;
}

template <class T>
T Stack<T>::top()
{
	Node<T>* cur = head;

	while (cur->getNext != NULL)
	{
		cur = cur->getNext;
	}
	return cur->getData;
}

template <class T>
void Stack<T>::pop()
{
	Node<T>* cur = head, prev = NULL;

	while (cur->getNext != NULL)
	{
		prev = cur;
		cur = prev->getNext;
	}
	prev->setNext(NULL);
	delete cur;
}

template <class T>
void Stack<T>::reset()
{
	Node<T>* cur = head, prev = NULL;

	while (prev->getNext != NULL)
	{
		delete prev;

		prev = cur;
		cur = prev->getNext;
	}

	head = NULL;
	count = 0;
}

#endif 
