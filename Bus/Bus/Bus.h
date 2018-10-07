/*
 Построить класс для работы со списком.
 Элемент списка содержит информацию об автобусе:
 номер автобуса;
 фамилию и инициалы водителя;
 номер маршрута.
 Программа должна обеспечивать:  a) начальное формирование двух списков:
 1) с данными об автобусах, которые находятся в парке;
 2) с данными об автобусах, которые находятся на маршрутах;
 при выезде каждого автобуса из парка вводится номер автобуса, и программа удаляет данные об этом автобусе из списка автобусов, находящихся в парке, и записывает эти данные в список автобусов, находящихся на маршруте;
 b) аналогичная операция выполняется для списков, если некоторый автобус возвращается в парк;  c) по запросу выдаются сведения об автобусах, находящихся в парке, или об автобусах, находящихся на маршруте.

 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Однонаправленный список/SingleList/SingleList/SingleList.h"

struct Bus{
    char number[10];
    char driver[30];
    size_t route;
    Bus();
    Bus(char *num, char *driv = "", size_t rt = 0);
 
    bool operator==(const Bus & b)const ;
   const Bus &operator=(const Bus &b);
    friend std::ostream &operator<<(std::ostream &out, const Bus &el);
     friend std::istream &operator>>(std::istream &in, Bus &el);
};

Bus::Bus():route(0){
    strcpy(number, "");
    strcpy(driver, "");
}

// два параметра по умолчанию, обязателен только номер автобуса, для метода search
Bus::Bus(char *num, char *driv, size_t rt): route(rt){
    strcpy(number, num);
    strcpy(driver, driv);
};



const Bus &Bus:: operator=(const Bus &b){
    if(b == *this)
       return *this;
    else{
        strcpy(number, b.number);
        strcpy(driver, b.driver);
        route = b.route;
    }
    return *this;
}
        

std::ostream &operator<< (std::ostream &out, const Bus & el){
    out<<"Номер автобуса: " << el.number<< "\n" <<"ФИО водителя: " <<\
    el.driver  <<"\n"<< "Маршрут: "<< el.route << "\n"  ;
    return out;
}

std::istream &operator>>(std::istream &in,  Bus &el){
//
//std::istream &operator>>(std::istream &in,  Bus &el){
//    char str [255];
//
//
//    in.getline(str, 255,'\0');
//    char *ptr = str;
//    char *ptr1 = nullptr;
//
//    while(!isspace(*ptr))
//        ptr++;
//      strncat(el.number, str, strlen(str)-strlen(ptr));
//    ptr1 = ptr;
//
//    while(!isnumber(*ptr))
//        ptr++;
//
//    strncat(el.driver, ptr1, strlen(ptr1)-strlen(ptr));
//
    in>> el.number >> el.driver >> el.route;
    return in;
}

// эквивалентность, если совпадают только номера автобусов, то эквмвалентны
bool Bus::operator==(const Bus & b)const{
    return (strcmp(number, b.number) == 0) ? true : false;
}

