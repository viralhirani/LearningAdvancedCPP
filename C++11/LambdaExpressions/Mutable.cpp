#include<iostream>
using namespace std;

int main()
{
    int cats = 5;
    // Lambda exp to capture local variable 'cats' by value and print.
    // Here since we are capturing 'cats' by value it will not allow us to assigne value inside lambda 
    // add the mutable keyword after the round bracket, this will make lambda mutable and will allow to modify variable to modify within lambda
    // 
    [cats] () mutable { 
        cats = 4; // is not allowd without mutable 
        cout << cats <<endl;
    }();
    // The 'cats' variable was captured by value in lambda, so any modification in mutable lambda is local to lambda.
    // mutable lambda modification doesn't reflact to the  variable, since variable was captured by value.
    cout << cats << endl;
    return 0;
}