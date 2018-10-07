#include <iostream>

template <class T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
    
    Node(){};
    Node(const T & _data, Node * _next = nullptr, Node * _prev = nullptr):
    data(_data), next(_next), prev(_prev){}
};

template <class T>
class DList
{
private:
    Node<T> *head;
    Node<T> *tail;
    size_t size;
    
    void del_list();
    
public:
    DList(): head(nullptr), tail(nullptr), size(0){}
    DList(const T &data): head(data), tail(head), size(1){}
    ~DList(){
        del_list();
    }
    
    void push_front(const T &);
    void push_back(const T &);
    T pop_back();
    T pop_front();
    void add_in_pos(const T &, size_t);
    bool remove_from_pos(size_t);
    bool remove_key(const T &);
    void replace(const T &, const T &);
    
    size_t get_size(){return size;};
    bool is_empty(){return !size;};
    
    T &operator[](size_t);
   const T &operator[](size_t)const;
    
  
    friend std::ostream &operator<<(std::ostream &out, const DList<T> &list){
//        for(Node<T> *ptr = list.head; ptr != nullptr; ptr = ptr->next){
//            out << ptr->data << " ";
//        }
            for(typename DList<T>:: iterator i = list.Begin(); i != list.End(); ++i)
                out << *i << " ";
        return out;
    }
    
    friend std::istream &operator>>(std::istream &, DList &);
    
    void insert_sort();
    void insert_on_position(const T &);
    
    struct iterator{
        Node<T> *ptr;
        iterator(const iterator &it):ptr(it.ptr){}
        iterator(Node<T> *_node):ptr(_node){}
        iterator(){};
        
        T &operator*(){return ptr->data;}
        
        
        iterator &operator++(){
            ptr = ptr->next;
            return *this;
        }
        
        iterator &operator--(){
            ptr = ptr->prev;
            return *this;
        }
        
        iterator &operator++(int){
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        
        iterator &operator--(int){
            iterator temp = *this;
            --(*this);
            return temp;
        }
        
        bool operator==(const iterator &it){
            return (ptr == it.ptr);
        }
        
        bool operator != (const iterator &it){
            return (ptr != it.ptr);
        }
    };
    
    iterator Begin()const{
        return iterator(head);
    }
    
    iterator End()const{
        return iterator(tail->next);
    }
};

template<class T>
void DList<T>::del_list(){
    while(size)
        remove_from_pos(0);
}

template<class T>
void DList<T>:: push_front(const T &element){
    Node<T> *cur = new Node<T>(element, head, nullptr);
    if(!size)
        tail = cur;
    else
        head->prev = cur;
    head = cur;
    ++size;
}

template <class T>
void DList<T>:: push_back(const T &element){
    Node<T> *cur = new Node<T>(element, nullptr, tail);
    if(!size)
        head = cur;
    else
    tail->next = cur;
    tail = cur;
    size++;
}

template <class T>
void DList<T>:: add_in_pos(const T & _data, size_t pos){
    if(pos > size){
        std::cout << "Impossible to add into the position \n";
        return;
    }
     if(pos == 0){
         push_front(_data);
         return;
    }
    if(pos == size){
        push_back(_data);
        return;
    }
    
    Node<T> *i = head;
    for(size_t j = 0; j < pos; j++, i = i->next);
    Node<T> *cur = new Node<T>(_data, i, i->prev);
    (i->prev)->next = cur;
    i->prev = cur;
    size++;
}

template <class T>
T DList<T>::pop_front(){
    if(!size){
        std::cout << "List is empty \n";
        return T();
    }
    
    Node<T> *cur = head;
    T result;
    
    if(size > 1){
    head = cur->next;
        head->prev = nullptr;
    }
    else
        head = tail->next;
    
    result = cur->data;
    delete cur;
    size--;
    return result;
}

template<class T>
T DList<T>:: pop_back(){
    if(!size){
        std::cout << "List is empty \n";
        return T();
    }
    
    Node<T> *cur = tail;
    T result;
    
    if(size > 1){
       tail= cur->prev;
        tail->next = nullptr;
    }
    else
        head = tail = nullptr;
    result = cur->data;
    size--;
    delete cur;
    return result;
}

template <class T>
bool DList<T>::remove_from_pos(size_t pos){
    if(pos >= size){
        std::cout << "impossible to remove elem from the position\n";
        return 0;
    }
    
    if(!pos){
        pop_front();
        return 1;
    }
    
    if(pos == size-1){
        pop_back();
        return 1;
    }
    
    Node<T> *i = head;
    for(size_t j = 0; j < pos; j++, i = i->next);
    (i->prev)->next = i->next;
    (i->next)->prev = i->prev;
    delete i;
    size--;
    return 1;
}

template <class T>
bool DList<T>:: remove_key(const T &key){
    for(int i = 0; i < size; i++)
        if((*this)[i] == key){
            remove_from_pos(i);
            return 1;
        }
    std::cout << "Not found \n";
    return 0;
}

template <class T>
T &DList<T>:: operator[](size_t index){
    if (index >= size)
    {
        std::cout << "No element with this index\n";
        exit(1);
    }
    
    Node<T> *i = head;
    for(size_t j = 0; j < index; j++, i = i->next);
    return i->data;
}

template <class T>
const T &DList<T>:: operator[](size_t index)const{
    if (index >= size)
    {
        std::cout << "No element with this index\n";
        exit(1);
    }

    Node<T>*i = head;
    for (size_t j = 0; j < index; j++, i = i->next);
    return i->data;
}

//template <class T>
//std::ostream &operator<<(std::ostream &out, const DList &list){
//    for(Node<T> *ptr = list.head; ptr != nullptr; ptr = ptr->next){
//        out << ptr->data << " ";
//    }
////    for(typename DList<T>:: iterator i = list.Begin(); i != list.End(); ++i)
////        out << *i << " ";
//    return out;
//}



template <class T>
void DList<T>:: insert_sort(){
for(Node<T> *i = head->next; i != nullptr; i= i->next){
    T tmp = i->data;
    for(Node<T> *j = i->prev; j != nullptr; j = j->prev){
        if(j->data > tmp){
            j->next->data = j->data;
            j->data = tmp;
        }else
            break;
    }
}
}

template <class T>
void DList<T>:: insert_on_position(const T &el){
    if(!size){
        std::cout << "List is empty \n";
        return;
    }
    
    Node<T> *cur = head;
    for(; cur->data < el && cur->next != nullptr; cur = cur->next);
    if(cur == head){
         Node<T> *temp = new Node<T>(el, head,nullptr);
        head->prev = temp;
        head = temp;
    }
    else if(cur->next == nullptr){
     Node<T> *temp = new Node<T>(el, nullptr,tail);
        tail->next = temp;
        tail = temp;
    }else{
        Node<T> *temp = new Node<T>(el, cur,cur->prev);
        (cur->prev)->next = temp;
        cur->prev = temp;
    }
    size++;
}
