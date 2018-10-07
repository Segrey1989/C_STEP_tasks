/*
 Рациональная (несократимая) дробь представляется парой целых чисел (a,b), где a − числитель, b − знаменатель. Создать класс  Rational для работы с рациональными дробями. Реализовать  конструкторы:   копирования и инициализации, а также методы:
 сложение add, (a,b) + (c,d) = (ad+bc,bd);
 умножение mul, (a,b) * (c,d) = (ac, bd);
 деление div, (a,b)/(c,d) = (ad,bc);
 сравнение equal, greater, less;
 вывод print.
 Реализовать приватную функцию сокращения дроби reduce, которая обязательно вызывается при выполнении арифметических операций.

 */

#include <iostream>

class Drob
{
private:
    int ch;
    int zn;
    void Reduce();
    void format(const Drob &rhc)const;
public:
    //Drob() { std::cout << "constructor without parameters\n"; }
    Drob(int _ch=1, int _zn=1):ch(_ch), zn(_zn!=0 ? _zn : 1 ){  }
    Drob(const Drob &rhc):ch(rhc.ch), zn(rhc.zn){}
    ~Drob(){}
    
    int Getch(){return ch;}
    int Getzn(){return zn;}
    
    void Set(int _ch, int _zn = 1);
    void Print()const;
    const Drob Add(const Drob &rhc)const;
    const  Drob Mul(const Drob &rhc)const;
    const Drob Div(const Drob &rhc)const;
    bool Equal(const Drob &rhc)const;
    bool Greater(const Drob &rhc)const;
    bool Less(const Drob &rhc)const;
};

void Drob::Set(int _ch, int _zn){
    if (_zn){
        ch = _ch;
        zn = _zn;
    }
    Reduce();
}


 void Drob::Print()const{
    std::cout << ch << "/" << zn << std::endl;
}

const Drob Drob::Add(const Drob &rhc)const{
    format(rhc);
    Drob sum(ch * rhc.zn + zn * rhc.ch, zn * rhc.zn);
    sum.Reduce();
    return sum;
}


const Drob Drob::Mul(const Drob &rhc)const {
   format(rhc);
    Drob mult(ch * rhc.ch, zn * rhc.zn);
    mult.Reduce();
    return mult;
}


const Drob Drob::Div(const Drob &rhc)const {
    format(rhc);
   // Drob div(Getch() * rhc.Getzn(), Getzn() * rhc.Getch());
    Drob div(ch * rhc.zn, zn * rhc.ch);
    div.Reduce();
    return div;
}


bool Drob::Equal(const Drob &rhc)const{
   format(rhc);
    return (ch * rhc.zn) == (rhc.ch * zn) ? true : false;
}


bool Drob::Greater(const Drob &rhc)const{
    format(rhc);
     return (ch * rhc.zn) > (rhc.ch * zn) ? true : false;
}


bool Drob::Less(const Drob &rhc)const{
    format(rhc);
     return (ch * rhc.zn) < (rhc.ch * zn) ? true : false;
}


//  вспомогательные функции

//сокращение дробей
void Drob::Reduce() {
    int a = ch, b = zn, nod = 0;
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    nod = a + b;
    
    ch /= nod;
    zn /= nod;
}

// вывод дробей в консоль
void Drob::format(const Drob &rhc)const {
    std::cout << "Drob 1: ";
    Print();
    std::cout << "Drob 2: ";
    rhc.Print();
}



int main()
{
    Drob obj1, obj2(3,4), obj3, objMul, objDiv;
    obj1.Set(10, 5);
    
    std::cout << "\nAdding: \n";
    obj3 = obj1.Add(obj2);
    obj3.Print();
    
    std::cout << "\nMultiplication: \n";
    objMul = obj3.Mul(obj1);
    objMul.Print();
    
    std::cout << "\nDivision: \n";
    objDiv = obj1.Div(obj3);
    objDiv.Print();
    
    std::cout << "\nEqual: \n";
    obj2.Set(5,6);
    std::cout << obj1.Equal(obj2) << std::endl;
    
    std::cout << "\nGreater: \n";
    std::cout << obj1.Greater(obj2) << std::endl;
    
    std::cout << "\nLess: \n";
    std::cout << obj1.Less(obj2) << std::endl;
    
    //std::cin.get();
    return 0;
    
}

/*
 //вариант reduce через рекурсию
 int gcd(int a, int b)
{
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}

void Drob::reduce()
{
    int var = 0;
    var = gcd(ch, zn);
    ch /= var;
    zn /= var;
}
 */


