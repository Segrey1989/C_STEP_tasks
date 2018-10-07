#ifndef Header_h
#define Header_h
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

struct Train{
    
    string destination;
    string number;
    string time;
    bool express;
   
    Train() = default;
    Train(string dest, string num, string t, bool exp = 0):destination(dest), number(num), time(t), express(exp){}
    
    Train &operator=(const Train &tr);
    friend istream & operator>> (istream &in, Train &tr);
    friend ostream & operator<< (ostream &out, const Train &tr);
    
};

Train &Train::operator=(const Train &tr){
    if(this != &tr){
        destination = tr.destination;
//        number = tr.number;
//        express = tr.express;
//        time = tr.time;
    }
    return *this;
}

istream &operator>> (istream &in, Train &tr){
    in >> tr.destination >> tr.number >> tr.time >> tr.express;
    return in;
}

ostream & operator<< (ostream &out, const Train &tr){
    out << tr.destination << "\n" << tr.number << "\n" << tr.time << "\n" << tr.express << "\n\n";
    return out;
    
};


#endif
