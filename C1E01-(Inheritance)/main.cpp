#include <iostream>
#include <iomanip>
//#include <cstdlib>
#include "class2.h"

using namespace std;

int main() {
    class1 o1(10, 20);
    class2 o2 (30, 40, 50);
    cout << endl;

    cout << "o1's Protected1: " << o1.getProtected1() << endl;   // = 10
    cout << "o1's Private1: " << o1.getPrivate1() << endl;   // = 20
    o1.displayTotal();   //private1<10> + protected1<20>
    cout << endl;
  //system("PAUSE");
    cout << "o2's Protected1: " << o2.getProtected1() << endl; // 30
    cout << "o2's Private1: " << o2.getPrivate1() << endl;  // 40
    cout << "o2's Private2: " << o2.getPrivate2() << endl; //50
    cout << "o2's Public1: " << o2.public1 << endl;     // public data remains public
    o2.displayTotal();  //protected1<30> + private1<40> + private2<50>
    cout << endl;

    o2.setPrivate1(60);
    o2.setPrivate2(70);
    o2.setProtected1(80);
    cout << "o2's Protected1: " << o2.getProtected1() << endl;  // 80
    cout << "o2's Private1: " << o2.getPrivate1() << endl;   // 60
    cout << "o2's Private2: " << o2.getPrivate2() << endl;  //70
    o2.displayTotal();  //protected1<60> + private1<70> + private2<80>

    cout << endl;

    return 0;
}
