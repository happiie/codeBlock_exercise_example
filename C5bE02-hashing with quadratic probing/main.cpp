//Hash Tables with Quadratic Probing

#include <iostream>
#include <cstdlib>

#define MIN_TABLE_SIZE 10

using namespace std;

//enumeration declaration (a distinct type whose value is restricted to a range of values)
enum EntryType {Legitimate, Empty, Deleted}; // Legitimate = 0; Empty = 1; Deleted = 2;

struct HashNode {
      int element;
      enum EntryType info;
};

struct HashTable {
      int Size;
      HashNode *table;
};

bool isPrime (int n) {
   if (n == 2 || n == 3)
       return true;
   if (n == 1 || n % 2 == 0)
       return false;
   for (int i = 3; i*i<=n; i+=2)
      if (n % i == 0)
         return false;
   return true;
}

int nextPrime(int n) {
   if (n <= 0)         //2 is not used, so smallest prime is 3.
      n == 3;
   if (n%2 == 0)
      n++;
   for (; !isPrime(n); n+=2); //what is this line doing?
   return n;
}

int HashFunc(int key, int s) {
      return key%s;
}

HashTable *initializeTable(int s) {
      HashTable *htable;
      if (s<MIN_TABLE_SIZE) {
             cout << "Table Size Too Small " << endl;
             return NULL;
      }

      htable = new HashTable;

      if (htable == NULL) {
          cout << "Out of Space" << endl;
          return NULL;
      }

      htable->Size = nextPrime(s);
      htable->table = new HashNode [htable->Size];
      if (htable->table == NULL) {
          cout << "Table Size Too Small" << endl;
          return NULL;
      }

      for (int i=0; i<htable->Size; i++) {
          htable->table[i].info = Empty;
          htable->table[i].element = NULL;
      }

      cout << "Table of size " << htable->Size << " created." << endl;
      return htable;
}

int Find(int key, HashTable *htable) {
      int pos = HashFunc(key, htable->Size);

      if(htable->table[pos].info == Legitimate && htable->table[pos].element != key)
            return -1;
      else
            return pos;
}

void Remove (int key, HashTable *htable) {
    int pos = Find (key, htable);
      if (pos!=-1 && htable->table[pos].info == Legitimate && htable->table[pos].element == key) {
          htable->table[pos].info = Deleted;
          htable->table[pos].element = NULL;
          cout << "Element " << key << " removed at position " << pos << endl;
      }
      else {
          cout << "Element " << key << " not found to be removed. " << endl;
      }
}

int Insert(int key, HashTable *htable) {
      int pos = Find(key, htable);
      if (pos!=-1 && htable->table[pos].info != Legitimate) {
          htable->table[pos].info = Legitimate;
          htable->table[pos].element = key;
          cout << "Element " << key << " enter into position " << pos << endl;
          return 0;
      }
      else {
          cout << "Element " << key << " not entered. " << endl;
          return -1;
      }
}

HashTable *Rehash(HashTable *htable) {
   int s = htable->Size;
   HashNode *table = htable->table;
   htable = initializeTable(2*s);
   cout << "+++Rehashing existing table ... \n";
   for (int i = 0; i<s; i++) {
       if (table[i].info == Legitimate)
           Insert(table[i].element, htable);
   }
   cout << "+++Done!\n";
   free(table);
   return htable;
}

void Display(HashTable *htable) {
    cout << "\nPosition\tElement\t\tStatus(0:L;1:E;2:D)\n";
    for (int i=0; i<htable->Size; i++) {
         int value = htable->table[i].element;
         cout << i << "\t\t" << value << "\t\t" << htable->table[i].info << endl;
   }
}

int main() {
    HashTable *htable;

    cout << "***Initiate***\n";
    htable = initializeTable(10);
    Display(htable);

    cout << "\n***Insert Element & Rehash***\n";
    int enter;
    for (int i=0; i<20; i++) {              //try to change i from 10-30
        enter = Insert(i, htable);
        if (enter == -1) {
              htable=Rehash(htable);
              enter = Insert(i, htable);
        }
    }
    Display(htable);

    cout << "\n***Find Element***\n";
    int pos;
    for (int i=0; i<30; i++) {
        pos = Find(i, htable);
        if(pos==-1 || htable->table[pos].element!=i)
            cout << "Element " << i << " not found." << endl;
        else
            cout << "Element " << i << " found in position " << pos << endl;
    }

    cout << "\n***Remove Element***\n";
    int i = 10;
    Remove(i, htable);
    Display(htable);
    pos = Find(i, htable);
    if(pos==-1||htable->table[i].element!=i)
        cout << "Element " << i << " not found." << endl;
    else
        cout << "Element " << i << " found in position " << pos << endl;

    return 0;
}
