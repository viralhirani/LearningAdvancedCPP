#include<iostream>
using namespace std;
class Test
{
int one{1};
int two{2};
public:
    void run()
    {
        int three{3};
        int four{4};
        // we can capute three and four with capute list because they are local variable.
        // we can NOT use [one] to capute the instance member variable. But we can pass 'this' so member variables are accessible.
        // we can use [this, three, four], this will caputre all instance variable by reference.
        // since we caputred 'this' all member variables are accessible by reference and any modification can ulter the value.
        // We can put 'this' in any sequence e.g. [three, this, four] is valid.
        // If we caputre all local variable by value, than it won't allow to capture 'this'. e.g [=, this] is not valid.
        // If we capute local variable by ref, it will allow to capute 'this'. e.g. [&, this] is valid.
        auto pLambda = [this, three, four](){
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };
        pLambda();
    }
};

int main()
{
    Test test;
    test.run();



    return 0;
}