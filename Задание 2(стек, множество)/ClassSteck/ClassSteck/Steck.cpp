#include "Header.h"

// конструктор копирования
Steck::Steck(const Steck &stk){
    size = stk.size;
    top = 0;
    data = new int[size];
    for (int i = 0; i < stk.top; i++){
        data[i] = stk.data[i];
        top++;
    }
}

// переопределение операции присваивания
Steck & Steck::operator =(const Steck &other){
    if(this == &other)
        return *this;
    
    size = other.size;
    top = 0;
    delete[]data;
    data = new int[size];
    
    for(int i = 0; i < other.top; i++){
        data[top] = other.data[i];
        top++;
    }
    return *this;
}

// проверка на заполненность стека
bool Steck::is_full()const{
    if (top == size){
       // std::cout << "Stack is full \n";
        return true;
    }
    return false;
}

// пуст ли стек
bool Steck::is_empty()const{
    if (top == 0){
        std::cout << "Stack is empty \n";
        return true;
    }
    return false;
}

// добавление элемента
void Steck::push(int val){
    if (is_full()){
        Steck temp(*this);
        delete[]data;
        size+=10;
        top = 0;
        data = new int[size];
        for(int i = 0; i <= temp.top && temp.top != 0; i++)
            data[top++] = temp.data[i++];
    }
  
        data[top] = val;
        top++;
}

//извлечение элемента
int Steck::pop(){
    if(!is_empty()){
        top--;
        return data[top];
    }
    return 0;
};
