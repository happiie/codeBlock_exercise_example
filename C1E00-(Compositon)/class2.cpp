#include <iostream>
#include "class2.h"

using namespace std;

class2::class2() {
    cout << ">>>>Constructor class2\n";
}

class2::~class2() {
    cout << ">>>>Destructor class2\n";
}

void class2::modifyI (int i) {
    c1.modifyI(i);
}

int class2::getI () {
    return c1.getI();
}

void class2::modifyD (double d) {
    c1.modifyD(d);
}

double class2::getD () {
    return c1.getD();
}
