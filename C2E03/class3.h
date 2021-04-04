#ifndef CLASS3_H_INCLUDED
#define CLASS3_H_INCLUDED

#include "class1.h"

class class3 : public class1 {
public:
    class3(int=0, int=0);
    void setPrivate3(int);
    int getPrivate3 () ;

    virtual int calculateTotal(); //pure virtual
    virtual void displayInfo();       //virtual

private:
    int private3;
};

#endif // CLASS3_H_INCLUDED
