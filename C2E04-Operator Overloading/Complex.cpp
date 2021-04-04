#include <iostream>
#include "Complex.h"

using namespace std;

void Complex::display() {
    cout << real << " + j" << imag << endl;
}

void Complex::operator= (const Complex& other) {
    real = other.real;
    imag = other.imag;
}

Complex Complex::operator+ (const Complex& other) {
    double result_real = real + other.real;
    double result_imag = imag + other.imag;
    return Complex(result_real, result_imag);
}

void Complex::operator++ () {
    real +=1;
    imag +=1;
}

void Complex::operator+= (int n) {
    real +=n;
    imag +=n;
}

bool Complex::operator== (const Complex& other) {
    if (real == other.real && imag == other.imag)
        return true;

    return false;
}

ostream& operator<< (ostream& os, const Complex& other) {
    os << other.real << " +j" << other.imag << endl;
    return os;
}

istream& operator>> (istream& is, Complex& other) {
    char ch;

    is >> ch;
    is >> other.real;
    is >> ch;
    is >> other.imag;
    is >> ch;

    return is;
}

