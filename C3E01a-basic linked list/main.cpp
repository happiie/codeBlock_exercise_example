#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List l1;

    l1.printList();
    for (int i=0; i<10; i++) {
        l1.insertItem(i*2+1);
        l1.printList();
    }

    l1.insertItem(65), l1.insertItem(67), l1.insertItem(66);
    l1.printList();

    cout << "First: " << l1.getFirst() << endl;
    cout << "Last: " << l1.getLast() << endl;

    for (int i=0; i<20; i++) {
        if (l1.searchItem(i)) cout << i << " found\n";
        else cout << i << " not found\n";
    }

    for (int i=0; i<20; i++)
        l1.deleteItem(i);

    return 0;
}
