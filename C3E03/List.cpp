#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    firstPtr = NULL, lastPtr = NULL;
};

List::~List(){
    while (!isEmpty())
        deleteItem(getLast());
};

bool List::isEmpty(){
    return (firstPtr == 0);
};

void List::printList() {

    cout << "[Size: " << findLength() << "] ";

    Node *tmp = firstPtr;
    if (isEmpty()) {
        cout << "EMPTY\n";
        return;
    }
    cout << "NULL <-> ";
    while (tmp!=NULL) {
        cout << tmp->getData();
        cout << " <-> ";
        tmp = tmp->getNext();
    }
    cout << "NULL" << endl;
};

void List::insertItemAscending(const int x) {

    Node* newNode = new Node();
    newNode->setData(x);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);

    if (isEmpty()) {
        firstPtr = newNode;
        lastPtr = newNode;
        return;
    }

    if(firstPtr->getData() >= x) {
        firstPtr->setPrev(newNode);
        newNode->setNext(firstPtr);
        firstPtr = newNode;
        return;
    }

    Node *tmp = firstPtr, *left=NULL;

    while (tmp!=NULL && tmp->getData()<x) {
        left = tmp;
        tmp = tmp ->getNext();
    }

    left->setNext(newNode);
    newNode->setPrev(left);

    if (tmp==NULL) {
        lastPtr = newNode;
    }
    else {
        newNode->setNext(tmp);
        tmp->setPrev(newNode);
    }
};

void List::deleteItem(const int key){

    if (!searchItem(key)) {
        cout << "Item " << key << " not found\n";
        return;
    }

    Node *tmp = firstPtr;
    Node *prev, *next;

    while (tmp!=NULL) {
       if (tmp->getData() == key)
           break;
       tmp = tmp->getNext();
    }

    if (tmp==firstPtr) {
        if(tmp->getNext() == NULL && tmp->getPrev()==NULL) {
            firstPtr = NULL;
            lastPtr = NULL;
        }
        else {
            firstPtr=tmp->getNext();
            firstPtr->setPrev(NULL);
        }
    }
    else {
        prev = tmp->getPrev();
        next = tmp->getNext();

        if (next!=NULL&&prev!=NULL) {
            prev->setNext(next);
            next->setPrev(prev);
        }
        else {
            lastPtr=prev;
            prev->setNext(next);
        }
    }

    delete tmp;
    cout << "Item " << key << " deleted\n";
};

int List::getFirst() const {
        Node *tmp = firstPtr;
        return tmp->getData();
};

int List::getLast() const{
        Node *tmp = lastPtr;
        return tmp->getData();
};

int List::findLength() {
    if (isEmpty())
        return 0;

    int counter = 1;
    Node *tmp = firstPtr;
    while (tmp->getNext()!=NULL) {
        counter++;
        tmp = tmp->getNext();
    }

    return counter;
};

bool List::searchItem(const int key) {
    Node *tmp = firstPtr;

    while (tmp != NULL) {
        if (tmp->getData() == key)
            return true;
        tmp = tmp->getNext();
    }

    return false;
};
