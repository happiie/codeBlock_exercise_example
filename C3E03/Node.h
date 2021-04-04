#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
    friend class List;

public:
    Node() {};
    Node(const int x): data(x), nextPtr(0), prevPtr(0) {};
    void setData (int x) { data = x; };
    void setNext (Node *y) { nextPtr = y; };
    void setPrev (Node *y) { prevPtr = y; };
    int getData() const { return data; };
    Node* getNext() const { return nextPtr; };
    Node* getPrev() const { return prevPtr; };

private:
    int data;
    Node *nextPtr, *prevPtr;
};


#endif // NODE_H_INCLUDED
