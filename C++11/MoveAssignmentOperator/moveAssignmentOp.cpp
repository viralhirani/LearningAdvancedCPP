#include<iostream>
#include<vector>
using namespace std;

class Test
{
private:
    int *_pBuffer{nullptr};
    const static int SIZE = 10;
public:
    Test()
    {
        _pBuffer = new int[SIZE]{}; // {} at the end will initialize all the elements with 0;
    }
    Test(int i)
    {
        _pBuffer = new int[SIZE]{}; // {} at the end will initialize all the elements with 0;

        for (int k =0; k < SIZE; k++) {
            _pBuffer[k] = 7 * i;
        }
    }
    Test(const Test &other)
    {
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer,other._pBuffer,SIZE*sizeof(int));
    }
    // move constructor
    // We need to use mutable rValue reference here because we are modifiying other
    Test(Test &&other)
    {
        cout<<"Move constructor"<<endl;
        // rValue has already allocated memory and we are stealing that here.
        _pBuffer = other._pBuffer;
        // After stealing we need to assigne pointer with nullptr. otherwise destructor will deallocate the memory and we will have issue.
        other._pBuffer = nullptr;
    }
    Test &operator=(const Test &other)
    {
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer,other._pBuffer,SIZE*sizeof(int));
        return *this;
    }
    // Move Assignment operator
    // Same as move constructor, We need to use mutable rValue reference here because we are modifiying other
    Test &operator=(Test &&other)
    {
        cout<<"Move Assignment Operator"<<endl;
        // assignment operator is used on already constructed object. so we need to free memory first.
        delete [] _pBuffer;
        // rValue has already allocated memory and we are stealing that here.
        _pBuffer = other._pBuffer;
        // After stealing we need to assigne pointer with nullptr. otherwise destructor will deallocate the memory and we will have issue.
        other._pBuffer = nullptr;
        return *this;
    }
    ~Test()
    {
        delete [] _pBuffer;
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

// REMEMBER: Rule of 3: If you are implementing assignment operator you need copy constructor and destructor.
// and now also move constructor and move assignment operator.

// If you are not using dynamic memory allocation then you can use default constructors and assignment operator.

    vector<Test> vec;
    // This will call the move constructor.
    vec.push_back(Test()); 

    // This will call move assignment operator
    Test test1;
    test1 = getTest();
// This will also call move assignment operator
    test1 = Test();

    return 0;
}