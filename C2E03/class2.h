#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include "class1.h"

class class2 : public class1 {
public:
    class2(int=0, int=0);
    void setPrivate2(int);
    int getPrivate2 () ;

    virtual int calculateTotal(); //pure virtual
    virtual void displayInfo();       //virtual

private:
    int private2;
};

#endif // CLASS2_H_INCLUDED
