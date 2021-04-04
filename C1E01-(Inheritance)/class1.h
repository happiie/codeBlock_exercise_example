#ifndef CLASS1_H_INCLUDED
#define CLASS1_H_INCLUDED

class class1 {
public:
    class1(int, int);
    ~class1();
    void setProtected1(int);
    int getProtected1();
    void setPrivate1(int);
    int getPrivate1();
    void displayTotal() const;

protected:
    int protected1;

private:
    int private1;

public:
    int public1;
};

#endif // CLASS1_H_INCLUDED
