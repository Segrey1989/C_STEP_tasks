#include <iostream>
#include <string>
#include<iterator>
#include<set>
//#include<windows.h>
using namespace std;


int main(){
    
    //setlocale(0, "");
   // SetConsoleCP(1251);
   // SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian_Russia.1251") ;
    
    set<string> cost = {"пескарь", "мидия", "рак"};
    set<string> deep = { "бычок", "окунь", "мидия" };
    
    /*set<string> cost = { "gudgeon", "mussel", "cancer" };
     set<string> deep = { "goby fish", "bass", "mussel" };*/
    
    set<string> all_river, all, waterside;
    
    cout << "Водится по всей реке: \n";
    set_intersection(cost.begin(), cost.end(), deep.begin(), deep.end(), inserter(all_river, all_river.begin()));
    copy(all_river.begin(), all_river.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    
    cout << "Все обитатели реки: \n";
    copy(cost.begin(), cost.end(), inserter(all, all.begin()));
    copy(deep.begin(), deep.end(), inserter(all, all.end()));
    copy(all.begin(), all.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    
    cout << "Только у берега: \n";
    set_difference(cost.begin(), cost.end(), deep.begin(), deep.end(), inserter(waterside, waterside.begin()));
    copy(waterside.begin(), waterside.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    
    //system("pause");
    return 0;
    
}
