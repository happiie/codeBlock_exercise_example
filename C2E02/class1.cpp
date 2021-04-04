#include <iostream>
#include <iomanip>
#include "class1.h"

using namespace std;

class1::class1(int x) {
    setPrivate1(x);
}

void class1::setPrivate1(int x) {
    private1 = x;
}

int class1::getPrivate1() {
    return private1;
}

void class1::displayTotal() {
        cout << "Class1 Total: " << private1 << endl;
}
