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
    return (firstPtr == NULL);
};

int List::findLength() {
    if (isEmpty())
        return 0;

    Node *tmp = firstPtr;
    int counter = 1;

    while (tmp->getNext()!=firstPtr) {
        counter++;
        tmp = tmp->getNext();
    }

    return counter;
};

void List::printList() {

    cout << "[Size: " << findLength() << "] ";

    if (isEmpty()) {
        cout << "EMPTY\n";
        return;
    }

    cout << firstPtr ->getData() << " --> ";

    Node *tmp = firstPtr->getNext();
    while (tmp!=firstPtr) {
        cout << tmp->getData() << " --> ";
        tmp = tmp->getNext();
    }
    cout << "(" << firstPtr->getData() << ")";
    cout << "[" << lastPtr->getData() << "]" << endl;
};

int List::getFirst() const {
        return firstPtr->getData();
};

int List::getLast() const{
        return lastPtr->getData();
};

bool List::searchItem(const int key) {

    if(firstPtr->getData()==key)
        return true;

    Node *tmp = firstPtr->getNext();
    while (tmp != firstPtr) {
        if (tmp->getData() == key)
            return true;
        tmp = tmp->getNext();
    }

    return false;
};

void List::insertItem(const int x) {

    Node* newNode = new Node();
    newNode->setData(x);

    if(isEmpty()) {
        firstPtr=newNode;
    }
    else {
        Node *tmp = firstPtr;
        while (tmp->getNext() != firstPtr)
            tmp = tmp->getNext();
        tmp->setNext(newNode);
    }

    newNode->setNext(firstPtr);
    lastPtr=newNode;
    cout << x << " inserted\n";
};

void List::deleteItem(const int key){

    if (!searchItem(key)) {
        cout << "Item " << key << " not found\n";
        return;
    }

    if(firstPtr==lastPtr) {
        firstPtr=NULL;
        lastPtr=NULL;
    }
    else if (firstPtr->getData()==key) {
        firstPtr=firstPtr->getNext();
        lastPtr->setNext(firstPtr);
    }
    else {
        Node *tmp = firstPtr->getNext(), *prev = firstPtr;

        while (tmp!=firstPtr) {
            if(tmp->getData()==key)
                break;
            prev=tmp;
            tmp=tmp->getNext();
        }

        if (tmp==lastPtr) {
            lastPtr = prev;
        }

        prev->setNext(tmp->getNext());

        delete(tmp);
    }

    cout << "Item " << key << " deleted\n";
};
