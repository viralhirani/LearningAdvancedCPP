#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // c++11 generalizes the usage of {}. we can uses this with everything for initialization.
    int value{5}; // initializing int with value 5;
    cout << value << endl;

    string text{"Hello"}; // initializing string
    cout << text <<endl;

    int numbers[]{1, 3, 6}; // Initializing array
    cout << numbers[1] <<endl;

    int *pInts = new int[3]{1, 2, 3}; // using initializer list with new. here we have to specify memory alocation size 
    cout << pInts[2] <<endl;

    int value1{};// this initializes the value1 with 0
    cout <<value1<<endl;

    // NULL is a macro in c++, it's not a keyword. if we add any header it will pull the macro from somewhere.
    // in c++11 whave have nullptr type which is the keyword. this can be used to initialize the pointer

    int *pSomething{}; // equivalent to int *pSomething = nullptr;
    cout<<pSomething<<endl;

    int numbers1[5]{}; // this initialises the array elements with 0. here we need to specify array length.
    cout << numbers1[2] <<endl;

    struct {
        int value;
        string text;
    }s1{5,"Hi"}; // we can use this with class or struct also.
    cout << s1.text<<endl; // here text is public by default.

    vector<string> strings{"one","two","three"}; // we can use it with STL. this is using initialiser list implementation internally.
    cout << strings[2] <<endl;

    return 0;
}