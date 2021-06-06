#ifndef RING_H_
#define RING_H_
#include<iostream>
using namespace std;

template<typename T>
class ring
{
public:
    class iterator;
};
template<typename T>
class ring<T>::iterator // we need to pass template to base ring, not to iterator. iterator can still use ring template.
{
public:
    void print()
    {
        cout<<"I am iterator: "<< T()<<endl; // T() calls constructor of type T
    }
};

#endif // RING_H_