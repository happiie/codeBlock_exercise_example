#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

using namespace std;

class Complex {
public:
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);

    Complex() : real(0.0), imag(0.0) {};
    Complex(double re, double im) : real(re), imag(im) {};

    void display();

    void operator=(const Complex& );
    Complex operator+(const Complex& );
    void operator++();
    void operator+=(int);
    bool operator== (const Complex& );

//private:
    double real;
    double imag;
};

#endif // COMPLEX_H_INCLUDED
