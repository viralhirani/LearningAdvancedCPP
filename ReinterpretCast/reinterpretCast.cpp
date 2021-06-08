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
    Sister sister;

    Parent *ppb = &brother; // Here ppb can point to brother or parent.

    // This will cast the ppb which is pointing to brother to psb which is sister class pointer.
    // This doesn't make sense in most of the situation, but static_cast will just cast it anyway.
    // Sister *psb = static_cast<Sister *>(ppb);

    // This will cast the ppb which is pointing to brother to psb which is sister class pointer.
    // This doesn't make sense in most of the situation,  dynamic_cast will not cast it and will return nullptr.
    // Sister *psb = dynamic_cast<Sister *>(ppb);

    // This will cast the ppb which is pointing to brother to psb which is sister class pointer.
    // This doesn't make sense in most of the situation.
    // reinterpret_cast is completely off the wall cast. it's got even less checking on it than static_cast.
    // it letarally does the binary cast for pointer. so it casts anything to anything.
    Sister *psb = reinterpret_cast<Sister *>(ppb);

    if(psb == nullptr) {
        cout << "Invalid cast"<<endl;
    }
    else {
        cout << psb <<endl;
    }
    return 0;
}