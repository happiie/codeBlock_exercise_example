#include <iostream>
#include "class4.h"

using namespace std;

class4::class4 (int x, int y, int z): class3(x, y) {
    setPrivate4(z);
}

void class4::setPrivate4(int x) {
    private4 = x;
}

int class4::getPrivate4 ()  {
    return private4;
}

int class4::calculateTotal()  {
    return class3::calculateTotal() + getPrivate4();
}

void  class4::displayInfo() {
    class3::displayInfo();
    cout << "Display class4\n";
}
