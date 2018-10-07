
#pragma once
#include "array.h"
#include <cmath>

class Polinom : public Array
{
public:
    Polinom():Array(){}
    Polinom(size_t _size, int value = 0): Array(_size, value){}
    Polinom(const Array&A)
    {
        (*this).set_size(A.get_size());
        for (int i = 0; i < A.get_size(); i++)
        {
            (*this)[i] = A[i];
        }
    }
    float get_value(float)const;
    const Polinom &operator*(const Polinom &)const;
    const double &operator/(const double &)const;
    const Polinom &operator-(const Polinom &)const;
    bool operator >(const Polinom &)const;
    bool operator <(const Polinom &)const;
    bool operator ==(const Polinom &)const;
};

float Polinom::get_value(float x)const
{
    float value = 0;
    for (int i = 0; i < get_size(); i++)
    {
        value += pow(x, i)*(*this)[i];
    }
    return value;
}

// произведение полиномов
const Polinom &Polinom::operator*(const Polinom &pol)const{
    Polinom temp(get_size());
    for (int i = 0; i < get_size(); i++){
        temp[i] = (*this)[i];
         for (int j = 0; j < pol.get_size(); j++){
             temp[i] *= pol[j];
         }
    }
    return Polinom(temp);
}

// деление многочлена на одночлен
const double &Polinom::operator/(const double & el)const{
    double result = 0;
    for (int i = 0; i < get_size(); i++){
        result += (*this)[i] / el;
    }
    return result;
}

// разность полиномов
const Polinom &Polinom::operator-(const Polinom & pol)const{
    size_t new_size = 0;
    int i = 0;
    get_size() > pol.get_size() ? new_size = get_size() : new_size = pol.get_size();
     Polinom temp(new_size);
    
    if(get_size() < pol.get_size()){
    for (; i < get_size(); i++)
        temp[i]=(*this)[i] - pol[i];
    for (; i < pol.get_size(); i++)
        temp[i] = pol[i] * (-1);
    }
    else {
        for (; i < pol.get_size(); i++)
            temp[i]=(*this)[i] - pol[i];
        for (; i < get_size(); i++)
            temp[i] = (*this)[i];
    }
    
    return Polinom(temp);
}

//вспомогательная функция для подсчета суммы всех членов многочлена
double sum(const Polinom &pol){
     double result= 0;
    for (int i = 0; i < pol.get_size(); i++)
        result+= pol[i];
    return result;
}

bool Polinom::operator >(const Polinom & pol)const{
    return sum(*this) > sum(pol)? true : false;
}

bool Polinom::operator <(const Polinom & pol)const{
    return sum(*this) < sum(pol)? true : false;
}

bool Polinom::operator ==(const Polinom & pol)const{
    return sum(*this) == sum(pol)? true : false;
}
