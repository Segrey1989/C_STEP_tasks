/*
 Создайте vector<string>, считайте в него список слов из текстового файла. Выполните:
 -    сортировку списка;
 -    печать отсортированного списка;
 -    печать элементов списка, начинающихся на заданную букву
 -    удаление элементов списка на заданную букву;
 -    печать списка после удаления элементов.
 Указание:
 Удаление элементов списка, начинающихся на заданную букву реализовать следующим образом:
 vector<string>::iterator p1=find_if(v.begin(), v.end(), initial);
 vector<string>::iterator p2=find_if(p1, fruit.end(), initial_not);
 v.erase(p1, p2);
 здесь initial() − вами реализованная функция поиска слова на заданную букву.

 */


#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
#include<algorithm>
using namespace std;


bool initial(const string &word);
bool initial_not(const string &word);


int main(){
    string word;
    vector<string> txt;
    fstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Stl(first lesson)/Find, sort/Find, sort/Text.txt", ios::in);
    if (!in){
        cout << "Opening file error \n";
        return 0;
    }

    while (in >> word)
    txt.push_back(word);

    sort(txt.begin(), txt.end()); // сортировка

    cout << "Sort txt: \n";
    for (vector<string>::iterator beg = txt.begin(); beg != txt.end(); beg++)
        cout << *beg << "\n";

    cout << "\nThe firt coincidence \n";
    vector<string>::iterator ptr, ptr_del;
    ptr = find_if(txt.begin(), txt.end(), initial);
    cout << *ptr << "\n";
   
    ptr_del = find_if(ptr, txt.end(), initial_not);

    cout << "\nAll words on coincidence letter\n";
    for (ptr; ptr != ptr_del; ptr++)
        cout << *ptr << "\n";


    cout << "\nAll words on coincidence letter were deleted\n";
    ptr = find_if(txt.begin(), txt.end(), initial);
    txt.erase(ptr, ptr_del);
    for (vector<string>::iterator beg = txt.begin(); beg != txt.end(); beg++)
        cout << *beg << "\n";


   // system("pause");
    return 0;
}

bool initial(const string &word){

    return word[0] == 'w' ? true : false;
}

bool initial_not(const string &word){
    return word[0] != 'w' ? true : false;
}

