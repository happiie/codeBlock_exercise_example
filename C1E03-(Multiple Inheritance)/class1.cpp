#include <iostream>
#include "class1.h"

using namespace std;

class1::class1(int x) {
    cout << ">>>>Constructor of class1\n";
    setProtected1(x);
}

class1::~class1() {
    cout << ">>>>Destructor of class1\n";
}

void class1::setProtected1(int x) {
    protected1 = x;
}

int class1::getProtected1() {
    return protected1;
}

void class1::displayTotal() {
    cout << "Class1 Total: " <<  protected1 << endl;
}
