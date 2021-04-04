#ifndef CLASS4_H_INCLUDED
#define CLASS4_H_INCLUDED

#include "class3.h"

class class4: public class3 {
public:
    class4(int=0, int=0, int=0);
    void setPrivate4(int);
    int getPrivate4 () ;

    virtual int calculateTotal(); //pure virtual
    virtual void displayInfo();       //virtual

private:
    int private4;
};

#endif // CLASS4_H_INCLUDED
