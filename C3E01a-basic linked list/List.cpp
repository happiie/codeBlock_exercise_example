#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    initializeList();
};

List::~List(){
    destroyList();
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

    while (tmp!=NULL) {
        cout << tmp->getData();
        cout << " --> ";
        tmp = tmp->getNext();
    }
    cout << "NULL" << endl;
};

void List::insertItem(const int x) {

    Node* newNode = new Node();
    newNode->setData(x);
    newNode->setNext(NULL);

    Node *tmp = firstPtr;

    if (isEmpty())
        firstPtr = newNode;
    else {
        while (tmp->getNext() != NULL )
            tmp = tmp->getNext();
        tmp->setNext(newNode);
    }
};

void List::deleteItem(const int key){

    if (!searchItem(key)) {
        cout << "Item " << key << " not found\n";
        return;
    }

    Node *tmp = firstPtr;
    Node *prev;

    while (tmp!=NULL) {
       if (tmp->getData() == key)
           break;
       prev = tmp;
       tmp = tmp->getNext();
    }

    if (tmp == firstPtr)
        firstPtr = tmp->getNext();
    else
        prev->setNext(tmp->getNext());

    delete tmp;
    cout << "Item " << key << " deleted\n";
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

int List::getFirst() const {
        Node *tmp = firstPtr;
        return tmp->getData();
};

int List::getLast() const{
    Node *tmp = firstPtr;
    while (tmp->getNext()!=NULL)
        tmp = tmp->getNext();
    return tmp ->getData();
};

void List::initializeList(){
    firstPtr = NULL;
};

void List::destroyList(){
    while (!isEmpty())
        deleteItem(getLast());
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
