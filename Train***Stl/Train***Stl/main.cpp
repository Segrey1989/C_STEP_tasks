
#include "Header.h"

class PunktFinder{
    const string request;
public:
    PunktFinder(const string &str) : request(str){}
    bool operator()(const Train &tr){
        return !request.compare(tr.destination);
    }
};

class TimeFrame{
    const string time1;
    const string time2;
public:
    TimeFrame(const string &t1, const string &t2) : time1(t1), time2(t2){}
    bool operator()(const Train &tr){
        return ((tr.time > time1) && (tr.time < time2)) ? true : false;
    }
};

// для replace
bool need_change(const Train &tr);
//для erase
bool find_city(const Train &tr);

int main(){
    vector<Train> railway;
    fstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Train***Stl/Train***Stl/Scedule.txt", ios::in);
    if (!in.is_open()){
        cout << "File opening error\n";
        return 0;
    }
    
    istream_iterator<Train> it(in), cur_it;
    ostream_iterator<Train> out(cout);
    
    // чтение в файл
    copy(it, cur_it, back_inserter(railway));
    
    //отсортировали по времени
    cout << "Sorted by time: \n";
    sort(railway.begin(), railway.end(), [](const Train &a, const Train &b){return a.time < b.time; });
    //вывод в консоль
    copy(railway.begin(), railway.end(), out);
    
    // поиск по пункту назначения
    cout << "Trains with same destination: \n";
    string request;
    cout << "Enter a destination: \n";
    cin >> request;
    PunktFinder f(request);
    //через лямбда-функцию
//    copy_if(railway.begin(), railway.end(), out, [request](const Train &tr){return !request.compare(tr.destination);});
     copy_if(railway.begin(), railway.end(), out, f);
    
    // поиск в диапазоне времени
    cout << "Trains between time1 and time2:\n";
    string time1, time2;
    cout << "Enter time1 and time2: \n";
    cin >> time1 >> time2;
    TimeFrame between(time1, time2);
    copy_if(railway.begin(), railway.end(), out, between);
    //через лямбда-функцию
//    copy_if(railway.begin(), railway.end(), out, [time1, time2](const Train &tr){return ((tr.time > time1) && (tr.time < time2)) ? true : false;});
    
    //замена на заданный пункт назначения
    // замена пункта Минск и вывод
    cout << "Minsk was replaced for Berlin:\n";
    string new_dest;
   // cout << "Enter new destination point: \n";
  //  cin >> new_dest;
    Train temp("Berlin", "007", "20.15");
    replace_if(railway.begin(), railway.end(),need_change, temp);
    
    // удаление элемента из вектора
    cout << "Train to Moskow was deleted: \n";
    auto it_del = find_if(railway.begin(), railway.end(),find_city);
    railway.erase(it_del);
    copy(railway.begin(), railway.end(), out);
    
   // system("pause");
    return 0;
}

// для replace
bool need_change(const Train &tr){
    return !tr.destination.compare("Minsk");
}

bool find_city(const Train &tr){
    return !tr.destination.compare("Moskow");
}
