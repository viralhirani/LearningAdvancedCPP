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

// When you have unique_ptr as member variable. it's destroyed automatically when class objec goes out of scope
// Becasue when object goes out of scope it's member variable also goes out of scope.

class Temp
{
private:
    unique_ptr<Test> pTest;
public:
    Temp(): pTest(new Test) {}
};

int main()
{
    unique_ptr<int> pInt(new int); // this creates unique pointer to int.
    *pInt = 7; // we can use this pointer as norman pointer.
    {
        // pointer will be cleaned up once it goes out of scope.
        unique_ptr<Test> pTest(new Test); // this creates unique pointer to int.
        pTest->greet();
    }

    // we can use it with array also.
    {
        // pointer will be cleaned up once it goes out of scope.
        // Here it will clear out all the pointers 
        unique_ptr<Test[]> pTestA(new Test[2]); // this creates unique pointer to int.
        pTestA[1].greet();
    }

    {
        cout<< "started temp"<< endl;
        Temp temp;
    }
    cout << "Finished"<< endl;
    return 0;
}