#include "Person.h"

class Aspirant: public Person{
    float average;
    size_t year;
    string speciality;
    float scolarship;
    
public:
    Aspirant(): Person::Person(), average(0), year(0), scolarship(0){}
    Aspirant(string _name, size_t _age, string _gender, float _aver, size_t _year, string _spec);
    
    virtual void read(istringstream &str);
    virtual string get_speciality();
    virtual void count_scolarship(size_t base);
    virtual void print(fstream &out);
    
    friend std::ostream &operator<<(std::ostream &, const Aspirant &);
};

Aspirant::Aspirant(string _name, size_t _age, string _gender, float _aver, size_t _year, string _spec):
scolarship(0),
Person::Person(_name, _age, _gender),
average(_aver), year(_year), speciality(_spec){}


void Aspirant::count_scolarship(size_t base){
    scolarship = base;
}

string Aspirant::get_speciality(){
    return speciality;
}

void Aspirant::print(fstream &out){
    out << "Aspirant: \n";
    out <<"name: " << get_name() << "\nage: " << get_age() << "\ngender: " << get_gender() << "\n";
    out << "average: " << average << "\nyear: " << year << "\nspeciality: " << speciality << "\n";
    out << "scolarship: " << scolarship << "\n";
    out << "\n\n";
}


void Aspirant::read(istringstream &str){
    Person:: read(str);
    str >> average >> year >> speciality >> scolarship;
}

std::ostream &operator<<(std::ostream &out, const Aspirant & asp){
    out << "Aspirant: \n";
    out <<"name: " << asp.get_name() << "\nage: " << asp.get_age() << "\ngender: " << asp.get_gender() << "\n";
    out << "average: " << asp.average << "\ncourse: " << asp.year << "\nspeciality: " << asp.speciality << "\n";
    out << "scolarship: " << asp.scolarship << "\n";
    out << "\n\n";
    return out;
}
