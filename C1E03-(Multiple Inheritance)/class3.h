#ifndef CLASS3_H_INCLUDED
#define CLASS3_H_INCLUDED

#include "class1.h"
#include "class2.h"

class class3 : public class1, public class2 {
public:
    class3(int x, int y, int z);
    ~class3();
    void setProtected3(int);
    int getProtected3();

    void displayTotal();

protected:
    int protected3;
};

#endif // CLASS3_H_INCLUDED
