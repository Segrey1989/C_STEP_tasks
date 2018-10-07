/*
 Реализовать класс "Стек" (Stek) на основе динамического массива состоящий из следующих данных:
 int* data;
 int size;
 int top;
 Реализовать методы конструкторы: без параметров, explicit конструктор с параметрами, конструктор копирования.
 Реализовать методы pop(), push(), is_full(), is_empty().

 */

#include <iostream>

class Steck{
    int *data;
    int size;
    int top;
    
    bool is_full()const;
    bool is_empty()const;
public:
    Steck():data(nullptr), size(0), top(0){}// без параметров
    
   explicit Steck(int _size):data(nullptr), size(_size), top(0){
        data = new int[size];
    } // с параметрами
    
    Steck(const Steck &stk); // копирования
    ~Steck(){delete[]data; } // деструктор
    
    Steck & operator = (const Steck &other); // операция присваивания
    
    int Get_size(){return size;};
    int Get_top(){return top;};
    
    void push(int val);
    int pop();
    
};
