#include "Header.h"

int main() {
    Set obj1("abcde"), obj2, obj3, obj4, obj5, obj6;
     std::cin >> obj2;
    
    std::cout << "Пересечение \n";
    obj3 = obj1 * obj2;
    std::cout << obj3 << "\n\n";
    
    std::cout << "Объединение \n";
    obj4 = obj1 + obj2;
    std::cout << obj4 << "\n\n";
    
     std::cout << "Разность \n";
    obj5 = obj1 - obj2;
    std::cout << obj5 << "\n\n";

     std::cout << "Включение \n";
    std::cout << (obj2 < obj1) << "\n\n";
    
    std::cout << "Эквивалентность \n";
    std::cout << (obj1 == obj2) << "\n\n";
    return 0;
}
