
#include "Source.h"

int main() {
    fstream out("//Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Abstract clases/Person/Person/output.txt", std::ios::out);
    fstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Abstract clases/Person/Person/input.txt", std::ios::in);
    size_t size = 0, i = 0;
    string line;
    
    find_list_size(in, size); // определение размера массива указателей

    Person *arr[size-1]; // массив указателей на базовый класс

    if(in.is_open()){
        while(i < size-1){
            getline(in, line);
            arr[i] = getPtr(line);
            istringstream str = istringstream(line);
            arr[i]->read(str);
            recount_scolarspip(arr[i], 70,150); //перерасчет стипендии
            arr[i]->print(out); // вывод в файл
            i++;
        }
        print_same_speciality(arr, "managment", size-1); // вывод одной специальности
    }
    else
        cout << "Input file opening error \n";
    
    for(size_t i = 0; i < size-1; i++)
        delete arr[i];
    
    return 0;
}

