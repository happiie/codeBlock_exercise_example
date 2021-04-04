#include <iostream>
#include "class2.h"

using namespace std;

class2::class2 (int x, int y): class1(x) {
    setPrivate2(y);
}

void class2::setPrivate2(int x) {
    private2 = x;
}

int class2::getPrivate2 ()  {
    return private2;
}

int class2::calculateTotal()  {
    return class1::getPrivate1() + getPrivate2();
}

void  class2::displayInfo() {
    class1::displayInfo();
    cout << "Display class2\n";
}
