#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Series{
    int first_mem;
    int d;
    
public:
    Series():first_mem(0), d(0){}
    Series(int _first_mem, int _d = 1){
      first_mem =  _first_mem;
        d = _d;
    }
    
    virtual ~Series(){}
    virtual long find_el(int ind) = 0;
    virtual long find_sum(int num) = 0;
    
    int get_d(){return d;};
    int get_first_mem(){return first_mem;};
    
};
