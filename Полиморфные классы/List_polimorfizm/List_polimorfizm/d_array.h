#pragma once
#include<iostream>

class Array
{
    int mySize;
    int *myData;
public:
    Array():mySize(0), myData(nullptr){}
    explicit Array(int size);//конструктор (задача правильно проинициализировать объект класса)
   
    void set(int i, int val);        //заносить в массив
    int & operator[](int i);               //перегрузка индексирования
    const int & operator[](int i)const;    //перегрузка индексирования
    int get_size()const;                   //получить размер
    Array(const Array &a);                 //конструктор копирования
    Array & operator = (Array & a);
    void give_mem(int);
    
    virtual ~Array();
    virtual void print(std::ostream &) = 0;
    virtual void push(int) = 0;
    virtual int pop() = 0;
};

Array::Array(int size):mySize(size), myData(new int[mySize]){}

Array:: ~Array()
{
    std::cout << "destr\n" ;
    delete[] myData;
}

void Array::give_mem(int size)
{
    if (size == mySize)
    {
        int * ptr;
        ptr = new int[size * 2 + 1];
        for (size_t i = 0; i < size; ++i)
        {
            ptr[i] = myData[i];
        }
        delete[] myData;
        myData = ptr;
        mySize = mySize * 2 + 1;
    }
}


void Array::set(int i, int val)
{
    if (i<0 || i>(mySize - 1))
        return;
    myData[i] = val;
}


int & Array::operator[](int i)
{
    if ((i<0 || i>(mySize-1)) && mySize)
    {
       std::cout << "error index /n";
       exit(1);
    }
    
    return myData[i];
}
const int & Array::operator[](int i)const
{
    if ((i<0 || i>(mySize - 1)) && mySize)
    {
       std::cout << "error index /n";
       exit(1);
    }
    return myData[i];
}


int Array::get_size()const
{
    return mySize;
}


Array::Array(const Array & a)
{
    mySize = a.mySize;
    myData = new int[mySize];
    for (int i = 0; i< mySize; i++)
        myData[i] = a.myData[i];
}


Array& Array :: operator = (Array & a)
{
    if (this != &a)
    {
        mySize = a.mySize;
        delete[] myData;
        myData = new int[mySize];
        for (int i = 0; i<mySize; i++)
            myData[i] = a.myData[i];
    }
    return *this;
}

std::ostream & operator<<(std::ostream & out, const Array & a)
{
    for (size_t i = 0; i < a.get_size(); i++)
    {
        out << a[i] << " ";
    }
    out << std::endl;
    return out;
}
