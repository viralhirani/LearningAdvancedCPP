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
public:
    iterator begin()
    {
        return iterator(0,*this);
    }
    iterator end()
    {
        return iterator(m_size,*this);
    }
};
template<typename T>
class ring<T>::iterator // we need to pass template to base ring, not to iterator. iterator can still use ring template.
{
private:
    int m_pos;
    ring& m_ring;
public:
    iterator(int pos, ring& aRing): m_pos(pos), m_ring(aRing)
    {

    }
    // pre-increament
    iterator& operator++(int) {
        m_pos++;
        return *this;
    }
    //post increament
    iterator& operator++() {
        m_pos++;
        return *this;
    }
    T& operator*() {
        return m_ring.get(m_pos);
    }
    bool operator!=(const iterator& other) const
    {
        return (m_pos != other.m_pos);
    }

};

#endif // RING_H_