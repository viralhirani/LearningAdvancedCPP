#include<iostream>
using namespace std;

class Test
{

};


// This function will call check.
// T &&arg will be rValue/lValue based on passing value.
template<typename T>
void call(T &&arg)
{
    // this is not perfect forwarding.
    //check(arg); // this will pass 'arg' as lvalue, so it will call the lvalue check.
    // we can fix that with static cast.
    // so here if we pass rvalue T will be rvalue type. if we pass lvalue, there will be reference collapsed rule and T will be lvalue ref type.
   // check(static_cast<T>(arg));
    // C++11 has forward, which does the same thing. 
    check(forward<T>(arg));
}

void check(Test &test)
{
    cout << "lValue"<< endl;
}

void check(Test &&test)
{
    cout << "rValue"<< endl;
}

int main()
{
    Test test;
    // This is find. t is rValue reference and Test() is rValue.
    // auto &&t = Test();
    // test is lvalue and t is rValue ref. But still it works.
    // if auto is boiled down to lvalue than the reference will collapse and t will be lvalue ref.
    // this is reference collapsing rule.
    auto &&t = test;

    call(Test());

    call(test);

    return 0;
}