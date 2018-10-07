//#pragma once
#include <iostream>
//#include "/Users/Siarhei/Desktop/STEP/C++/Drob/Drob/Drob.cpp"

template<class T>
class List{
  
    struct Node{
        T data;
        Node *next;
        Node(const T &_data, Node* _next = nullptr) : data(_data), next(_next){}
        Node() = default;
    };

    Node *head;
    Node *tail;
    size_t size;

    void freeMem();

 public:
    List() :head(nullptr), tail(nullptr), size(0){}
    List(const T &data) : head(new Node(data)), tail(head), size(1){}
    List(const List<T> &);
    ~List(){ freeMem(); }

    T &operator=(const T &el);
    size_t getSize(){return size;};
    
    void push_back(const T &_data);
    const T pop_back();
    void push_front(const T &_data);
    const T pop_front();
    void insert(const T & _data, size_t index);
    bool search (const T &key);
    T remove(const T & key);
   
   friend std::ostream & operator<<(std::ostream &out, const List<T> &list);

};

template<class T>
void List<T>::push_back(const T &_data){
    if (tail){ // добавление в непустой список
        tail->next = new Node(_data);
        tail = tail->next;
    }
    else{
        head = new Node(_data); //добавление в пустой список
        tail = head;
    }
    size++;

}

template<class T>
const  T List<T>::pop_back(){
    if(!size){
        std::cout<< "Empty \n";
        exit(1);
    }
    T result;
    if(size > 1) {
    Node *cur = head, *prev = nullptr;
    while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
    }
    result = cur->data;
    delete cur;
    prev->next = nullptr;
    tail = prev;
   // tail->next = nullptr;
    }
    else{
        result = tail->data;
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    size--;
    return result;

}

template<class T>
void  List<T>::push_front(const T &_data){
    if(head)
        head = new Node(_data, head);
    else{
         head = new Node(_data, head);
        tail = head;
    }
    size++;
}

template<class T>
const T List<T>::pop_front(){
    T result = T();

    if(size){
    result = head->data;
    Node * temp = head->next;
    delete head;
    head = temp;
    size--;
    }
    else{
      std::cout << "List is empty \n";
    }
    return result;
}


template<class T>
void List<T>:: insert(const T & _data, size_t index){
    if(index > size){
        std::cout << "Wrong index \n";
        return;
    }

    if(size == 0)
        push_back(_data);
    else{
    Node *cur = head;
    for(size_t i = 0; i != index && cur->next != nullptr; i++){
        cur = cur->next;
    }
    cur->next = new Node(_data, cur->next);
    }
    size++;
}

template<class T>
 bool List<T>:: search (const T &key){
    for(Node *i = head; i != nullptr; i = i->next){
        if(i->data == key)
            return true;
    }
    std::cout << "No such key \n";
    return false;
}

template<class T>
T List<T>:: remove(const T & key){
    T temp = T();
     Node *cur = head, *prev = head;
    if(head->data == key){
        temp = head->data;
        head = head->next;
        delete cur;
        size--;
    }
    else{
        for(; cur != nullptr; cur = cur->next){
        if(cur->data == key){
            std::cout << "Was deleted: " << cur->data << "\n";
            temp = cur->data;
            prev->next = cur->next;
            delete cur;
            size--;
            break;
        }
        else
            prev = cur;
    }
    }
        return temp;
}

template<class T>
void List<T>:: freeMem(){
    while(head){
        Node * temp = head;
         head = head->next;
        delete temp;
    }
    size = 0;
}

template<class T>
std::ostream & operator<<(std::ostream &out, const List<T> &list){
    for(typename List<T>::Node* ptr = list.head; ptr != nullptr; ptr = ptr->next){
        out << ptr->data << '\n';
    }
    return out;
}
