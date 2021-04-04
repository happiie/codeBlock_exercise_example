#include <iostream>
#include <iomanip>
#include "class3.h"

using namespace std;

class3::class3(int x, int y, int z) : class1(x), class2(y) {
    cout << ">>>>Constructor of class3\n";
    setProtected3(z);
}

class3::~class3() {
    cout << ">>>>Destructor of class3\n";
}

void class3::setProtected3(int x) {
    protected3 = x;
}

int class3::getProtected3() {
    return protected3;
}

void class3::displayTotal() {
    cout << "Class3 Total: " <<  protected1 + protected2 + protected3 << endl;
}
