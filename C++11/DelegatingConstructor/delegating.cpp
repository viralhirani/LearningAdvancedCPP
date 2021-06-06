#include<iostream>
using namespace std;

// in c++11 we have delegating constructor.
// we can call constructor from an constructor.
// Earlier in c++98 we couldn't do that.
// So we used to create intitialize() method and call from different constructor.s
class Test {
    int dogs{5};
    string text{"Hello"};
public:
    Test() : Test("Hello") // Here non parameterized constructor is calling parametarized constructor first. 
    {
        cout<< "No Parameter constructor"<<endl;
    }
    // We shouldn't try to call non param constructor from here, that will result into infinite recursion.
    Test(string text) 
    {
        cout << "String constructor"<<endl;
    }
};
int main()
{
    Test obj1;
    Test obj2("Hi");
    return 0;
}