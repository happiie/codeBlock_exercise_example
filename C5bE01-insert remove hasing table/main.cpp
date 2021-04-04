#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int TABLE_SIZE = 5;

class HashNode {
public:
     int key;
     int value;
     HashNode(int, int);
};

HashNode::HashNode(int key, int value) {
     this->key = key;
     this->value = value;
}

class DeletedNode:public HashNode { //class inheritance
private:
     static DeletedNode *entry;
     DeletedNode():HashNode(-1, -1) {}
public:
     static DeletedNode *getNode() {
        if (entry == NULL)
            entry = new DeletedNode();
        return entry;
     }
};

DeletedNode *DeletedNode::entry = NULL;

class HashMap {
private:
     HashNode **htable;   //A pointer to a pointer
public:
     HashMap();
     ~HashMap();
     int HashFunc(int);
     void Insert(int, int);
     int Search (int);
     void Remove(int);
     void Display();
};

HashMap::HashMap() {
     htable = new HashNode* [TABLE_SIZE];
     for (int i=0; i<TABLE_SIZE; i++)
          htable[i] = NULL;
};

HashMap::~HashMap() {
     for (int i=0; i<TABLE_SIZE; i++)
         if (htable[i]!=NULL && htable[i]!=DeletedNode::getNode())
                delete htable[i];
     delete[] htable;
};

int HashMap::HashFunc(int key) {
     return key%TABLE_SIZE;
};

void HashMap::Insert(int key, int value) {
    int hash_val = HashFunc(key);
    int init = -1;
    int deletedindex = -1;

    while (hash_val!=init &&
           ((htable[hash_val] == DeletedNode::getNode() ||
            htable[hash_val]!= NULL && htable[hash_val]->key != key))) {
                if (init == -1)
                    init = hash_val;
                if (htable[hash_val] == DeletedNode::getNode())
                    deletedindex = hash_val;
                hash_val = HashFunc(hash_val + 1);
    }

    if (htable[hash_val] == NULL || hash_val == init) {
        if(deletedindex != -1) {
               htable[deletedindex] = new HashNode(key, value);
        }
        else {
               htable[hash_val] = new HashNode(key, value);
        }
    }
    if(init != hash_val) {
        if (htable[hash_val] != DeletedNode::getNode()) {
               if (htable[hash_val] != NULL) {
                 if (htable[hash_val]->key == key){
                    htable[hash_val]->value = value;
                 }
               }
        }
        else {
              htable[hash_val] = new HashNode(key, value);
        }
    }

};

int HashMap::Search(int key) {
    int hash_val = HashFunc(key);
    int init = -1;
    int deletedindex = -1;

    while (hash_val!=init &&
           ((htable[hash_val] == DeletedNode::getNode() ||
            htable[hash_val]!= NULL && htable[hash_val]->key != key))) {
                if (init == -1)
                    init = hash_val;
                hash_val = HashFunc(hash_val + 1);
    }

    if (htable[hash_val] == NULL || hash_val == init)
          return -1;
    else
          return htable[hash_val]->value;
};

void HashMap::Remove(int key) {
    int hash_val = HashFunc(key);
    int init = -1;
    int deletedindex = -1;

    while (hash_val!=init &&
           ((htable[hash_val] == DeletedNode::getNode() ||
            htable[hash_val]!= NULL && htable[hash_val]->key != key))) {
                if (init == -1)
                    init = hash_val;
                hash_val = HashFunc(hash_val + 1);
    }

    if (htable[hash_val] == NULL || hash_val == init)
        cout << "No matched element to be removed\n";
    else {
       delete htable[hash_val];
       htable[hash_val] = DeletedNode::getNode();
     }
};

void HashMap::Display() {
    bool Empty = true;

    cout << "hValue\thTable[i]\tKey\tValue\n";
    for (int i = 0; i < TABLE_SIZE; i++)
        if (htable[i]!=NULL && htable[i]!=DeletedNode::getNode()) {
            cout << HashFunc(htable[i]->key) << "\t" << htable[i] << "\t" << htable[i]->key << "\t" << htable[i]->value << endl;
            Empty = false;
        }

    if (Empty==true)
        cout << "(Empty)\n";

    cout << "***End of HTable***\n\n";
};

int main() {
    HashMap hash;

    hash.Display();

    cout << "###INSERT###\n";
    for (int i=0; i<10; i++){
        hash.Insert(i, 2*i);
        hash.Display();
    }

    cout << "###SEARCH###\n";
    for (int i=0; i<=10; i++) {
        if(hash.Search(i) == -1)
              cout<< "No element found at key " << i << endl;
        else
              cout<< "Element found at key " << i << " : " << hash.Search(i) << endl;
    }

    cout << "\n###REMOVE###\n";
    for (int i=0; i<=10; i++)
        if(i!=8) {
         cout << "Removing key " << i << endl;
         hash.Remove(i);
         hash.Display();
        }

    int i=8;
    cout << "Removing key " << i << endl;
    hash.Remove(i);
    hash.Display();

    return 0;
}
