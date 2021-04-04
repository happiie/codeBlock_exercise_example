#include <iostream>
#include <iomanip>
#include "class2.h"

using namespace std;

class2::class2(int x, int y, int z) : class1(x,y) {
    cout << ">>>>Constructor of class2\n";
    SetPrivate2(z);
}

class2::~class2() {
    cout << ">>>>Destructor of class2\n";
}

void class2::SetPrivate2(int x) {
    private2 = x;
}

int class2::GetPrivate2() {
    return private2;
}

void class2::SetProtected1(int x) {
    protected1 = x;
}

int class2::GetProtected1() {
    return protected1;
}

void class2::SetPrivate1(int x) {
    setPrivate1(x);
}

int class2::GetPrivate1() {
    return getPrivate1();
}

int class2::GetPublic1() {
    return public1;
}

void class2::displayTotal() {
    cout << "Class2 Total: " <<  getPrivate1() + protected1 + private2 << endl;
}
