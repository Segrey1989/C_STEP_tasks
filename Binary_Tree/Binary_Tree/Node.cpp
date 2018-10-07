
#include "Header.h"

template <class T>
struct Node{
    static const size_t size = 20;
    T data;
    string penalty[size];
    bool was_payed[size];
    size_t arr_index;
    
    Node *left;
    Node *right;
    
    Node() = default;
    Node(const T &_data, Node *_left = nullptr, Node *_right = nullptr):
    data(_data), left(_left), right(_right), arr_index(0){}
    
public:
    void setPenalty(const string &_penalty);
    void payPenalty(string &_penalty);
    size_t getIndex(){return arr_index;}
    
};



template <class T>
void Node<T>::setPenalty(const string &_penalty){
    penalty[arr_index] = _penalty;
    was_payed[arr_index] = false;
    arr_index++;
}

template <class T>
void Node<T>::payPenalty(string &_penalty){
    for(size_t i = 0; i < size; i++)
        if(penalty[i] == _penalty)
            was_payed[i] = true;
}

