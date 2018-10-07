#include<iostream>
#include<cstring>

class Drob{
    int ch;
    int zn;
    
     void Reduce();
public:
    Drob():ch(0),zn(1){};
    Drob(int _ch, int _zn);
    Drob (const Drob &d);
    ~Drob(){};
    
    int getCh();
    void setCh(int);
    
    int getZn();
    void setZn(int );
    
    const Drob &operator=(const Drob &d);
    const Drob &operator=(const Drob *d);
    const Drob &operator+(const Drob &d)const;
    const Drob &operator*(const Drob &d)const;
    const Drob &operator*(const int &d)const;
    const Drob &operator-(const Drob &d)const;
     const Drob &operator/(const Drob &d)const;
    const Drob &operator/(const size_t &d)const;
    
    bool operator<(const Drob &d)const;
     bool operator>(const Drob &d)const;
    bool operator==(const Drob &d)const;
    const Drob &operator[](size_t index);
    
    friend std::ostream &operator<<(std::ostream &out, const Drob &d);
    friend std::istream &operator>>(std::istream &in,  Drob &d);
};
