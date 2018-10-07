
#include "Source.h"

int main() {
    std::ifstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Полиморфные классы/Man/Man/input.txt");
    if(!in){
        std::cout << "File opening error in the first opening\n";
        return 0;
    }
    
    size_t size = 0;
    char str[255];
    //массив пробелов(если использовать ф-ю in.getline для подсчета пробелов, то необходимо как-то смещаться назад, чтобы занести данные прочитанной строки в объект)
    size_t arr[100] = {0};
    // подсчет количества строк в файле и занесение данных о числе пробелов в массив
    for(size_t i= 0; in.getline(str, 254, '\n'); i++){
        arr[i] =  count_spaces(str);
        size++;
   }
    in.close();
   in.open("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Полиморфные классы/Man/Man/input.txt");
    if(!in.is_open()){
        std::cout << "File opening error in the second opening\n";
        return 0;
    }
    
    Man *people[size];
    int i = 0;
    while(i < size){
        if(arr[i]== 3){
            people[i] = new Man;
            in>> *people[i];
            i++;
        }
        else if(arr[i]== 4){
            people[i] = new Student;
            in >> *dynamic_cast<Student*>(people[i]);
            i++;
        }
        else{
            std::cout <<"Ошибка, пробелов - " << count_spaces(str) << "\n";
            return 0;
        }
    }
    
    //вывод в консоль массива people
    for(int i = 0; i < size ; i++)
        if(strcmp(typeid(*people[i]).name(), "3Man") == 0)
             std:: cout << *people[i];
        else
              std:: cout << *dynamic_cast<Student*>(people[i]);
    

    std::cout << "Same age men: " << count_same_age(people, size, 31) << "\n";
    std::cout << "Same year students: " << count_same_year(people, size, 2017) << "\n";
    
    // освобождение памяти
    freeMem(people, size);
    
    return 0;
}

