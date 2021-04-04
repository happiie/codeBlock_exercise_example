#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include "Node.h"

using namespace std;

class List {
public:
    List();
    ~List();
    void initializeList();
    void destroyList();
    bool isEmpty();
    void printList();
    void insertItem(const int); //insert to the end of the list
    void deleteItem(const int); //delete a selected node
    int getFirst() const;
    int getLast() const;
    bool searchItem(const int);
    int findLength();

private:
    Node *firstPtr;
};

#endif // LIST_H_INCLUDED
