/*
 Создать базовый класс Array, в котором определите поле-массив подходящего типа и поле для хранения количества элементов у текущего объекта-массива. Максимально возможный размер массива задается статической константой. Реализуйте конструктор инициализации, задающий количество элементов и начальное значение (по умолчанию 0). Реализуйте методы доступа к отдельному элементу, перегрузив операцию индексирования[]. При этом должна выполнятся проверка индекса на допустимость.
 В классе Array реализовать операцию поэлементного сложения массивов.
 
 Реализовать производный класс Polinom для работы с многочленами до 100-й степени. Коэффициенты представлены массивом.  Младшая степень имеет меньший индекс. Реализовать арифметические операции и операции сравнения, вычисление значения полинома для заданного значения x.
 Операция поэлементного сложения наследуется из базового класса.
 Протестировать корректную работу объектов обоих классов.

 */

#pragma once
#include <iostream>

class Array
{
    static const size_t max_size = 100;
    int data[max_size];
    size_t size;
public:
    Array(): size(0){ }
    Array(size_t _size, int value = 0):size(_size)
    {
        if (_size > max_size)
        {
            std::cout << "Size is bigger than max_size\n";
            exit(1);
        }
        for (int i = 0; i < size; i++)
        {
            this->data[i] = value;
        }
    }
    const int& operator[](size_t)const;
    int& operator[](size_t);
    const Array operator+(const Array&)const;
    
    size_t get_size()const {return size;}
    void set_size(size_t _size){this->size = _size;}
    
    friend std::ostream& operator<<(std::ostream&, const Array&);
};

const int& Array::operator[](size_t index) const
{
    if (index > size)
    {
        std::cout << "Index is out of range\n";
        exit(1);
    }
    return data[index];
}

int& Array::operator[](size_t index)
{
    if (index > size)
    {
        std::cout << "Index is out of range\n";
        exit(1);
    }
    return data[index];
}

const Array Array::operator+(const Array&A)const
{
    size_t new_size;
    if (this->size > A.size) new_size = this->size;
    else new_size = A.size;
    Array result(new_size);
    for (int i = 0; i < this->size; i++)
    {
        result[i] = this->data[i];
    }
    
    for (int i = 0; i < A.size; i++)
    {
        result[i] += A.data[i];
    }
    
    return result;
}

std::ostream& operator<<(std::ostream& out, const Array&A)
{
    for (int i = 0; i < A.size; i++)
    {
        out << A.data[i] << ' ';
    }
    out << '\n';
    return out;
}

