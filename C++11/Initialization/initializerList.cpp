#include<iostream>
#include<vector>
#include<initializer_list> // header needed if we use initializer list implementation.
using namespace std;

class Test
{
public:
    Test(initializer_list<string> texts) // this gets all values with initializer list.
    {
        for(auto text:texts) { // initializer list has iterator implementation so we can use raged based loop.
            cout <<text<<endl;
        }
    }
    void print(initializer_list<string> texts) // initializer list works with functions also
    {
        for(auto text:texts) {
            cout <<text<<endl;
        }
    }
};
int main()
{
    Test test{"apple","orage","banana"}; // this is uses constructor with initializer list implementation.

    // initializer list works with functions also
    // this passes whole list without creating array.
    test.print({"one", "two", "three"});
    return 0;
}