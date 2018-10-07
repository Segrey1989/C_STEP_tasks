#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool check(fstream &);

int main()
{
    fstream in("/Users/Siarhei/Desktop/STEP/C++/Insert_unsigned(string)/Insert_unsigned(string)/input.txt", ios::in);
    fstream out("/Users/Siarhei/Desktop/STEP/C++/Insert_unsigned(string)/Insert_unsigned(string)/output.txt", ios::out);
    if (!check(in))
        return 0;
    
    string str;
    string ins = "unsigned ";
    while (!in.eof())
    {
        int pos = 0;
        getline(in, str);
        while (pos != string::npos)
        {
            pos = str.find("char", pos);
            if (pos == -1) break;
            str.insert(pos, ins);
            pos = pos + ins.length()+4;
        }
        out << str << "\n";
    }
    return 0;
}



bool check(fstream & in)
{
    if (!in)
    {
        cout << "File opening error \n";
        return 0;
    }
    return true;
}

