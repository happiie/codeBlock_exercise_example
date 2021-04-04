#include <iostream>
#include <iomanip>
#include "class1.h"

using namespace std;

class1::class1(int x, int y) {
    cout << ">>>>Constructor of class1\n";
    setProtected1(x);
    private1 = y;
    public1 = 100;
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

void class1::setPrivate1(int x) {
    private1 = x;
}

int class1::getPrivate1() {
    return private1;
}

void class1::displayTotal() const {
    cout << "Class1 Total: " << private1 + protected1 << endl;

}
