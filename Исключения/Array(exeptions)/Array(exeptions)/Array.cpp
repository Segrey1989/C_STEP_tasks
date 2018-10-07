/*
 Создать базовый класс Array, в котором определите поле-массив типа unsigned char и поле для хранения количества элементов у текущего объекта-массива. Максимально возможный размер массива задается статической константой. Реализуйте конструктор инициализации, задающий количество элементов и начальное значение (по умолчанию 0). Реализуйте методы доступа к отдельному элементу, перегрузив операцию индексирования[].При этом должна выполнятся проверка индекса на допустимость. В конструкторе и перегруженной операции [] обработку исключений. Исключения реализовать, как наследники от стандартных исключений.
 В классе Array реализовать перегруженную операцию поэлементного сложения массивов.
 
 Реализовать производный класс  Octal для работы  с без знаковыми целыми восьмеричными числами. Используя для представления числа массив типа unsigned char, каждый элемент которого является восьмеричной цифрой.
 */
#pragma once
#include "Header.h"

class Array{
protected:
    static const size_t max_size = 100;
    size_t cur_size;
    unsigned char *data;

public:

    // исключения
        class IndexError: public exception{
        public:
             size_t ind;
            IndexError(size_t val): ind(val){}
            virtual const char* what()const throw(){
                return "Wrong index : ";
            }
    
        };
    
    class  ErrorMax: public exception{
    public:
        ErrorMax(){}
        virtual const char* what()const throw(){
            return "Error: cur_size > max_size\n";
        }
    };

    //конструктор
    Array(size_t _size, unsigned char val = 0){
        if(_size > max_size) throw ErrorMax();
        cur_size = _size;
        data = (new unsigned char[cur_size]);
                for(size_t i = 0; i < cur_size; i++)
                    data[i] = val;
    }
    
    //конструктор копирования
    Array(Array &ar): Array{ar.cur_size}{
//       cur_size = ar.cur_size;
//        data = new unsigned char[cur_size];
        for(size_t i = 0; i < cur_size; i++)
            data[i] = ar.data[i];
    }

    ~Array(){
        delete[]data;
    }
    
    // получение размера
    size_t getSize()const{
        return cur_size;
    }
    
    // чтение из файла
    void read(std::istream &in){
         int i = 0;
        while(i< cur_size){
            in >> data[i];
            i++;
        }
    }
    
    // индексирование
    unsigned char& operator[](int index){
     if(index >= 0 && index < cur_size)
            return data[index];
        else
            throw IndexError(index);
    }
    
     // индексирование
    const unsigned char &operator[](int index)const{
        if(index >= 0 && index < cur_size)
            return data[index];
        else
            throw IndexError(index);
    }
    
    // вывод всего массива
    friend std::ostream &operator << (std::ostream &out, Array &arr){
        for(size_t i = 0; i < arr.cur_size; i++){
            out << arr[i] << " ";
        }
        out << endl;
        return out;
    }
    
  
    
    
    const Array &operator= (const Array &ar2){
        cur_size = ar2.cur_size;
        for(size_t i = 0; i < cur_size; i++)
            data[i] = ar2.data[i];
        return *this;
    }

};


