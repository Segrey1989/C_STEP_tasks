
#include "Header.h"
#include "Tree.cpp"


int main() {
    BinTree<string> data_base;
    
//    data_base.add_elem("BM3456");
//    data_base.add_elem("BM3456");
//    data_base.add_elem("PH3089");
//    data_base.add_elem("G0056");
//   data_base.add_elem("LN0159");
//
    data_base.add_penalty("BM3456", "Fast speed");
     data_base.add_penalty("BM3456", "Turn left on right");
     data_base.add_penalty("PH3089", "Fast speed");
    data_base.add_penalty("LN0159", "Medicine");

     data_base.add_penalty("BM3456", "Rubish");
     data_base.add_penalty("PH3089", "Fast speed");
     data_base.add_penalty("G0056", "Rubish");

     data_base.give_paymant("LN0159", "Medicine");
 
    
    cout << "Вывод по ключу: \n";
    data_base.print_by_key("BM3456");
    
    cout << "Вывод в диапазоне: \n";
    data_base.pint_in_diapason("G0056", "PH3089");
    
    cout << "Вывод всего списка: \n";
    data_base.print();

    return 0;
}
