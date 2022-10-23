#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include "Node.hpp"
using namespace std;

template <class T>
class List
{
public:
	List() { count = 0; head = NULL; }
	~List();
	void insert(T);
	void reset();
	T at(int);
	int count() { return count; }
	bool contains(T);
	void remove(T);
	string toString();

private:
	int count;
	Node<T>* head;
};

template <class T>
List<T>::~List()
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
void List<T>::insert(T x)
{
	Node<T> n = new Node<T>;
	n.setData(x);
	n.setNext(NULL);

	if (count = 0)
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
void List<T>::reset()
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
T List<T>::at(int x)
{
	Node<T>* cur = head;

	for (int i = 0; i <= x; i++)
	{
		cur = cur->getNext;
	}

	return cur->getData;
}

template <class T>
bool List<T>::contains(T x)
{
	Node<T>* cur = head, prev = NULL;

	while (cur->getNext != NULL)
	{
		prev = cur;
		cur = prev->getNext;

		if (cur->getData == x || prev->getData == x)
			return true
	}
	return false;
}

template <class T>
void List<T>::remove(T x)
{
	Node<T>* cur = head, prev = cur;

	if (cur->getData == x)
	{
		head = cur->getNext;
		delete cur;
		count--;
	}

	while (cur->getNext != NULL)
	{
		cur = prev->getNext;

		if (cur->getData == x)
		{
			prev.setNext(cur->getNext);
			delete cur;
			count--;
		}
	}
}

template <class T>
string List<T>::toString()
{
	Node<T>* cur = head, prev = NULL;
	string total, part;

	part = to_string(head->getData);
	total.append(part);
	total.append(" ");

	while (cur->getNext != NULL)
	{
		prev = cur;
		cur = prev->getNext;

		part = to_string(cur->getData);
		total.append(part);
		total.append(" ");
	}
	return total;
}

#endif 
