#pragma once
#include "Series.cpp"
#include<cmath>

class Exponential: public Series{
    int q;
public:
    Exponential(): Series::Series(), q(0){}
    Exponential(int _first_mem, int _d = 1):Series::Series(_first_mem, _d){}
    
    long find_el(int ind){
        long el = get_first_mem() * pow(get_d(), ind - 1);
        return el;
    }
    
    long find_sum(int num){
        long sum = 0;
        if(get_d() != 1)
            sum = (get_first_mem() *(1 - pow(get_d(), num)))/ (1 - get_d());
        else
            sum = num * get_first_mem();
        return sum;
    }
    
};
