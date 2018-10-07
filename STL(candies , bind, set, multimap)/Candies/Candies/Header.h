#ifndef Header_h
#define Header_h
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
#include<sstream>
#include<iterator>
using namespace std;

class Candy{
    string name;
    size_t sugar;
    size_t weight;
public:
    Candy():name(""), sugar(0), weight(0){}
    Candy(string _name, size_t s, size_t w):name(_name), sugar(s), weight(w){}
//    Candy(const Candy &cnd){
//        name = cnd.name;
//        sugar = cnd.sugar;
//        weight = cnd.weight;
//    }
    virtual ~Candy(){}
    
    void setName(const string _name){name = _name;};
    void setSugar(const size_t sug){sugar = sug;};
    void setWeight(const size_t w){weight = w;};
    
    string getName()const{return name;};
    size_t getSugar()const{return sugar;};
    size_t getWeight()const{return weight;};
    
    bool operator>(const Candy &c){
        return (weight > c.weight) ? true:false;}
    bool operator<(const Candy &c){
        return (weight < c.weight) ? true:false;}
    bool operator==(const Candy &c){
        return (weight == c.weight) ? true:false;}
    
    Candy &operator=(const Candy &c);
    
    virtual void print(ostream &out)const = 0;
    virtual void read(istream &in) = 0;
};

void Candy::print(ostream &out)const{
    out<< "name: " <<name <<"\nsugar: " <<sugar << "\nweight: "<< weight << endl;
}

void Candy:: read(istream &in){
    string type;
    in >> type >> name >> sugar >> weight;
}

Candy &Candy::operator=(const Candy &c){
    if(this != &c){
        name = c.name;
        sugar = c.sugar;
        weight = c.weight;
    }
    return *this;
}

/**************************************************/
class Choc: public Candy{
    size_t cocao;
public:
    Choc(): Candy(), cocao(0){}
    Choc(string _name, size_t _sugar, size_t _weight, size_t _cocao):
    Candy(_name, _sugar, _weight), cocao(_cocao){}
//    Choc(const Choc &choc): Candy(choc){
//        cocao = choc.cocao;
//    }
    ~Choc(){}
    
    Choc &operator=(const Choc &c){
        if(this != &c){
            setName(c.getName());
            setSugar(c.getSugar());
            setWeight(c.getWeight());
            cocao = c.cocao;
        }
        return *this;
    }
    
    bool operator>(const Choc &c){
        return (getWeight() > c.getWeight()) ? true:false;}
    bool operator<(const Choc &c){
        return (getWeight() < c.getWeight()) ? true:false;}
    bool operator==(const Choc &c){
        return (getWeight() == c.getWeight()) ? true:false;}
    
     virtual void print(ostream &out)const;
     virtual void read(istream &in);
};

void Choc::print(ostream &out)const{
    Candy::print(out);
    out << "cocao: " << cocao << endl;
   // out <<"sugar: " <<getSugar() << "\nweight: "<< getWeight() << "\ncocao: " << cocao << endl;
}
void Choc::read(istream &in){
    string type;
    Candy::read(in);
    in >> cocao;
}

/**************************************************/

class Caramel: public Candy{
    string flavour;
public:
    Caramel(): Candy(), flavour(""){}
    Caramel(string _name, size_t _sugar, size_t _weight, string _flavour):
    Candy(_name, _sugar, _weight), flavour(_flavour){}
//    Caramel(const Caramel &car): Candy(car){
//        flavour = car.flavour;
//    }
    ~Caramel(){}
    
    bool operator>(const Caramel &c){
        return (getWeight() > c.getWeight()) ? true:false;}
    bool operator<(const Caramel &c){
        return (getWeight() < c.getWeight()) ? true:false;}
    bool operator==(const Caramel &c){
        return (getWeight() == c.getWeight()) ? true:false;}
    
    Caramel &operator=(const Caramel &c){
        if(this != &c){
            setName(c.getName());
            setSugar(c.getSugar());
            setWeight(c.getWeight());
            flavour = c.flavour;
        }
        return *this;
    }
    
    virtual void print(ostream &out)const;
    virtual void read(istream &in);
    friend istream &operator>>(const istream &in, Caramel &c);

};

void Caramel::print(ostream &out)const{
    Candy:: print(out);
    out << "flavour: " << flavour << endl;
    //out <<"sugar: " <<getSugar() << "\nweight: "<< getWeight() << endl;
}

void Caramel::read(istream &in){
     string type;
    Candy::read(in);
    in >> flavour;
}

/**************************************************/

class With_filler: public Choc{
    string filler;
    size_t quantity;
public:
    With_filler(): Choc(), filler(""), quantity(0){}
    With_filler(string _name, size_t _sugar, size_t _weight, size_t _cocao, string _filler, size_t _quantity):
    Choc(_name, _sugar, _weight, _cocao), filler(_filler), quantity(_quantity){}
//    With_filler(const With_filler &wf): Choc(wf){
//        filler = wf.filler;
//        quantity = wf.quantity;
//    }
    ~With_filler(){}
    
    bool operator>(const With_filler &c){
        return (getWeight() > c.getWeight()) ? true:false;}
    bool operator<(const With_filler &c){
        return (getWeight() < c.getWeight()) ? true:false;}
    bool operator==(const With_filler &c){
        return (getWeight() == c.getWeight()) ? true:false;}
    
    virtual void print(ostream &out)const;
    virtual void read(istream &in);
};

void With_filler::print(ostream &out)const{
    Choc::print(out);
    out << "filler: " << filler  << "\n";
    out <<"quantity: " << quantity << "%" << endl;
    
}
void With_filler::read(istream &in){
    string type;
    Choc::read(in);
    in >> filler >> quantity;
}

Candy* getPtr(istringstream &obj){
    string type;
    Candy *candy = nullptr;
    obj >> type;
    if(type == "choc")
        candy = new Choc();
    else if(type == "car")
        candy = new Caramel();
    else
        candy = new With_filler;    
    return candy;
}
ostream &operator<<(ostream &out, const Candy &obj){
    obj.print(out);
    out << endl;
    return out;
}
#endif /* Header_h */
