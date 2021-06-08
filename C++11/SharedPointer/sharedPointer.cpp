#include<iostream>
#include<memory>// include this for smart pointer.
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Created"<<endl;
    }
    void greet()
    {
        cout << "Hello"<< endl;
    }
    ~Test()
    {
        cout<<"Destroyed"<< endl;
    }
};

int main()
{
    // one way is to create shared pointer is the same way as we created unique pointer
   // shared_ptr<Test> pTest1(new Test);

    shared_ptr<Test> pTest3 = nullptr;
{
    // The best way to shared pointer is to use make_shared macro. this is more efficient than using new
    shared_ptr<Test> pTest2 = make_shared<Test>(); // we dont have to use new here.
    pTest3 = pTest2;
} // this will make shared pointer go out of scope only after the last usage goes out of scope

    cout << "Finished"<< endl;
    return 0;
}