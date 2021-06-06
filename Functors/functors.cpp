#include<iostream>
using namespace std;

// functors are another way of passing function pointers
struct matchTest {
    bool operator()(string& text)
    {
        return text == "lion";
    }
};

// we can use the polymorphysm and use functors more effectively
struct Test { // abstract lass
    virtual bool operator()(string& text)=0;
};
// like this example we can have different tests and derive form Test
// we can have private variables and states with functors. we can't do that with function pointers.
struct matchTest1 : public Test {
    virtual bool operator()(string& text)
    {
        return text == "lion";
    }
};

// use the matchTest and pass to any functions
void check(string text, Test& test) // use reference here to use polymorphism
{
    if(test(text)) {
        cout<< "Text matches!"<<endl;
    }
    else {
        cout<< "No match."<<endl;
    }
}

int main()
{
    string value = "lion";

    matchTest pred;
    // This is very complecated way of checking this.
    // but we can pass this predicate to any function.
    cout<< pred(value)<<endl;

    matchTest1 m;

    check(value,m);

    return 0;
}