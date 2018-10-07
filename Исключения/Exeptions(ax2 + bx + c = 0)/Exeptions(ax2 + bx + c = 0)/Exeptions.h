#ifndef EXEPTIONS_H
# define EXEPTIONS_H
#include "Header.h"

////2. собственная реализация - пустой класс
//
//class zeroDevision{
//
//};
//
//class negativeD{
//public:
////     int D;
////    negativeD(int val): D(val){}
//};



////3. собственная реализация - независимый класс с полями-параметрами
//class zeroDevision{
//public:
//    int val;
//    zeroDevision(int i): val(i){};
//
//};
//
//class negativeD{
//    public:
//         int D;
//        negativeD(int val): D(val){}
//};


////4. собственная реализация - наследование
class zeroDevision: public exception{
public:
    virtual const char* what()const throw(){
        return "Zero devision error \n";
    }
};

class negativeD: public exception{
    public:
         int D;
        negativeD(int val): D(val){}
    virtual const char* what()const throw(){
        return "There are no roots \n";
    }

};
#endif
