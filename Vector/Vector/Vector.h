#include <iostream>
//#include "/Users/Siarhei/Desktop/STEP/C++/Drob/Drob/Drob.h"
#include "/Users/Siarhei/Desktop/STEP/C++/Drob/Drob/Drob.cpp"
template <class T>
class Vector
{
    T* data;
    size_t size;
    size_t ac_size; //текущее количество элементов
    
    bool check_mem();
public:
    size_t get_ac_size(){return ac_size;}
    Vector() : data(new T[1]), size(1), ac_size(0){};
    Vector(size_t);
    ~Vector(){ delete[]data; };
    Vector(const Vector<T> &v);
    Vector<T> &operator=(const Vector<T> &v);
    typedef T* iterator;
    iterator begin(){ return data; };
    iterator end(){ return (data +ac_size-1); }
    
    const T &operator[](size_t)const;
    T &operator[](size_t);
    void push_back(T);
    T pop_back();
    void insert(T, size_t);
    T erase(size_t);
};


template <class T>
Vector<T>::Vector(size_t _size) : size(_size), data(new T[_size]), ac_size(_size){};

template <class T>
Vector<T>::Vector(const Vector<T> &v){
    size = v.size;
    ac_size = v.ac_size;
    data = new T[size];
    for (size_t i = 0; i < ac_size; i++)
        data[i] = v.data[i];
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v){
    if (v != this){
        size = v.size;
        ac_size = v.ac_size;
        
        delete[]data;
        data = new T[size];
        for (size_t i = 0; i < ac_size; i++)
            data[i] = v.data[i];
    }
    return *this;
}


template <class T>
const T &Vector<T>::operator[](size_t index)const{
    if (index > ac_size){
        std::cout << "Error index \n";
        exit(1);
    }
    return data[index];
}


template <class T>
T &Vector<T>::operator[](size_t index){
    if (index > ac_size){
        std::cout << "Error index \n";
        exit(1);
    }
    return data[index];
}


template <class T>
void Vector<T>::push_back(T elem){
    if (check_mem()){
        Vector<T> temp(*this);
        size *= 2;
        delete[]data;
        data = new T[size];
        for (size_t i = 0; i < temp.ac_size; i++)
            data[i] = temp[i];
    }
    data[ac_size++] = elem;
}

//template <class T>
//void Vector <T> ::push_back(T elem)
//{
//    if (check_mem())
//    {
//        size*=2;
//        T* temp = new T[size];
//        for (int i=0; i<ac_size; ++i)
//            temp[i] = data[i];
//        delete[]data;
//        data=temp;
//        //data = new T[size];
//        //for (int i = 0; i<ac_size; ++i)
//        //   data[i] = temp[i];
//        //delete[] temp;
//    }
//    data[ac_size] = elem;
//    ac_size++;
//}


template <class T>
T Vector<T>::pop_back(){
    if(!ac_size){
        std::cout << "Vector is empty \n";
    exit(1);
    }
    return data[--ac_size];    
}

template <class T>
void Vector<T>::insert(T elem, size_t index){
    if(index > ac_size){
        std::cout <<"Wrong position \n";
        exit(1);
    }
    if (check_mem())
        size *= 2;
    
         T *temp = new T[size];

        for (int i = 0; i < index; i++)
            temp[i] = data[i];
        temp[index] = elem;
        
        for (size_t i = index; i < ac_size; i++)
            temp[i + 1] = data[i];
    ac_size++;
    
      delete[]data;
        data = temp;
    }


template <class T>
T Vector<T>::erase(size_t index){
    if(index > ac_size){
        std::cout <<"Wrong position \n";
        exit(1);
    }
    
    T temp = data[index];
    for(size_t i = index; i < ac_size; i++)
        data[i] = data[i+1];
    ac_size--;
    return temp;
}


template <class T>
bool Vector<T>::check_mem(){
    if (this->ac_size+1 <= this->size)
        return true;
    return false;
}




