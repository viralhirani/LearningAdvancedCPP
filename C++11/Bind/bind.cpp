#include<iostream>
#include<functional> // we need to include functional header to use bind

using namespace std; // bind is in std namespace
using namespace placeholders; 

int add (int a, int b, int c)
{
    cout << a << " , "<< b << " ,"<< c<< endl;
    return a+b+c;
}

int run(function<int(int,int)> func)
{
    return func(7, 8); // this will pass two args and one default 100
}

// we can use bind with method.
class Test
{
public:
    int add1 (int a, int b, int c)
    {
        cout << a << " , "<< b << " ,"<< c<< endl;
        return a+b+c;
    }
};

int main()
{
    // create auto calculator and use bind - first arg is function pointer and then arguments.
    auto calculator = bind(add, 4, 2, 5);
    // calculator will always call with provided arg.
    cout << calculator() <<endl;

    // if we have functional headers and namespace placeholders, we can use placeholder.
    // where we can suply arguments 
    // 1,2,3 are the argument number.
    auto calculator1 = bind(add, _1, _2, _3);

    cout << calculator1(10,20,30) <<endl;

    auto calculator2 = bind(add, _3, _2, _1);
    cout << calculator2(10,20,30) <<endl; // it will pass ass 30,20,10

    // we can use hardcoded arguments or placeholders.
    auto calculator3 = bind(add, _2, 100, _1);
    cout << calculator3(10,20) <<endl; //it will pass 10,20,100

    // we can pass this to function as arg.
    cout << run(calculator3) <<endl;

    // we can bind with class methods
    Test test; // we need to provide an object to bind.
    auto calculator4 = bind(&Test::add1,test, 4, 2, 5);
    cout << calculator4() <<endl;

    return 0;

}