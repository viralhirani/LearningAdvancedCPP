// implement the own ranged loop.
#include<iostream>
#include"ring.h"

using namespace std;


int main()
{

    ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    //textring.add("four");

// This is standerd for loop
/*     for (int i = 0; i<textring.size(); ++i) {
        cout << textring.get(i) <<endl;
    } */

// To make class iterable, we need to implement iterator for it.
// if we provide iterator it will work with with range based for loop as well.
// c++98 style
    for (ring<string>::iterator it = textring.begin(); it != textring.end(); it++) {
        cout << *it <<endl;
    }
    cout<<endl;
    // if we make the implement the iterator and make above sytext work, range based loop also will work.
// c++11 style
    for (auto value : textring) {
        cout <<value<<endl;
    }


    return 0;
}