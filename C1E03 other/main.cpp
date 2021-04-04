#include <iostream>
#include <iomanip>
#include "class3.h"

using namespace std;

int main()
{
    class3 o3 (10, 20, 30);
    cout << "Protected1: " << o3.getProtected1() << endl;
    cout << "Protected2: " << o3.getProtected2() << endl;
    cout << "Protected3: " << o3.getProtected3() << endl;
    o3.displayTotal();
    cout << endl;

    o3.setProtected1(40), o3.setProtected2(50), o3.setProtected3(60);

    cout << "Protected1: " << o3.getProtected1() << endl;
    cout << "Protected2: " << o3.getProtected2() << endl;
    cout << "Protected3: " << o3.getProtected3() << endl;
    o3.displayTotal();
    cout << endl;

    return 0;
}
