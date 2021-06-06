#include<iostream>
#include<vector>
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

// function capture lValue
void check(const Test &value)
{
    cout<<"lValue Function!"<<endl;
}

// rValue function
void check(Test &&value) // no need be be const. some time it uses function resources and can't be const.
{
    cout<<"rValue Function!"<<endl;
}

// function with lvalue int ref
void print(int &value)
{
    cout<< "lValue Function: "<< value<<endl;
}
// function with rValue int ref
void print(int &&value)
{
    cout<< "rValue Function: "<< value<<endl;
}
int main()
{
    // anything for which we can take address is Lvalue, and we can't take address is Rvalue.
    int value1 = 7; // here value1 is Lvalue and 7 is Rvalue.
    int *pValue1 = &value1; // this is valid.
    //int *pValue2 = &7;// this is not valid.

    int *pValue3 = &++value1; // this is valid because pre-fix increament is valid Lvalue.
    cout<<*pValue3<<endl;
    //int *pValue4 = &value1++; // this isn't valid.

    // int *s = &(7+value1); // this isn't valid.

    Test test1 = getTest();

    cout << test1 <<endl;

    vector<Test> vec;
    vec.push_back(Test()); // here we are passing temp value to a function.

    // rValue ref will help us to handle temp values like non-temp values and optimize our code.

    Test &lTest1 = test1; // lValue ref. pointing to lValue

    //rValue reference
    // rValue ref are defained with && - this is not address of address but the rValue reference.
    //Test &&rTest1 = test1; // we cannot do this. Test &&rtest1 is rValue ref we cannot bind that to lValue - test1.
    // but what we can do is to bind rValue ref to rValue.

    Test &&rTest2 = getTest();
    //or
    Test &&rTest3 = Test();

    check(test1); // this will call lValue function
    check(getTest()); // this will call fucntion with rValue ref.
    check(Test()); // this will call fucntion with rValue ref.

    // Tutorial:
    int i = 10;
    print(i); // calls lValue ref function
    print(11); // calls rValue ref function.
    print(++i); // calls lValue ref function and passes 11 post increament.
    int j = 10;
    print(j++);// Calls rValue ref function and passes j = 10 and increament later.

    // this will be use rValue/lValue ref in move constructors and move assignment operators. which is going to be really useful and lot more efficent than copy constructor.
    return 0;
}