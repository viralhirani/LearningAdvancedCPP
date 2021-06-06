#include<iostream>
#include<typeinfo>
using namespace std;

/*
auto test() { // this doesn't work as auto needs more information to identify return type
    return 7;
}*/

auto test() -> int // c++11 provides trailing return type, we can use with auto to identify return type.
{ // this will be more usefull with template
    return 7;
}

template<typename T>
auto test1(T value) -> decltype(value) // use decltype to identify the value type.
{
    return value;
}

// using decltype with function return type and auto
int get()
{
    return 999;
}
auto test2() -> decltype(get()) // use decltype with auto to determine return type 
{
    return get();
}
/*
class test3
{
int a;
test()
{
    a = 10;
}
static int print() {
    return get();
}
private:
    int get() { return a;}
};
*/
int main()
{
    auto value = 7;
    cout << value <<endl;
    cout<<typeid(value).name()<<endl;

    auto text = "Hello";

    cout << text <<endl;

    cout<< test() <<endl;

    cout<< test1("Viral")<<endl;

    cout << test2()<<endl;

    return 0;
}