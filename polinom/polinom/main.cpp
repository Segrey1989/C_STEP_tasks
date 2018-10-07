
#include "polinom.h"

int main()
{
    Array a(10, 3);
    Polinom p1(a), p2(3, 2);
    Polinom p3, p4, p5;
    p3 = p1+p2;
    p4 = p3*p2;
    p5 = p2 - p4;
     std::cout<< "p1: " << p1;
    std::cout<< "p2: " << p2;
    std::cout<< "p3: " << p3;
    std::cout<< "p4: " << p4;
    std::cout<< "p5: " << p5;
    
    double o, summ ;
    o = p2/2;
    std::cout<< "o: "<< o << '\n';
    
//    summ = sum(p1);
//     std::cout<< "summ: "<< summ << '\n';
    std::cout<< std::boolalpha << (p1 < p2) <<'\n' ;
    
    float x = 2;
    std::cout << p3.get_value(x) << '\n';
}

