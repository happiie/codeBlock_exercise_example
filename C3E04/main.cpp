#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List l1;

    l1.printList();

    l1.insertItem(1);
    l1.printList();
    l1.insertItem(2);
    l1.printList();
    l1.deleteItem(1);
    l1.printList();
    l1.deleteItem(2);
    l1.printList();


    for (int i=1; i<8; i++) {
        l1.insertItem(i);
        l1.printList();
    }

    for (int i=0; i<10; i++) {
        if(l1.searchItem(i))
            cout << i << " found\n";
        else
            cout << i << " not found\n";
    }


    l1.deleteItem(10);
    l1.printList();
    l1.deleteItem(2);
    l1.printList();
    l1.deleteItem(7);
    l1.printList();
    l1.deleteItem(3);
    l1.printList();
    l1.deleteItem(1);
    l1.printList();
    l1.deleteItem(6);
    l1.printList();

    return 0;
}
