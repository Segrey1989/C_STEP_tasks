#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std:: cout;
using std:: endl;
using std:: string;
using std:: fstream;
using std:: istringstream;
using std:: cin;


class Person{
    string name;
    size_t age;
    string gender;
    
public:
    Person():age(0){}
    Person(string _name, size_t _age, string _gender): name(_name), age(_age), gender(_gender){}
    virtual ~Person(){}
    
    string get_name()const;
    size_t get_age()const;
    string get_gender()const;
    
    virtual void read(istringstream &str);
    virtual void print(fstream &out) = 0;
    virtual void count_scolarship(size_t base)= 0;
    virtual string get_speciality() = 0;
    
};

void Person::read(istringstream &str){
    str >> name >> age >> gender;
}

string Person::get_name()const{
    return name;
}

size_t Person::get_age()const{
    return age;
}

string Person::get_gender()const{
    return gender;
}
