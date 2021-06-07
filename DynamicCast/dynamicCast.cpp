#include<iostream>
using namespace std;
class Parent
{
public:
    virtual void speak()
    {
        cout << "Parent!"<<endl;
    }
};

class Brother : public Parent
{

};

class Sister : public Parent
{

};

int main()
{
    Parent parent;
    Brother brother;

    Parent *ppb = &brother; // Here ppb can point to brother or parent.

    // If we use static cast[it's compile time casting], it will cast the ppb to pbb without any checks. that will be issue if ppb is pointing to parent.
    // but if we use dynamic_cast [which is run time casting], it will check the ppb type run time and it will cast only if it's poining to valid object.
    // if it's poinint to parent in this case, it will return nullptr. 
    // And it will cast successfully if ppb is pointing to brother object.
    Brother *pbb = dynamic_cast<Brother *>(ppb);

    if(pbb == nullptr) {
        cout << "Invalid cast"<<endl;
    }
    else {
        cout << pbb <<endl;
    }
    return 0;
}