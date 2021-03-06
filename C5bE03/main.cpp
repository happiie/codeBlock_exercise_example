#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;

const int TABLE_SIZE = 128;

class HashNode {
public:
    int key;
    int value;
	HashNode* next;
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
	    this->next = NULL;
    }
};

class HashMap {
private:
    HashNode** htable;

public:
    HashMap() {
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
           htable[i] = NULL;
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
                HashNode* entry = htable[i];
                while (entry != NULL) {
                    HashNode* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
        delete[] htable;
    }

    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void Insert(int key, int value) {
        int hash_val = HashFunc(key);
        HashNode* prev = NULL;
        HashNode* entry = htable[hash_val];
        while (entry != NULL) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == NULL) {
            entry = new HashNode(key, value);
            if (prev == NULL) {
                htable[hash_val] = entry;
            }
	        else {
                prev->next = entry;
            }
        }
        else {
            entry->value = value;
        }
     }

     void Remove(int key) {
            int hash_val = HashFunc(key);
            HashNode* entry = htable[hash_val];
            HashNode* prev = NULL;
            if (entry == NULL || entry->key != key) {
            	cout<<"No Element found at key " << key << endl;
                return;
            }
            while (entry->next != NULL) {
                prev = entry;
                entry = entry->next;
            }

            if (prev != NULL) {
                prev->next = entry->next;
            }

            cout << entry->key << " Deleted"<<endl;
            delete entry;
     }

     void Search(int key) {
            bool flag = false;
            int hash_val = HashFunc(key);
            HashNode* entry = htable[hash_val];
            while (entry != NULL) {
                if (entry->key == key) {
                    cout << entry->value << " found\n";
                    flag = true;
                }
                entry = entry->next;
            }

            if (!flag)
                cout << key << " not found\n";
    }

};

int main() {
    HashMap h1;
    h1.Insert(1, 10);
    h1.Insert(2, 11);
    h1.Search(1);
    h1.Remove(1);

    return 0;
}
