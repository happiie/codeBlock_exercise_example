#include <iostream>
#include "class3.h"

using namespace std;

class3::class3 (int x, int y): class1(x) {
    setPrivate3(y);
}

void class3::setPrivate3(int x) {
    private3 = x;
}

int class3::getPrivate3 ()  {
    return private3;
}

int class3::calculateTotal()  {
    return class1::getPrivate1() + getPrivate3();
}

void  class3::displayInfo() {
    class1::displayInfo();
    cout << "Display class3\n";
}
