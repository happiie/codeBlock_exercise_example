#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include "class1.h"

class class2 : protected class1 {          // protected inheritance
public:
    class2(int x, int y, int z);
    ~class2();
    void SetPrivate2(int);
    int GetPrivate2();
    void SetProtected1(int);
    int GetProtected1();
    void SetPrivate1(int);
    int GetPrivate1();
    int GetPublic1();

    void displayTotal();

private:
    int private2;
};

#endif // CLASS2_H_INCLUDED
