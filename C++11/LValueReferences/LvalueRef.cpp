#include<iostream>
using namespace std;

class Test
{
private:
    int *_pBuffter;
    const static int SIZE = 10;
public:
    Test()
    {
        cout << "Default Constructor" << endl;
        _pBuffter = new int[SIZE]{}; // {} at the end will initialize all the elements with 0;
    }
    Test(int i)
    {
        cout << "Parameterized Constructor" << endl;
        _pBuffter = new int[SIZE]{}; // {} at the end will initialize all the elements with 0;

        for (int k =0; k < SIZE; k++) {
            _pBuffter[k] = 7 * i;
        }
    }
    Test(const Test &other)
    {
        cout <<"Copy constructor"<<endl;
        _pBuffter = new int[SIZE]{};
        memcpy(_pBuffter,other._pBuffter,SIZE*sizeof(int));
    }
    Test &operator=(const Test &other)
    {
        cout <<"Assignement operator"<<endl;
        _pBuffter = new int[SIZE]{};
        memcpy(_pBuffter,other._pBuffter,SIZE*sizeof(int));
        return *this;
    }
    ~Test()
    {
        cout<<"Destructor"<<endl;
        delete [] _pBuffter;
    }

    friend ostream & operator<<(ostream &out, const Test &test);

};

ostream& operator<<(ostream &out, const Test &test)
{
    out<<"Hello from test";
    return out;
}

Test getTest()
{
    return Test();
}
int main()
{
    Test test1 = getTest();

    cout << test1 <<endl;

    // lValue reference is the normal references. we call it lValue references because in c++11 we have rValue references.
    // this is normal reference, we can bind that to lvalue. lValues are the values which are addressible.
    Test &rTest = test1; // this is valid lvalue ref. 

    // if we try to bind lValue ref to rValue we cannot do it.
    // we cannot do this, eventhough getTest() return type is Test object, it's not addressable so it's rValue and we cannot have reference it it.
    // REMEMBER: return values of any functions are rValues. They are temp values, they don't have name and we can't take address of it.
    // Test &rTest2 = getTest(); 

    // we can make it work if we make lValue ref const. like below. this will extent the scope and life time of the retern value.
    const Test &rTest2 = getTest(); // we need to keep const here and create ref to rvalue.

    //similarly the same thing is happening with Copy constructor copy constructor caputures const Test &obj.
    // so we can pass the rvalue to it.

    Test test2(Test(1)); // here we are passing Test() directly which is rvalue. but copy constructor will be able to create ref to it.

    return 0;
}