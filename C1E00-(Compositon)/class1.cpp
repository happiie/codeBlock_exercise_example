#include <iostream>
#include "class1.h"

using namespace std;

class1::class1() {
    cout << ">>>>Constructor class1\n";
    i1 = 0;
    d1 = 0.0;
}

class1::~class1() {
    cout << ">>>>Destructor class1\n";
}

void class1::modifyI (int i) {
    i1 = i;
}

int class1::getI () {
    return i1;
}

void class1::modifyD (double d) {
    d1 = d;
}

double class1::getD () {
    return d1;
}

