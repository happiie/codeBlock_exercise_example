#include <iostream>
#include "class2.h"

using namespace std;

class2::class2(int x) {
    cout << ">>>>Constructor of class2\n";
    setProtected2(x);
}

class2::~class2() {
    cout << ">>>>Destructor of class2\n";
}

void class2::setProtected2(int x) {
    protected2 = x;
}

int class2::getProtected2() {
    return protected2;
}

void class2::displayTotal() {
    cout << "Class2 Total: " <<  protected2 << endl;
}
