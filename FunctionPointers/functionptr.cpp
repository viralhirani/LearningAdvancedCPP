#include<iostream>
using namespace std;

void test()
{
    cout << "Hello" <<endl;
}

void test1()
{
    cout << "Hello test1" <<endl;
}

void test2(int value)
{
    cout << "Hello: " <<value<<endl;
}

int main()
{
    test();

    void (*pTest)();

    pTest=test; // works with our without & on test
    pTest(); // works as (*pTest)()

    void (*pTest1)() = test1; // function pointer initialization.

    pTest1(); // calls test1()

    pTest1=test;

    pTest1(); // calls test()

    // Function ptr with argument

    void (*pTest2)(int) = test2;
    pTest2(7);
    return 0;
}