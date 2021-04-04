#include <iostream>
#include <iomanip>
#include "class2.h"

using namespace std;

int main() {
    class1 o1(10, 20);
    class2 o2 (30, 40, 50);
    cout << endl;

    cout << "o1's Protected1: " << o1.getProtected1() << endl;
    cout << "o1's Private1: " << o1.getPrivate1() << endl;
    cout << "o1's Public1: " << o1.public1 << endl;
    o1.displayTotal();
    cout << endl;

    cout << "o2's Private2: " << o2.GetPrivate2() << endl;
    cout << "o2's Protected1: " << o2.GetProtected1() << endl;
    cout << "o2's Private1: " << o2.GetPrivate1() << endl;
    cout << "o2's Public1: " << o2.GetPublic1() << endl;
    o2.displayTotal();
    cout << endl;


    o2.SetPrivate1(60);
    o2.SetPrivate2(70);
    o2.SetProtected1(80);
    cout << "o2's Protected1: " << o2.GetProtected1() << endl;
    cout << "o2's Private1: " << o2.GetPrivate1() << endl;
    cout << "o2's Private2: " << o2.GetPrivate2() << endl;
    o2.displayTotal();

    cout << endl;

    return 0;
}
