#ifndef RING_H_
#define RING_H_
#include<iostream>
using namespace std;

template<typename T>
class ring
{
private:
    size_t m_size;
    size_t m_pos;
    T *m_value;
public:
    class iterator;

public:
    ring(size_t size) : m_size(size), m_pos(0), m_value(NULL)
    {
        m_value = new T [size];
    }
    ~ring()
    {
        delete [] m_value;
    }
    void add(T value)
    {
        m_value[m_pos++] = value;
        if(m_pos == m_size) {
            m_pos = 0;
        }
    }
    T& get(size_t pos)
    {
        return m_value[pos];
    }
    size_t size()
    {
        return m_size;
    }
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