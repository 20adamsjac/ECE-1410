#ifndef BST_HPP 
#define BST_HPP

#include <string>
#include <iostream>
#include <sstream>

#include "Node.hpp"
using namespace std;

template <class T>
class BST
{
public:
    BST() {}
    BST(T data) {}

    void insert(T);
    bool contains(T);
    string search(T);
    int count() { return c; }

    void remove(T);

private:
    int c = 0;
    Node<T>* root;
};

template <class T>
void BST<T>::insert(T x)
{
    Node<T> temp(x);
    temp.setLeft(NULL);
    temp.setRight(NULL);

    if (c == 0)
        root = &temp;
    else
    {
        Node<T>* next = root;
        Node<T>* cur = root;
        while (next != NULL)
        {
            cur = next;

            if (x < cur->getData())
                next = cur->getLeft();
            else
                next = cur->getRight();
        }
        if (x < cur->getData())
            cur->setLeft(&temp);
        else
            cur->setRight(&temp);
    }
    c++;
}

template <class T>
bool BST<T>::contains(T x)
{
    Node<T>* cur = root;
    Node<T>* prev = NULL;

    while (cur != NULL)
    {
        if (cur->getData() == x)
            return true;
        else
        {
            prev = cur;

            if (x > cur->getData())
                cur = cur->getRight();
            else
                cur = cur->getLeft();
        }
    }
    return false;
}

template <class T>
string BST<T>::search(T x)
{
    Node<T>* cur = root;
    Node<T>* prev = NULL;

    string found = "Found: ", nfound = "Not found: ", roo, dat;

    stringstream ss;
    ss << root->getData();
    ss >> roo;

    string path = "root(" + roo + ")";
    

    while (cur != NULL)
    {
        if (cur->getData() == x)
        {
            found.append(path);
            return found;
        }
        else
        {
            prev = cur;

            ss << cur->getData();
            ss >> dat;

            if (x > cur->getData())
            {
                cur = cur->getRight();
                path.append("->right(" + dat + ")");
            }
            else
            {
                cur = cur->getLeft();
                path.append("->left(" + dat + ")");
            }
        }
    }
    nfound.append(path);
    return nfound;
}

template <class T>
void BST<T>::remove(T x)
{
    Node<T>* cur = root;
    Node<T>* prev = NULL;
    Node<T>* temp = NULL, tempprev = NULL;

    while (cur->getRight() != NULL && cur->getLeft() != NULL)
    {
        if (cur->getData() == x)
            break;
        else
        {
            prev = cur;
            if (x > cur->getData())
                cur = cur->getRight();
            else
                cur = cur->getLeft();
        }
    }

    
    if (cur->getRight() != NULL && cur->getLeft() != NULL)
    {
        if (x > prev->getData())
            prev->setRight(NULL);
        else
            prev->setLeft(NULL);
    }
    else
    {

        if (cur->getLeft() == NULL)
        {
            temp = cur->getRight();
            while (temp->getLeft() != NULL)
            {
                tempprev = temp;
                temp = temp->getLeft();
            }
            if (temp->getRight() != NULL)
                tempprev->setLeft(temp->getRight());
            else
                tempprev->setLeft(NULL);
        }

        else
        {
            temp = cur->getLeft();
            while (temp->getRight() != NULL)
            {
                tempprev = temp;
                temp = temp->getRight();
            }
            if (temp->getLeft() != NULL)
                tempprev->setRight(temp->getLeft());
            else
                tempprev->setRight(NULL);
        }

        if (temp->getData() > prev->getData())
            prev->setRight(temp);
        else
            prev->setLeft(temp);

        temp->setRight(cur->getRight());
        temp->setLeft(cur->getLeft());
    }

    c--;
}
#endif