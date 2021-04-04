#include <iostream>
#include <iomanip>
#include "class2.h"

using namespace std;

class2::class2(int x, int y) : class1(x) { //inheritance
    setPrivate2(y);
}

void class2::setPrivate2(int x) {
    private2 = x;
}

int class2::getPrivate2() {
    return private2;
}

void class2::displayTotal() {
    cout << "Class2 Total: " <<  getPrivate1() + private2 << endl;
}
