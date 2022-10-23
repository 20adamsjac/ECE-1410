#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

template <class T>
class Queue
{
public:
	Queue() { count = 0; head = NULL; tail = NULL; }
	~Queue();
	void enqueue(T);
	int count() { return count; }
	T front() { return head->getData; }
	void dequeue();
	void reset();

private:
	int count;
	Node<T>* head, tail;
};

template <class T>
Queue<T>::~Queue()
{
	Node<T>* cur = head, prev = NULL;

	while (prev->getNext != NULL)
	{
		delete prev;

		prev = cur;
		cur = prev->getNext;
	}

	head = NULL;
	tail = NULL;
	count = 0;
}

template <class T>
void Queue<T>::enqueue(T x)
{
	Node<T> n = new Node<T>;
	n.setData(x);
	n.setNext(NULL);

	if (count == 0)
	{
		head = &n;
		tail = &n;
	}
	else
	{
		Node<T>* temp;
		temp = head;
		temp->setNext(&n);
		head = &n;
	}
	count++;
}

template <class T>
void Queue<T>::dequeue()
{
	Node<T>* temp = tail;
	tail = temp->getNext;
	delete temp;
}

template <class T>
void Queue<T>::reset()
{
	Node<T>* cur = head, prev = NULL;

	while (prev->getNext != NULL)
	{
		delete prev;

		prev = cur;
		cur = prev->getNext;
	}

	head = NULL;
	tail = NULL;
	count = 0;
}

#endif 
