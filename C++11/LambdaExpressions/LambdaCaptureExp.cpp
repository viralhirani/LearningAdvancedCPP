#include<iostream>
using namespace std;

int main()
{
    int one = 1, two = 2, three = 3;

    // Capture one and two variable by value.
    [one,two](){cout<<one<<", "<<two<<endl;}();// adding () at the end will call lambda exp.

    // Capture all local variable to labmda exp.
    [=](){cout<<one<<", "<<two<<endl;}(); 

    // Default capture all local variables by value but three by reference.
    [=,&three](){three=7; cout<<one<<", "<<two<<endl;}();
    cout<<three<<endl; // variable three was passed by ref so it's value should be changed.

    // Default caputre all local variables by reference.
    [&](){three=7; two = 8; cout<<one<<", "<<two<<endl;}();
    cout<<two<<endl;

    // Default capture all local variables by ref, but two and three by value.
    [&, two, three](){one = 9; cout<<one<<", "<<two<<endl;}();
    cout<< one << endl;

    return 0;
}