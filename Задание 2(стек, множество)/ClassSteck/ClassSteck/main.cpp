#include "Header.h"

int main() {
    Steck a(2);
    Steck c;
//    a.push(10);
//    a.push(4);
//    std::cout << a.pop() << "\n";
  
    
    c = a; // присвоили c размер и содержимое a

// дополнили c
     c.push(5);
     c.push(6);
     c.push(7);

    //дополнили a
    a.push(5);

    // инициализировали стек b через конструктор копирования
   Steck b(a);

    std::cout <<"Значение top стека с: "<< c.Get_top() << " \n";
    std::cout <<"Извлекли из с: " <<c.pop() << " \n";
     std::cout <<"Значение top стека с: "<< c.Get_top() << " \n\n";

    std::cout <<"Значение top стека a: "<< a.Get_top() << " \n";
     std::cout <<"Значение top стека b: "<< b.Get_top() << " \n\n";

    //std::cout << a.Get_size() << "\n";
    return 0;
}
