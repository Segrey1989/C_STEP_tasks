#pragma once
#include "Series.cpp"

class Linear: public Series{
public:
    Linear(): Series::Series(){}
    Linear(int _first_mem, int _d = 1):Series::Series(_first_mem, _d){}
    
    long find_el(int ind){
        long el = get_first_mem() + (ind - 1) * get_d();
        return el;
    }
    
    long find_sum(int num){
        //long sum = (2 * get_first_mem() + get_d() * (num -1)) / 2 * num;
        long sum = (get_first_mem() + find_el(num)) / 2.0 * num ;
        return sum;
    }
};
