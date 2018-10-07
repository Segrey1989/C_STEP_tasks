/*
В тексте на английском языке заменить все местоимения «we»  на местоимения «they».
*/
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::fstream in("/Users/Siarhei/Desktop/STEP/C++/We->they_change/We->they_change/in.txt", std::ios::in);
     std::fstream out("/Users/Siarhei/Desktop/STEP/C++/We->they_change/We->they_change/Output.txt", std::ios::out);
    if(in.is_open()){
        std::string str;
        
        
        while(!in.eof()){
            size_t pos = 0;
            getline(in, str);
            
            // замена прописных букв
            while(pos != std::string::npos){
            pos = str.find("we", pos);
                if(pos == -1) break;
                str.replace(pos, 2, "they");
            }
            //замена заглавной буквы
            pos = 0;
            while(pos != std::string::npos){
                pos = str.find("We", pos);
                if(pos == -1) break;
                str.replace(pos, 2, "They");
            }
            
            out << str << "\n";
        }
    }
    return 0;
}
