#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
    friend class List;

public:
    Node() {};
    Node(const int x): data(x), nextPtr(0) {};
    void setData (int x) { data = x; };
    void setNext (Node *y) { nextPtr = y; };
    int getData() const { return data; };
    Node* getNext() const { return nextPtr; };

private:
    int data;
    Node *nextPtr;
};

#endif // NODE_H_INCLUDED
