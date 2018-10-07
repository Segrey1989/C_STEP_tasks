/*
 Создать абстрактный базовый класс Series (прогрессия) с виртуальными функциями вычисления j-го элемента прогрессии и суммы прогрессии. Определить производные классы: Liner (арифметическая) и Exponential (геометрическая). Реализовать вывод элементов прогрессии в файл.
 Вызывающая программа должна продемонстрировать все варианты вызова виртуальных функций с помощью указателей на базовый класс.

 */

#include "Series.cpp"
#include "Linear.cpp"
#include "Exponential.cpp"
#include <fstream>
using std:: fstream;
using std:: ios;

void write(fstream &out, Series* prog, int size);

int main() {
    fstream out("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Abstract clases/Progression/Progression/out.txt", ios::out);
    
    Series *ar[4];
    ar[0]= new Linear(2, 7);
    ar[1]= new Exponential(2, 3);
    
    out << "Linear: \n";
    write(out, ar[0], 2);
    out<< "Summa: " << ar[0]->find_sum(2) << endl;
    
    write(out, ar[0], 15);
    out<< "Summa: " << (*ar[0]).find_sum(15) << endl;
    
    
    out << "Exponential: \n";
    write(out, ar[1], 4);
    out <<"Summa: " << ar[1]->find_sum(4) << endl;
    
    write(out, ar[1], 10);
    out <<"Summa: " << (*ar[1]).find_sum(10) << endl;
    
    for(int i = 0; i < 4; i++)
    delete ar[i];
    
    return 0;
}

void write(fstream &out, Series* prog, int size){
    for(int i = 1; i <= size; i++){
        out << prog->find_el(i) <<" ";
    }
    out<<endl;
}
