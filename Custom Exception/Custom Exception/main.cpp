//
//  main.cpp
//  Custom Exception
//
//  Created by Viral on 05/05/21.
//

#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Something bad happend";
    }
};
class MyClass
{
public:
    void goesBad()
    {
        throw MyException();
    }
};

int main(int argc, const char * argv[]) {
    MyClass obj;
    try{
        obj.goesBad();
    }
    catch(MyException& e){
        cout<<e.what()<<endl;
    }
    return 0;
}
