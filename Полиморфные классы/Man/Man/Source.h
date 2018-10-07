#include "Man.h"
#include "Student.h"
#include <ctime>

//подсчет количества пробелов в строке
size_t count_spaces(char *str){
    size_t space_num = 0;
    char *ptr = str;
    
    while(*ptr != '\0'){
        if(isspace(*ptr))
            space_num++;
        ptr++;
    }
    return space_num;
}

// подсчет людей одного возраста
size_t count_same_age(Man **arr, size_t size, size_t age){
    size_t count = 0;
    for(int i = 0; i < size ; i++)
        if(arr[i]->get_age() == age)
            count++;
    return count;
}

// подсчет студентов одного года поступления
size_t count_same_year(Man **arr, size_t size, size_t year){
    size_t count = 0;
    for(int i = 0; i < size ; i++)
        if(static_cast<Student*>(arr[i])->get_year() == year)
            count++;
    return count;
}

// освобождение памяти
void freeMem(Man **arr, size_t size){
    for(int i = 0; i < size ; i++)
        delete arr[i];
}
