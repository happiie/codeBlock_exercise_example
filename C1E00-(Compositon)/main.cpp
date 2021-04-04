//Revision on Classes and Composition

#include <iostream>
#include "class1.h"
#include "class2.h"

using namespace std;

void displayInfo(class1 &c1) {
    cout << "The info are: " << c1.getI() << " and " << c1.getD() << endl;  //friend function
}

int main()
{
    class1 o1;
    class2 o2;

    cout << "(Before) o1 has properties: " << o1.getD() << " and " << o1.getI() << endl;
    o1.modifyD(2.5);
    o1.modifyI(3);
    cout << "(After) o1 has properties: " << o1.getD() << " and " << o1.getI() << endl;

    cout << "(Before) o2 has properties: " << o2.getD() << " and " << o2.getI() << endl;
    o2.modifyD(3.5);
    o2.modifyI(4);
    cout << "(After) o2 has properties: " << o2.getD() << " and " << o2.getI() << endl;

    class2 o3;

    cout << "(Before) o3 has properties: " << o3.getD() << " and " << o3.getI() << endl;
    o3 = o2;    //membershipwise assignment
    cout << "(After) o3 has properties: " << o3.getD() << " and " << o3.getI() << endl;

    displayInfo(o1);

    return 0;
}
