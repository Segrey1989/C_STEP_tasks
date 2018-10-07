#pragma once
#include "d_array.h"

class Fifo : public Array
{
    size_t head;
    size_t tail;
public:
    Fifo():Array(), head(0), tail(0){}
    /*~Fifo()
     {
     Array::~Array();
     }*/
    virtual void push(int);
    virtual int pop();
    virtual void print(std::ostream &);
};

void Fifo::push(int elem)
{
    if (tail == this->get_size())
    {
        give_mem(tail);
    }
    (*this)[tail] = elem;
    ++tail;
}

int Fifo::pop()
{
    if (tail==head)
    {
        std::cout << "Queue is empty\n";
        exit(1);
    }
    int result = (*this)[head];
    
    for (int i=1; i<tail; i++)
    {
        (*this)[i - 1] = (*this)[i];
    }
    --tail;
    return result;
}

void Fifo::print(std::ostream &out)
{
    for (int i = 0; i < tail; i++)
    {
        out << (*this)[i] << ' ';
    }
    out << '\n';
}
