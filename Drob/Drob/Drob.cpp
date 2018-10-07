#include "Drob.h"


Drob::Drob(int _ch, int _zn): ch(_ch){
    if(_zn > 0){
        zn =_zn;
       Reduce();
    }
    else
        exit(1);
};

Drob::Drob (const Drob &d){
    ch = d.ch;
    zn = d.zn;
    Reduce();
}

int Drob::getCh(){return ch;}
void Drob::setCh(int _ch){
    ch = _ch;
}

int Drob::getZn(){return zn;}
void Drob::setZn(int _zn){
    if(_zn > 0)
        zn = -zn;
}

const Drob &Drob::operator=(const Drob &d){
    ch = d.ch;
    zn = d.zn;
    Reduce();
    return *this;
}

const Drob &Drob::operator=(const Drob *d){
    Drob t = *d;
    ch = t.ch;
    zn =t.zn;
    Reduce();
    return *this;
}

const Drob &Drob::operator+(const Drob &d)const{
    Drob temp;
    temp.ch = ch * d.zn + d.ch *zn;
    temp.zn = zn * d.zn;
    temp.Reduce();
    return Drob(temp);
}

const Drob &Drob::operator-(const Drob &d)const{
    Drob temp;
    temp.ch = ch * d.zn - d.ch *zn;
    temp.zn = zn * d.zn;
    temp.Reduce();
    return Drob(temp);
}

const Drob &Drob::operator/(const Drob &d)const{
     Drob temp;
    temp.ch = ch * d.zn;
    temp.zn = zn * d.ch;
    temp.Reduce();
    return Drob(temp);
}

const Drob &Drob::operator*(const Drob &d)const{
     Drob temp;
    temp.ch = ch * d.ch;
    temp.zn = zn * d.zn;
    temp.Reduce();
    return Drob(temp);
}

const Drob &Drob::operator*(const int &i)const{
    Drob temp;
    temp.ch = ch * i;
    temp.zn = zn;
    temp.Reduce();
    return Drob(temp);
}

const Drob &Drob::operator/(const size_t &d)const{
    Drob temp;
    temp.ch = ch;
    temp.zn = zn * d;
    temp.Reduce();
    return Drob(temp);
}

bool Drob::operator==(const Drob &d)const{
    if(ch == d.ch && zn == d.zn)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &out, const Drob &d){
    out << d.ch << "/" << d.zn << " ";
    return out;
}

std::istream &operator>>(std::istream &in,  Drob &d){
    char buf[20];
    in >> buf;
    
     d.ch = atoi(&buf[0]);
    char *ptr = nullptr;
    ptr = strpbrk(buf, "/");
    d.zn = atoi(++ptr);
    return in;
}


bool Drob::operator<(const Drob &d)const{
    int tch = ch * d.zn;
    int dch = d.ch * zn;
    return tch < dch ? true : false;
}


bool Drob::operator>(const Drob &d)const{
    int tch = ch * d.zn;
    int dch = d.ch * zn;
    return tch > dch ? true : false;
}


int gcd(int a, int b)
{
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}

void Drob::Reduce()
{
    int var = 0;
    var = gcd(ch, zn);
    ch /= var;
    zn /= var;
}
