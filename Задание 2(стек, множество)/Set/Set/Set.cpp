
#include "Header.h"

Set::Set(): size(0), data(new char[1]){
    *data = '\0';
}

Set::Set(const char* str) : size(strlen(str)), data(new char[size+1]){
    strcpy(data, str);
    }

Set::Set(size_t _size): size(_size), data(new char[size+1]){}

Set::Set(const Set &obj): size(strlen(obj.data)), data(new char[size +1]){
    strcpy(data, obj.data);
}


Set & Set::operator=(const Set &obj){
    if(this != &obj){
        delete[]data;
        size = strlen(obj.data);
        data = new char[size+1];
        strcpy(data, obj.data);
    }
    return *this;
}

Set & Set::operator=(const char *str){
    delete[]data;
    size = strlen(str);
    data = new char[size+1];
    strcpy(data, str);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Set &obj){
    out << obj.data << " ";
    return out;
}

std::istream &operator>>(std::istream &in, Set &obj){
    char buff[255];
    std::cout << "Enter the string \n";
    
    in >> buff;
    obj.size = strlen(buff);
    delete[]obj.data;
    obj.data = new char[obj.size + 1];
    strcpy(obj.data, buff);
    return in;
}


const Set Set::operator*(const Set &obj)const{
    char buff[255];
    size_t size_buff = 0;
    
    char *ptr = strpbrk(data, obj.data);
    while(ptr !=NULL){
        buff[size_buff++] = *ptr;
        ptr = strpbrk(ptr+1, obj.data);
    }
    buff[size_buff] = '\0';
    return Set(buff);
}

const Set Set::operator+(const Set &obj)const{
    char buff[255];
    size_t buff_size = size;
    strcpy(buff, data);
    
    char *ptr = obj.data;
    while(*ptr != '\0'){
        if(!check(*ptr))
        buff[buff_size++] = *ptr;
        ptr++;
    }
     buff[buff_size] = '\0';
    return Set(buff);
}


const Set Set::operator-(const Set &obj)const{
    char buff[255];
    size_t buff_size = 0;
    char *ptr = data;
    
    char *el = nullptr;
    while(*ptr != '\0'){
    el = strchr(obj.data, *ptr);
        if(!el)
            buff[buff_size++] = *ptr;
        ptr++;
    }
    buff[buff_size] = '\0';
    return Set(buff);
}

//включение множества
bool Set::operator<(const Set obj)const{
   char *ptr = data, *el = nullptr;
    while(*ptr != '\0'){
        el = strchr(obj.data, *ptr);
        if(!el)
            return false;
        ptr++;
    }
    return true;
}

//эквивалентность множеств
bool Set::operator==(const Set obj)const{
  if(size != obj.size)
      return false;
    
    char *el = obj.data;
    while(*el != '\0'){
        if(!check(*el))
            return false;
        el++;
    }

    return true;
}



// privat функция для проверки на совпадение значений
bool Set::check(char val)const{
    char *el = strchr(data, val);
    return el != NULL ? true : false;
}

