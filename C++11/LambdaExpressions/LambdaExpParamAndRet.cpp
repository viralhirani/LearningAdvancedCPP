#include<iostream>
using namespace std;

void testGreet(void (*greet)(string)) // parameter type for function pointer
{
    greet("Bob");
}
// function which calls the pDevide
void  runDevide(double (*devide)(double, double)) // funtion ptr with return type.
{
    cout << devide(20.0,2.0)<<endl;
}
int main()
{
    // lambda exp which take parameters.
    // in round bracket we can put comma saperated list of parameters like function.
    auto pGreet = [](string value){cout<<"Hello " <<value<<endl;};
    pGreet("Viral");

    // create a function and pass the lambda exp
    testGreet(pGreet);

    // lambda exp with return type.
    // C++11 can infer the return type for lambda exp. there is no need to specify return type for a lambda exp.
    auto pDivide = [](double a, double b){
        return a/b;
    };
    cout << pDivide(10.0,5.0)<<endl;
    // this works fine if we have return type with only single return type. C++ can't handle if we have return with different type.
    /*auto pDivide1 = [](double a, double b){
        if(b == 0.0) {
            return 0; // this returns int so it wouldn't work.
        }
        return a/b;
    };*/
    // specify the return type using trailing return type syntex -> double 
    auto pDivide1 = [](double a, double b) -> double {
        if(b == 0.0) {
            return 0; // now this works. this will typecast the return type to double.
        }
        return a/b;
    };
    cout << pDivide1(10.0,0)<<endl;

    // pass lambda to function
    runDevide(pDivide1);
    return 0;
}