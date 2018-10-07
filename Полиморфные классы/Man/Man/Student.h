#pragma once
#include "Man.h"

class Student: public Man{
    size_t stud_year;
    
public:
    Student(): Man(), stud_year(0){}
    Student(char *_name, size_t year): Man(_name), stud_year(year){}
    Student(size_t year): Man(), stud_year(year){}
    
    size_t get_year()const{return stud_year;};
    void set_year(size_t year){stud_year = year;};
    
    Student &operator=(const Student &);
    
    bool operator==(const Student &);
    void print(std::ostream &);
    friend std::ostream &operator<<(std::ostream &, const Student &);
    friend std::istream &operator>>(std::istream &, Student &);
    
    Student &operator++();
};

Student &Student::operator=(const Student & st){
    if(strcmp((*this).get_name(), st.get_name()) == 0){
        return *this;
    }
    ((*this).set_name(st.get_name()));
     ((*this).set_age(st.get_age()));
     ((*this).set_sex(st.get_sex()));
     ((*this).set_weight(st.get_weight()));
    
    
        return *this;
}

Student &Student::operator++(){
    stud_year++;
    return *this;
}

bool Student::operator==(const Student &st){
    return stud_year == st.stud_year ? true:false;
}

void Student::print(std::ostream &out){
    out<< "Name: " << get_name() << "\n";
    out<< "Age: " << get_age() << "\n";
    out<< "Sex: " << get_sex() << "\n";
    out<< "Weight: " << get_weight() << "\n";
    out << "Studding year: " << get_year() << "\n\n";
}

std::ostream &operator<<(std::ostream & out, const Student & st){
    out<< "Name: " << st.get_name() << "\n";
    out<< "Age: " << st.get_age() << "\n";
    out<< "Sex: " << st.get_sex() << "\n";
    out<< "Weight: " << st.get_weight() << "\n";
    out << "Studding year: " << st.get_year() << "\n\n";
    return out;
}

std::istream &operator>>(std::istream &in, Student &st){
   in >> st.name >> st.age >> st.sex >> st.weight >> st.stud_year;
    return in;
}
