#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include "class1.h"

class class2 {
public:
    class2();
    ~class2();
    void modifyI (int i);
    int getI ();
    void modifyD (double d);
    double getD ();

private:
    class1 c1;	// composition
};

#endif // CLASS2_H_INCLUDED
