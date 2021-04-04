#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1(2.3, 4.5), c2, c3;
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();

    c2=c1;
    cout << "c2 = ";
    c2.display();

    c3 = c1 + c2;
    cout << "c3 = ";
    c3.display();

    if (c1==c2)
        cout << "c1 same as c2\n";
    else
        cout << "c1 not same as c2\n";

    if (c1==c3)
        cout << "c1 same as c3\n";
    else
        cout << "c1 not same as c3\n";

    ++c1;
    cout << "c1 = ";
    c1.display();

    c1+=2;
    cout << "c1 = ";
    c1.display();

    cout << "Enter a complex number (a, b): ";
    cin >> c1;
    cout << "c1 is " << c1;

    return 0;
}
