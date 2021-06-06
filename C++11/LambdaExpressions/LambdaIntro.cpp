#include<iostream>
#include<vector>
using namespace std;

// we can pass the lambda exp to a function and catch to function pointer.
void test(void (*pFunc)()) // pFunc is the function pointer - return type void and doesn't take any arguments.
{
    pFunc();

}

int main()
{
    // Lambda expression start with square brackets []
    // Lambda expression looks like a bracket party!!
    // general syntex is
    // [](){}; // this is valid expression but we are not doing anything
    //{} is block where we write code
    // [](){cout << "Hello" <<endl;}; // this is valid expression but we are not running this code yet.
    // if we look close, above expression looks like a function defination. instead of return time and function name we have [].

    // we can store the lambda expression to a auto variable and call.
    auto func = [](){cout << "Hello" <<endl;}; // return type depends on lambda exp. better to use auto with lambda to avoid issues.
    func();// this will call the lambda expression.

    // we can pass the lambda exp. to a function and catch to a function pointer.
    test(func);

    // we can directly pass the lambda exp to a function.
    test([](){cout << "Hello again!" <<endl;});

    return 0;
}