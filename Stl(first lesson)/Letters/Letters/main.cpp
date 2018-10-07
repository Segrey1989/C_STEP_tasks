#include<iostream>
#include<vector>
#include<iterator>

using namespace std;


int main(){
    vector<char> abc;
    vector<char>::iterator beg ;
    vector<char>::reverse_iterator r_beg;
    for (int i = 65; i < 91; i++)
        abc.push_back(i);

    for (beg = abc.begin(); beg != abc.end();beg++){
        cout << *beg << " ";

    }
    cout << endl;

    for (r_beg = abc.rbegin(); r_beg !=abc.rend() ; r_beg++)
        cout << *r_beg << " ";
    cout << endl;

    system("pause");
    return 0;
}
