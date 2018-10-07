/*
 Реализовать класс "Множество из элементов- символов" (Set) состоящий из следующих данных:
 - указатель на тип char;
 - количество элементов в данном множестве не более 256.
 
 Определить и реализовать в классе конструкторы,  деструктор, перегрузить   операцию присваивания и  методы чтения и вывода на консоль.
 Дополнить определение класса заданными перегруженными операциями  пересечение, объединение, разность, включение, эквивалентность )  .
 Реализовать эти операции. Выполнить тестирование.
 
 */


#include <iostream>
#include <cstring>


class Set{
    size_t size;
    char *data;
    bool check(char val)const;
public:
    Set();
    Set(const char* str);
    Set(size_t _size);
    Set(const Set &obj);
    ~Set(){delete[]data;};
    Set & operator=(const Set &obj);
    Set & operator=(const char *str);
   
    friend std::ostream &operator<<(std::ostream &out, const Set &obj);
    friend std::istream &operator>>(std::istream &in, Set &obj);
    
    const Set operator*(const Set &obj)const;
    const Set operator+(const Set &obj)const;
    const Set operator-(const Set &obj)const;
    
    bool operator<(const Set obj)const;
    bool operator==(const Set obj)const;
};

