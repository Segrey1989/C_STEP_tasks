#include "DList.h"
using namespace std;

bool check_same_num(int);
int mult(int, int);
int find_max(DList<int> &);

int main(){
    DList<int> list, list_max;
    
    // ввод цифр, пока не встретится не int символ
     int temp = 0;
     cout << "Enter the number: ";
    while(cin >> temp){
        if(check_same_num(temp) && (!list.is_empty()))
            list.pop_back();
        list.push_back(temp);
        cout << "Enter the number: ";
    }
    
    list.insert_on_position(3);
    
    // поиск середины списка
    typename DList<int>:: iterator m = list.Begin(), n = m;
    int i = list.get_size()/2;
    while(i--){
        m++; n++;
    }
    --n;

  //   cout<< *n <<" "<<  *m << endl;
    for(;(m != list.End()) && (n != list.Begin()) ; m++, n--){
            int temp = mult(*n, *m);
            list_max.push_back(temp);
        }
   
    // через индексы то же
//    for(int m = list.get_size()/2, n = m - 1;  m < list.get_size() && n > 0 ; m++, n--){
//        int temp = mult(list[n], list[m]);
//        list_max.push_back(temp);
//    }
   
    cout << "list: \n" << list << endl;
    cout << "list_max: \n" <<list_max << endl;
    cout<< "max: " << find_max(list_max)<< endl;

    return 0;
    
}



// проверка двузначных чисел
bool check_same_num(int num){
    return (num % 10 == num / 10) ? true : false;
}

// умножение
int mult(int a, int b){
    return a * b;
}

// поиск максимума
int find_max(DList<int> &l){
    int max = l[0];
    for(typename DList<int>:: iterator i = ++l.Begin(); i != l.End(); ++i)
        if (*i > max)
            max = *i;
    return max;
}
