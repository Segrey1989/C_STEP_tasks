#include "Header.h"
#include "Array.cpp"


class Octal : public Array{
public:
    class ErrorMax: public exception{
    public:
        virtual const char*what()const throw(){
            return "Invalid value\n";
        }
    };
    Octal(int Size, unsigned char val = 0) :Array(Size, val){
        if (val > 7 || val < 0){
            throw ErrorMax();
        }
    }
    
    void set(int i, unsigned char val){
        if (i > getSize() - 1)
            throw IndexError(i);
        
        if (val > 7 || val < 0){
            throw ErrorMax();
        }
        
        (*this)[i] = val;
        
    }
    
    
    Octal operator+(const Octal &a)const{
        int new_size;
        if (getSize() > a.getSize())
            new_size = getSize();
        else
            new_size = a.getSize();
        new_size += 1;
        Octal new_octal(new_size), first(new_size), second(new_size);
        int count = 0;
        
        for (int i = getSize() - 1, j = new_size - 1; i != -1; i--, j--){
            first[j] = (*this)[i];
        }
        
        for (int i = a.getSize() - 1, j = new_size - 1; i != -1; i--, j--){
            second[j] = a[i];
        }
        
        for (int i = new_size - 1; i != 0; i--){
            new_octal[i] = first[i] + second[i] + count;
            if (new_octal[i] > 7)
                count = 1;
            else
                count = 0;
            new_octal[i] = new_octal[i] % 8;
            
        }
        
        return new_octal;
    }
    
    friend std::ostream &operator << (std::ostream &out, Octal &arr){
        for(size_t i = 0; i < arr.cur_size; i++){
            out << int(arr[i]) << " ";
        }
        out << endl;
        return out;
    }
};

