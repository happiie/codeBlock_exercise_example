#ifndef CLASS1_H_INCLUDED
#define CLASS1_H_INCLUDED

class class1 {
    friend void displayInfo(class1 &);
public:
    class1();
    ~class1();
    void modifyI (int i);
    int getI ();
    void modifyD (double d);
    double getD ();

private:
    int i1;
    double d1;
};

#endif // CLASS1_H_INCLUDED
