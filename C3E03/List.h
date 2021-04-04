#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include "Node.h"

using namespace std;

class List {
public:
    List();
    ~List();
    bool isEmpty();
    void printList();
    void insertItemAscending(const int);
    void deleteItem(const int);
    int getFirst() const;
    int getLast() const;
    int findLength();
    bool searchItem(const int);

private:
    Node *firstPtr, *lastPtr;
};

#endif // LIST_H_INCLUDED
