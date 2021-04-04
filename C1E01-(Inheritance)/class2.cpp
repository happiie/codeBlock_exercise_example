#include <iostream>
#include <iomanip>
#include "class2.h"

using namespace std;

class2::class2(int x, int y, int z) : class1(x,y) { //inheritance
    cout << ">>>>Constructor of class2\n";
    setPrivate2(z);
}

class2::~class2() {
    cout << ">>>>Destructor of class2\n";
}

void class2::setPrivate2(int x) {
    private2 = x;
}

int class2::getPrivate2() {
    return private2;
}

void class2::displayTotal() {
    cout << "Class2 Total: " <<  getPrivate1() + protected1 + private2 << endl; //Private1 cannot be accessed directly
}
