/*Создайте vector<int>, считайте в него список чисел из текстового файла. Выполните, не используя циклов:
-    Подсчет количества чисел, равных заданному;
-    Подсчет количества чисел, удовлетворяющих условию, например, «больше, чем 15»;
-    Подсчет общего количества чисел;
-    Подсчет суммы чисел;
-    Подсчет среднего арифметического чисел.

Подсказка!!! Использовать алгоритмы count, count_if, accumulate.
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

bool bigger_15(int n){
    return n > 15? true:false;
}

int main(){
    int number;
    vector<int> numbers;
    fstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Stl(first lesson)/Count/Stl(first lesson)/Numbers.txt", ios::in);
    if (!in){
        cout << "Opening file error \n";
        return 0;
    }
    while (in >> number)
        numbers.push_back(number);
    
    cout << "All numbers in vector \n";
    for (vector<int>::iterator beg = numbers.begin(); beg != numbers.end(); beg++)
        cout << *beg << " ";
    cout << endl;
    
    cout << "\nNumbers equal a given number: \n";
    int countNum = count(numbers.begin(), numbers.end(), 8);
    cout << countNum << endl;
    
      cout << "\nNumbers more then 15: \n";
    int count_15 = count_if(numbers.begin(), numbers.end(), bigger_15);
    cout << count_15 << endl;
    
     cout << "\nCount of all elements: \n";
    int count_all = 0;
    for (vector<int>::iterator beg = numbers.begin(); beg != numbers.end(); beg++, count_all++);
    cout << count_all;
    //cout << numbers.size();
    cout << endl;
    
    cout << "\nSumma: \n";
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << sum << endl;
    
     cout << "\nAverage: \n";
    double av = (double)sum/count_all;
    cout << av << endl;
    
   // system("pause");
    return 0;
}
