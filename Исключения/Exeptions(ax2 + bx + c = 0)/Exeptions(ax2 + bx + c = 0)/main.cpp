#include "Header.h"
#include "Exeptions.h"

int main() {
    double x1 = 0, x2 = 0;

//    // 1. со спецификацией throw
//    try{
//    find_roots(3,1, 11, x1, x2);
//    }
//    catch(int i){
//        if (i == 1)
//        cout << i << " -Zero devision" << endl;
//        else if (i == 2)
//            cout <<i << " - No roots" << endl;
//    }
//
    
    
//  //  2. собственная реализация - пустой класс
//    try{
//        find_roots(1, 6, 14, x1, x2);
//    }
//    catch(zeroDevision){
//        cout<< "a = 0: " << "Imposible to make zero division \n";
//    }
//    catch(negativeD){
//        cout<< "D is negative - no roots \n";
//    }

    
  
//    //3. собственная реализация - независимый класс с полями-параметрами
//    try{
//        find_roots(2, 16, 64, x1, x2);
//    }
//    catch(zeroDevision zero_obj){
//        cout<< "a = " << zero_obj.val << " Imposible to make zero division \n";
//    }
//    catch(negativeD neg_obj){
//        cout<< "D = " << neg_obj.D << " is negative - no roots \n";
//    }
    
    
   
        //4. собственная реализация - наследование
        try{
            find_roots(3, 6, 26, x1, x2);
        }
        catch(zeroDevision &zero_obj){ //зачем здесь & - работает без него
            cout << zero_obj.what();
        }
        catch(negativeD &neg_obj){ //зачем здесь & - работает без него
            cout<< neg_obj.what();
            cout << "D = " << neg_obj.D << endl;
        }
    
        cout << "x1 = "<< x1 << endl;
        cout << "x2 = "<< x2 << endl;
    
    
    return 0;
}


