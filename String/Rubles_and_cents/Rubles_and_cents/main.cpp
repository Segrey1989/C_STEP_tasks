/*
 Дано дробное число типа double, представляющее собой денежную сумму в рублях и копейках. Преобразовать число в строку, разделив тройки цифр в рублях пробелом; в конце добавить слово «рублей», «рубля» или «рубль»; после копеек вставить сокращение «коп.».  Например, 123 765 рублей 98 коп.
 */

#include <iostream>
#include <string>
#include <fstream>

char* form_end(int, char*);
std::string sep_num(std::string);
bool is_price(std:: string str, size_t pos);

int main(){
    std::fstream in ("/Users/Siarhei/Desktop/STEP/C++/Rubles_and_cents/Rubles_and_cents/input.txt", std::ios::in),
    out("/Users/Siarhei/Desktop/STEP/C++/Rubles_and_cents/Rubles_and_cents/output.txt", std::ios::out);
    
    if (!in.is_open()) return 0;
    
    std::string str, temp_s;
    int int_val = 0, rest = 0;
    float  float_val = 0;
    
 while (in){
    getline(in, str);
    size_t pos_beg = 0, pos_end = 0;
    
    pos_end = str.find_first_of("1234567890", pos_beg);
     if(pos_end != std::string::npos)
        while(pos_end != std::string::npos){
             temp_s = "";
            float_val = std::stof(str.substr(pos_end) , &pos_beg);
            
            if(is_price(str, pos_end)){
                
            int_val = std::stoi(str.substr(pos_end) , &pos_beg);
            rest = (float_val - int_val) * 100;
            temp_s.append(sep_num(std::to_string(int_val)));
            temp_s.append(form_end(int_val, "rubl"));
            temp_s.append(std::to_string(rest));
            temp_s.append(form_end(rest, "copejka"));
                // +1 - учитывание точки
            str.replace(pos_end, std::to_string(int_val).length() + std::to_string(rest).length() + 1, temp_s);
            }
            
            // смещение, если дробное число и смещение, если нет
            if(!is_price(str, pos_end))
            pos_beg = pos_end + std::to_string(int_val).length() + std::to_string(rest).length() + 1;
            else
            pos_beg = pos_end + temp_s.size();
            
            pos_end = str.find_first_of("1234567890", pos_beg);
        }

  out << str<< "\n";
    }
   // system("pause");
}


// форматирование окончаний
char* form_end(int val, char* money){
    if(strcmp(money,"rubl") == 0){
    if(val % 10 == 1 && val % 100 != 11)
        return " rubl ";
    else if((val % 10 == 0) || (val % 10 >=5 && val % 10 <= 9) || (val % 100 >= 5 && val % 100 <= 19))
        return " rublej ";
    else
        return " rubla ";
    }
    else if(strcmp(money,"copejka") == 0){
        if(val % 10 == 1 && val % 100 != 11)
            return " copejka ";
        else if((val % 10 == 0) || (val % 10 >=5 && val % 10 <= 9) || (val % 100 >= 5 && val % 100 <= 19))
            return " copeek ";
        else
            return " copejki";
        
    }

    return 0;
}

// разбиение рублей по 3 цифры
std::string sep_num(std::string str){
    int count=0;
    if(str.length() > 3)
        for(size_t i = str.length()-1; i != 0; i--){
             count++;
            if(count == 3 ){
                str.insert(i, 1, ' ');
                count = 0;
            }
        }
    return str;
}

// отсеивание дат и прочих целых чисел
bool is_price(std:: string str, size_t pos){
    //std::cout << str[pos+7] << "\n";
    while(str[pos] != ' '){
        if(str[pos] == '.' && isdigit(str[pos+1]))
            return true;
        pos++;
    }
    return false;
}
