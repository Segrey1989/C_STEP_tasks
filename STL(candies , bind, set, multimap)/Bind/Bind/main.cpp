#include <iostream>
#include<iterator>
#include<vector>
//#include<windows.h>
using namespace std;

int main(){
        vector<int> vec(20);
        for_each(vec.begin(), vec.end(), [&vec](int){
            vec.insert(vec.begin(),rand() % 100);
        });
            vec.resize(20);
    
    cout << "Первоначальный вектор \n";
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    
    cout << "После использования bind \n";
        copy_if(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "), bind(greater<int>(), placeholders::_1, 20));
        cout << endl;
    
}
