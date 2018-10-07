#ifndef Header_h
#define Header_h
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

struct Clumb{
    size_t id;
    string form;
    vector<string> flowers;
    
    friend istream &operator>>(istream &in, Clumb &cl);
    friend ostream &operator<<(ostream &out, const Clumb &cl);
};

istream &operator>>(istream &in, Clumb &cl){
    string str, flower;
    getline(in, str);
    istringstream str_st(str);
    str_st >> cl.id >> cl.form;
    cl.flowers.clear();
    while (str_st >> flower)
        cl.flowers.push_back(flower);
    
    return in;
}

ostream &operator<<(ostream &out, const Clumb &cl){
    out << cl.id << " "<< cl.form << " ";
    copy(cl.flowers.begin(), cl.flowers.end(), ostream_iterator<string> (out, " "));
    return out;
}

ostream &operator<<(ostream &out, const pair<string, Clumb> &obj){
    return out << obj.second << endl;
}

ostream &operator<<(ostream &out, const pair<string, size_t> &obj){
    return out << obj.first << ": " << obj.second << endl;
}

class FindFlower{
    string name;
public:
    FindFlower(const string fl) : name(fl){};
    bool operator()(const pair<string, Clumb> &p){
        return !(find(p.second.flowers.begin(), p.second.flowers.end(), name) == p.second.flowers.end());
    }
    string getName()const{ return name;}
};


#endif
