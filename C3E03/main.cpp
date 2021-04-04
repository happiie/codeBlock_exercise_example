#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List l1;

    l1.printList();
    l1.insertItemAscending(2);
    l1.printList();
    l1.insertItemAscending(1);
    l1.printList();
    l1.insertItemAscending(5);
    l1.printList();
    l1.insertItemAscending(7);
    l1.printList();
    l1.insertItemAscending(6);
    l1.printList();
    l1.insertItemAscending(4);
    l1.printList();
    l1.insertItemAscending(8);
    l1.printList();
    l1.insertItemAscending(1);
    l1.printList();
    l1.insertItemAscending(3);
    l1.printList();
    l1.insertItemAscending(9);
    l1.printList();
    l1.insertItemAscending(0);
    l1.printList();

    l1.deleteItem(0);
    l1.printList();
    l1.deleteItem(3);
    l1.printList();
    l1.deleteItem(7);
    l1.printList();
    l1.deleteItem(9);
    l1.printList();
    l1.deleteItem(10);
    l1.printList();
    l1.deleteItem(1);
    l1.printList();
    l1.deleteItem(2);
    l1.printList();
    l1.deleteItem(1);
    l1.printList();
    l1.deleteItem(4);
    l1.printList();

    return 0;
}
