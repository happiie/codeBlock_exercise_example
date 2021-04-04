#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include "class1.h"

class class2 : public class1 {          // public inheritance
public:
    class2(int x, int y, int z);
    ~class2();
    void setPrivate2(int);
    int getPrivate2();

    void displayTotal();

private:
    int private2;
};

#endif // CLASS2_H_INCLUDED
