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

    Test test1 = getTest();

    cout << test1 <<endl;

    vector<Test> vec;
    // This will call the move constructor.
    vec.push_back(Test()); 

    return 0;
}