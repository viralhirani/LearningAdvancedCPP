#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    double value;
    // typid returns the type name of variable. this is supported in c++98
    cout << typeid(value).name()<<endl;
    // c++11 added decltype
    // decltype allows us to declare other variable with the same type

    decltype(value) age = 34;
    cout << age <<endl;
    return 0;
}