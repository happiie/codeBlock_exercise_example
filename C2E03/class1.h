#ifndef CLASS1_H_INCLUDED
#define CLASS1_H_INCLUDED

class class1 {
public:
    class1(int=0);
    void setPrivate1(int);
    int getPrivate1 ();

    virtual int calculateTotal() = 0; //pure virtual
    virtual void displayInfo();       //virtual

private:
    int private1;
};

#endif // CLASS1_H_INCLUDED
