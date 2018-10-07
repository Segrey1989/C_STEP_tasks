/*
 . Дано следующее мульти-отображение:
 {
 { 1, L"адзін" },
 { 1, L"один" },
 { 1, L"one" },
 { 2, L"два" },
 { 2, L"two" },
 { 3, L"тры" },
 { 3, L"три" },
 { 3, L"three" },
 { 4, L"чатыры" },
 { 4, L"четыре" },
 { 4, L"four" },
 }
 При помощи методов lower_bound и upper_bound выведите все доступные варианты написания числа N. Если нету ни одного варианта, выведите соответствующее сообщение. Проверьте работу для N=3, N=5.

 */
#include <iostream>
#include <string>
#include<iterator>
#include<map>
//#include<windows.h>
using namespace std;

//ostream &operator<<(ostream &out, const pair<int, string> &p){
//    out << p.first << " " << p.second << "\n";
//    return out;
//}

int main(){
     setlocale(LC_ALL,"Russian_Russia.1251") ;
     
     multimap<int, string> numbers = {
     { 1, "адзін" },
     { 1, "один" },
     { 1, "one" },
     { 2, "два" },
     { 2, "two" },
     { 3, "тры" },
     { 3, "три" },
     { 3, "three" },
     { 4, "чатыры" },
     { 4, "четыре" },
     { 4, "four" },
     { 6, "six" }
     };
    int num = 0;
    cout << "Введите число: \n";
    cin >> num;
    
     std::multimap<int, string>::iterator low,up;
    low = numbers.lower_bound(num);
    up = numbers.upper_bound(num);

    if((*low).first != num)
        cout << "Нет соответствий\n";
    else
    for(auto it = low; it != up; it++)
        cout << (*it).second << endl;
   
  //  system("pause");
    return 0;
    
}
