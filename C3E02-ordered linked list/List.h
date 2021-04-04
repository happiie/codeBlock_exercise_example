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
    bool searchItem(const int);
    int getFirst() const;
    int getLast() const;
    int findLength();

private:
    Node *firstPtr;
};

#endif // LIST_H_INCLUDED
