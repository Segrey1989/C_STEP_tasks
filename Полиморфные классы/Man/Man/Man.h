#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <typeinfo>

class Man{
protected:
    char *name;
    size_t age;
    char *sex;
    size_t weight;
public:
    Man():age(0), weight(0){
        name = new  char[50];
        sex = new char[10];
        strcpy(name, "");
        strcpy(sex, "");
    }
    Man(char *_name): age(0), weight(0){
        name = new  char[50];
        sex = new char[10];
        strcpy(name, _name);
        strcpy(sex, "");
    }
    virtual ~Man(){
        delete[] name;
        delete[] sex;
    }
    
    void set_name(char *_name);
    void set_age(size_t _age);
    void set_weight(size_t _weight);
    void set_sex(char *_sex);
    
    char* get_name()const{return name;}
    size_t get_age()const{return age;};
    size_t get_weight()const{return weight;};
    char* get_sex()const{return sex;}
    
    virtual bool operator==(const Man &);
    virtual void print(std::ostream &);
    
    friend std::ostream &operator<<(std::ostream &, const Man &);
    friend std::istream &operator>>(std::istream &, Man &);
};

void Man::set_name(char *_name){
    strcpy(name, _name);
}

void Man::set_age(size_t _age){
    age = _age;
}

void Man::set_weight(size_t _weight){
    weight = _weight;
}

void Man::set_sex(char *_sex){
    strcpy(sex, _sex);
}

bool Man::operator==(const Man &mn){
    return age == mn.age ? true:false;
}

void Man::print(std::ostream &out){
    out << name << "| " << age << "| " << sex << "| " << weight << "\n";
}

std::ostream &operator<<(std::ostream & out, const Man &mn){
    out << mn.name << "| " << mn.age << "| " << mn.sex << "| " << mn.weight << "\n\n";
    return out;
}


std::istream &operator>>(std::istream &in, Man &mn){
    in >> mn.name >> mn.age >> mn.sex >> mn.weight;
    return in;
}
