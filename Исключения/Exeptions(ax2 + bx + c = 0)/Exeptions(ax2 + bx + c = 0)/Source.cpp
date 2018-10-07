#include "Header.h"
#include "Exeptions.h"

// // 1. со спецификацией throw
//void find_roots(int a, int b, int c, double &x1, double &x2){
//    if(a == 0)
//        throw  1;
//
//    int D = pow(b, 2) - 4 * a * c;
//    if(D == 0)
//        x1 = -b / (2.0*a);
//
//    else if (D > 0){
//
//        x1 = (-b - sqrt(D)) / (2.0 * a);
//        x2 = (-b + sqrt(D)) / (2.0 * a);
//    }
//    else
//        throw 2;
//
//    }


//// 2. собственная реализация - пустой класс
//void find_roots(int a, int b, int c, double &x1, double &x2){
//    if(a == 0)
//        throw  zeroDevision();
//
//    int D = pow(b, 2) - 4 * a * c;
//    if(D == 0)
//        x1 = -b / (2.0*a);
//
//    else if (D > 0){
//
//        x1 = (-b - sqrt(D)) / (2.0 * a);
//        x2 = (-b + sqrt(D)) / (2.0 * a);
//    }
//    else{
//        throw negativeD();
//    }
//
//    }

////3. собственная реализация - независимый класс с полями-параметрами
//
//void find_roots(int a, int b, int c, double &x1, double &x2){
//    if(a == 0)
//        throw  zeroDevision(a);
//
//    int D = pow(b, 2) - 4 * a * c;
//    if(D == 0)
//        x1 = -b / (2.0*a);
//
//    else if (D > 0){
//
//        x1 = (-b - sqrt(D)) / (2.0 * a);
//        x2 = (-b + sqrt(D)) / (2.0 * a);
//    }
//    else{
//        throw negativeD(D);
//    }
//
//    }


//4. собственная реализация - наследование

void find_roots(int a, int b, int c, double &x1, double &x2){
    if(a == 0)
        throw  zeroDevision();

    int D = pow(b, 2) - 4 * a * c;
    if(D == 0)
        x1 = -b / (2.0*a);

    else if (D > 0){

        x1 = (-b - sqrt(D)) / (2.0 * a);
        x2 = (-b + sqrt(D)) / (2.0 * a);
    }
    else{
        throw negativeD(D);
    }

    }
