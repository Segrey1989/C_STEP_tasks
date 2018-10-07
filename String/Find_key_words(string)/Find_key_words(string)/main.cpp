/*
 Дана программа на C++. Записать в выходной файл построчно все ключевые слова, встречающиеся в этой программе, указав количество появлений ключевого слова в ней.
 Удалить наиболее часто встречаемое ключевое слово.
 */

#include <iostream>
#include <string>
#include <fstream>

size_t find_max_in_arr(const size_t *, size_t);

int main() {
    std::fstream in("/Users/Siarhei/Desktop/STEP/C++/Find_key_words(string)/Find_key_words(string)/in.txt", std::ios::in);
    std::fstream out("/Users/Siarhei/Desktop/STEP/C++/Find_key_words(string)/Find_key_words(string)/out.txt", std::ios::out);
    std::fstream out_changed("/Users/Siarhei/Desktop/STEP/C++/Find_key_words(string)/Find_key_words(string)/out__changed_in", std::ios::out);
    
    if(in.is_open()){
       const size_t size = 9;
        std::string str;
        std::string key_arr[size] = {"main", "int","#include", "while", "return", "string", "break", "std", "if"};
        size_t count_word_arr[size] = {0};
        
        //подсчет количества ключевых слов
        // проходим по файлу столько раз, сколько элементов в key_arr
      for(size_t i = 0; i < size; i++){
             size_t counter = 0;

        while(getline(in, str)){
            size_t pos = 0;

            while(pos != std::string::npos){
                pos = str.find(key_arr[i], pos);
                if(pos == -1) break;
                counter++;
                pos = pos + key_arr[i].length();
            }
        }
          
        out << key_arr[i] << ": " << counter << "\n";
          count_word_arr[i] = counter;
          
          in.close();
           in.open("/Users/Siarhei/Desktop/STEP/C++/Find_key_words(string)/Find_key_words(string)/in.txt", std::ios::in);
          
          if(!in.is_open()){
              std::cout << "File opening error in second opening\n";
              return 0;
          }
           // in.seekg(0, std::ios::beg); //не работает
    }
        
        // максимально повторяющееся ключевое слово
        size_t max = find_max_in_arr(count_word_arr, size);

        // удаление наиболее часто встречающегося слова
        while(in){
            getline(in, str);
            size_t pos = 0;
        
            while(pos != std::string::npos){
                pos = str.find(key_arr[max], pos);
                if(pos == -1) break;
                str.replace(pos, key_arr[max].length(), "");
            }
             out_changed << str << "\n";
       }
    }
    else
        std::cout << "File opening error in first opening \n";
    return 0;
}



size_t find_max_in_arr(const size_t * arr, size_t size){
    size_t temp = arr[0];
    size_t index = 0;
    
    size_t i = 1;
    for(; i < size; i++)
        if(arr[i] > temp){
            temp = arr[i];
            index = i;
        }
    return index;
}
