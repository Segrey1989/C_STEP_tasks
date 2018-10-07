#include "Person.h"

class Student: public Person{
    float average;
    size_t course;
    string speciality;
    float scolarship;
    
    float _find_k();
public:
    Student(): Person::Person(), average(0), course(0), scolarship(0){}
    Student(string _name, size_t _age, string _gender, float _aver, size_t _course, string _spec);

    
    virtual string get_speciality();
    virtual void read(istringstream &str);
    virtual void count_scolarship(size_t base);
    virtual void print(fstream &out);
    
    friend std::ostream &operator<<(std::ostream &, const Student &);
};


Student::Student(string _name, size_t _age, string _gender, float _aver, size_t _course, string _spec):
scolarship(0),
Person::Person(_name, _age, _gender),
average(_aver), course(_course), speciality(_spec){}

void Student::count_scolarship(size_t base){
    scolarship = base * _find_k();
}

string Student::get_speciality(){
    return speciality;
}

void Student::print(fstream &out){
     out << "Student: \n";
    out <<"name: " << get_name() << "\nage: " << get_age() << "\ngender: " << get_gender() << "\n";
    out << "average: " << average << "\ncourse: " << course << "\nspeciality: " << speciality << "\n";
    out << "scolarship: " << scolarship << "\n";
    out << "\n\n";
}


void Student::read(istringstream &str){
    Person:: read(str);
    str >> average >> course >> speciality >> scolarship;
}

std::ostream &operator<<(std::ostream &out, const Student & st){
    out << "Student: \n";
    out <<"name: " << st.get_name() << "\nage: " << st.get_age() << "\ngender: " << st.get_gender() << "\n";
    out << "average: " << st.average << "\ncourse: " << st.course << "\nspeciality: " << st.speciality << "\n";
    out << "scolarship: " << st.scolarship << "\n";
    out << "\n\n";
    return out;
}

float Student::_find_k(){
    float k = 0;
    if (average > 5 && average < 6)
        k = 1;
    else if(average >= 6 && average <8)
        k = 1.2;
    else if(average >= 8 && average < 9)
        k = 1.4;
    else
        k = 1.6;
    
    return k;
}
