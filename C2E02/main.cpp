#include <iostream>
#include <iomanip>
#include "class2.h"

using namespace std;

int main()
{
    class1 o1(20), *o1Ptr;
    class2 o2 (30, 40), *o2Ptr;

    cout << "Static Binding\n";
    o1.displayTotal();
    o2.displayTotal();

    cout << "\nDynamic Binding\n (1. base-class Pointer to base-class object)\n";
    o1Ptr = &o1;
    o1Ptr -> displayTotal();

    cout << "\n (2. derived-class Pointer to derived-class object)\n";
    o2Ptr = &o2;
    o2Ptr -> displayTotal();

    cout << "\n (2. base-class Pointer to derived-class object)\n";
    o1Ptr = &o2;
    o1Ptr -> displayTotal();

    return 0;
}
