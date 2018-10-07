/*
 Тема: Шаблоны функций
 Задание №1 Написать шаблон функции для поиска среднего арифметиче- ского значений массива.
 Задание №2 Написать перегруженные шаблоны функций для нахождения корней линейного (a*x + b = 0) и квадратного (a*x2+b*x + c = 0) уравнений. Замечание: в функции передаются коэффициенты уравнений.
 Задание №3 Напишите шаблон функции, которая возвращает максимум из двух переданных параметров
 Задание №4 Напишите шаблон функции, которая возвращает минимум из двух переданных параметров.
 Задание №5 Напишите шаблон функции, которая осуществляет поиск максимального элемента в массиве. Функция возвращает позицию элемента и его значение.
 
 Задание №6 Напишите шаблон функции, которая принимает массив, и выводит на экран позиции нулевых элементов массива.
 
 Задание №7 Напишите шаблон функции, которая принимает x и y и вычисляет xy. Y – целое число.
 
 Протестировать шаблонные функции на различных типах данных.
 */


#include<iostream>
#include<cmath>
#include "/Users/Siarhei/Desktop/STEP/C++/Задание 2(стек, множество)/Set/Set/Header.h"
#include "/Users/Siarhei/Desktop/STEP/C++/Drob/Drob/Drob.cpp"

template<class T>
T* givemem(T*, size_t size);

template<class T>
T* freemem(T*);

template<class T>
void print(T*, size_t);

template<class T>
void read(T*, size_t);

template<class T>
T findAverage(T *, size_t);

template<class T>
T findMin(T obj1, T obj2);

template<class T>
T findMax(T obj1, T obj2);

template<class T>
size_t findElem(T*, size_t, T &);

template<class T>
void findZeroPositions(T *, size_t , size_t *, size_t &);

template<class T>
T power(T x, int y);

//линейное уравнение
template<class T>
T linearEquasion(T a, T b){
    T result = T();
    if(a == b){
        std::cout << "Уравнение имеет множество корней: ";
         exit(1);
    }
    else if(a == T() && (b > T() || b < T())){
        std::cout << "Нет корней: ";
        exit(1);
    }else
    {
        result  = T() - b/a;
    }
    return result;
}


// квадратное уравнение
template<class T>
void quadraticEquasion(T a, T b, T c){
    T x, x2;
    T D = power(b, 2) - (4 * a *c);
   
    if (D < T()){
        std::cout << "Нет корней: ";
        exit(1);
    }
    else if(D == T())
        x = T() - b/2 * a;

    else{
        x = (T() - b - sqrt(D))/(2 * a);
        x2 =(T() - b + sqrt(D))/(2 * a);
        std::cout << "x1: " <<x << " x2: " << x2 << "\n";
    }
}

// выделение памяти массиву
template<class T>
T* givemem(T* arr, size_t size){
    arr = new T[size];
    return arr;
}

// освобождение памяти массива
template<class T>
T* freemem(T* arr){
    delete[]arr;
    arr = nullptr;
    return arr;
}

// вывод элементов
template<class T>
void print(T* arr, size_t size){
    std::cout << "Elements of array\n";
    for (size_t i = 0; i <size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

// чтение элементов с консоли
template<class T>
void read(T* arr, size_t size){
    std::cout << "Enter " << size << " elements of array \n";
    for (size_t i = 0; i <size; i++)
        std::cin >> arr[i];
}


// поиск среднего арифметического
template<class T>
T findAverage(T * arr, size_t size){
    //std::cout << "Average of array \n";
    T temp = T();

    for (size_t i = 0; i < size; i++)
        temp = temp + arr[i];
    temp = temp/size;

    return temp;
}

// поиск минимума
template<class T>
T findMin(T obj1, T obj2){
    if(obj1 == obj2){
        std::cout << "Equal ";
    return obj1;
    }
    return obj1 < obj2 ? obj1 : obj2;
}

// поиск максимума
template<class T>
T findMax(T obj1, T obj2){
    if(obj1 == obj2){
        std::cout << "Equal ";
        return obj1;
    }
    return obj1 > obj2 ? obj1 : obj2;
}

// поиск максимально элемента и его позиции
template<class T>
size_t findElem(T* arr, size_t size, T &el){
    el= *arr;
    size_t index = 0, count = 0;
    for(T *ptr = arr; ptr < &arr[size]; ptr++){
        if(*ptr > el){
            el  = *ptr;
            index = count;
        }
        count++;
    }
    return index;
}

// поиск нулевых значений
template<class T>
void findZeroPositions(T *arr, size_t size, size_t *pos_arr, size_t &pos){

    size_t index = 0;
     for(T *ptr = arr; ptr < &arr[size]; ptr++){
         if(*ptr == T()){
             pos_arr[pos] = index;
         pos++;
         }
          index++;
     }
}

// возведение в степень
template<class T>
T power(T x, int y){
    T result = x;
    for(size_t i = 1; i < y; i++)
        result = result * x;
    return result;
}

