
#include "Person.h"
#include "Student.h"
#include "Aspirant.h"

// создание указателя на определенный класс
Person *getPtr(const string line){
    size_t count = 0, pos = 0;
    int temp = 0;
    
    while(count < 4){
        pos = line.find(" ", pos);
        if(pos == std::string::npos) break;
        pos++;
        count++;
    }
    temp = std::stoi(line.substr(pos));
    
    if(std::to_string(temp).length()==4)
        return new Aspirant();
    else
        return new Student();
}


// вывод в консоль студентов и аспирантов заданной специальности
void print_same_speciality(Person **arr, string spec, size_t _size){
    for(size_t i = 0; i < _size; i++)
        if ((*arr[i]).get_speciality().compare(spec) == 0){
            if(strcmp(typeid(*arr[i]).name(), "7Student")==0)
                cout << *dynamic_cast<Student*>(arr[i]);
            else
                cout << *dynamic_cast<Aspirant*>(arr[i]);
        }
}


// подсчет количества человек во входящем файле и перемещение указателя на
//  начало файла
void find_list_size(fstream &in, size_t &size){
    string line;
    while(in){
        getline(in, line);
        size++;
    }
    in.close();
    in.open("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Abstract clases/Person/Person/input.txt", std::ios::in);
}


// перерасчет стипендии, в зафисимости от среднего бала (для студентов)
void recount_scolarspip(Person *arr, size_t base_st, size_t base_asp){
    if(strcmp(typeid((*arr)).name(), "7Student")==0)
        dynamic_cast<Student*>(arr)-> count_scolarship(base_st);
    else
        dynamic_cast<Aspirant*>(arr)->count_scolarship(base_asp);
}
