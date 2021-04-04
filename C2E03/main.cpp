#include <iostream>
#include "class2.h"
#include "class3.h"
#include "class4.h"

using namespace std;

int main()
{
//    class1 o1(10);
    class2 o2 (20, 30);
    class3 o3 (40, 50);
    class4 o4 (60, 70, 80);

    cout << "o2 total: " << o2.calculateTotal() << endl;
    cout << "o3 total: " << o3.calculateTotal() << endl;
    cout << "o4 total: " << o4.calculateTotal() << endl;

    cout << "Display o2\n";
    o2.displayInfo();
    cout << "Display o3\n";
    o3.displayInfo();
    cout << "Display o4\n";
    o4.displayInfo();

    return 0;
}
