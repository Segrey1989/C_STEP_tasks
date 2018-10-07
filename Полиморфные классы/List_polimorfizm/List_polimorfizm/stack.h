#pragma once
#include "d_array.h"

class Stack : public Array
{
private:
    int top;
public:
    Stack():Array(), top(0)
    {
    }

    virtual void push(int);
    virtual int pop();
    virtual void print(std::ostream &);
};

void Stack::push(int var)
{
    if (top==get_size())
    {
        give_mem(top);
    }
    (*this)[top] = var;
    ++top;
}

void Stack::print(std::ostream & out)
{
    for (int i = 0; i < top; i++)
    {
        out << (*this)[i] << ' ';
    }
    out << '\n';
}

int Stack::pop()
{
    if (!top)
    {
        std::cout << "Stack is empty\n";
        exit(1);
    }
    int result = (*this)[top-1];
    top--;
    return result;
}
