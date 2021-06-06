#include<iostream>
#include<vector>
using namespace std;

class Test
{
    int id{21}; // this will initializer all the object with the value provided.
    string name{"Viral"};
public:

    // we can add constructor with initializer list which will override the member variable initialized values.
    Test(int id_): id(id_) {} // this will override the id value with newlly provided value.
    // once we have paramatarised contructor we loose default constructor
    Test() = default; // we can add default constructor by = default 
    Test(const Test& other) = delete; // similarly if we dont want to allow copy, we can use = delete to delete the copy constructor.
    Test& operator=(const Test& other) = default; // this will add default assignement operator.
    void print()
    {
        cout<< name << " : " << id <<endl;
    }
};

int main()
{
    Test test1;
    test1.print(); // this will print the default values initialized in class.

    Test test2(18); // this will override the initialized value with provided value.
    test2.print();

    // this will not work since we have deleted the  copy constructor.
    // Test test3 = test1;

    // this will invoke assignment operator and will work fine.
    test2=test1;
    test2.print();



    return 0;
}