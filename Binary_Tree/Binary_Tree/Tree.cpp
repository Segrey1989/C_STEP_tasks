#include "Header.h"
#include "Node.cpp"

template <class T>
class BinTree{
    Node<T> *root;
    size_t size;
    
    void del(Node<T> *);
    Node<T>* add(Node<T> *, const T &);
    void min_print(Node<T>*);
     bool min_search(Node<T>*, const T &);
    Node<T> *getTreeNode(Node<T>* node, const T &);
    void print_between(Node<T> * , const T &, const T &);
    
public:
    BinTree():root(nullptr), size(0){}
    BinTree(T &_data): root(new Node<T>(_data)), size(1){}
    ~BinTree(){
        del(root);
    }
    
    size_t getSize(){return size;}
   
    void add_elem(const T &);
    bool search(const T &_data);
    void add_penalty(const T &_data, string penalty);
    void give_paymant(const T &, string);
    
    void print();
    void print_by_key(const T &_);
    void pint_in_diapason(const T &, const T &);
};

// очистка бинарного дерева
template <class T>
void BinTree<T>:: del(Node<T> *node){
    if(node != nullptr){
        del(node->left);
        del(node->right);
        delete node;
    }
    return;
}

// добавление элемента (вспомогательная)
template <class T>
Node<T>* BinTree<T>:: add(Node<T> *node, const T & _data){
    if(node == nullptr){
        Node<T> *new_node = new Node<T>(_data);
        node = new_node;
    }
    else{
        if(_data < node->data)
                node->left = add(node->left, _data);
        else
           node->right = add(node->right, _data);
    
    }
    return node;
}

// добавление элемента(основная)
template <class T>
void BinTree<T>::add_elem(const T  &_data){
    if(!search(_data)){
   root = add(root, _data);
    size++;
    }
  
}

// печать всеч элементов дерева
template <class T>
void BinTree<T>:: print()
{
    min_print(root);
}

// печать всех элементов (вспомогательная)
template <class T>
void BinTree<T>::min_print(Node<T>* node)
{
    if (node != nullptr)
    {
        min_print(node->left);
        
        cout << node->data << "\n";
        for(int i = 0; i < node->getIndex(); i++){
            cout << node->penalty[i] << ": ";
             cout << node->was_payed[i] << "\n";
        }
        cout << endl;
        min_print(node->right);
    }
    else return;
}

// поиск элемента (вспомогательная)
template <class T>
bool BinTree<T>::min_search(Node<T>* node, const T &_data){
    if(node == nullptr)
        return false;

    else if(_data == node->data){
        return true;
    }
    else {
        if(_data < node->data)
            return min_search(node->left, _data);
        else
            return min_search(node->right, _data);
      
    }
}

// поиск элемента
template <class T>
bool BinTree<T>::search(const T &_data){
   return min_search(root, _data);
}

// добавление штрафа по ключу
template <class T>
void BinTree<T>::add_penalty(const T &_data, string penalty){

    add_elem(_data);
    Node<T> * temp;
    temp = getTreeNode(root, _data);
    temp->setPenalty(penalty);
}

// получение узла по ключу (вспомогательная)
template <class T>
Node<T> *BinTree<T>::getTreeNode(Node<T>* node, const T &_data){
    if(_data  == node->data)
        return node;
    else{
        if(_data < node->data)
            return getTreeNode(node->left, _data);
        else
            return getTreeNode(node->right, _data);
    }
   
}

//погашение квитанции, устанавливает флаг true в массив was_payed
template <class T>
void BinTree<T>::give_paymant(const T &_data, string penalty){
    
    if(search(_data)){
    Node<T> * temp;
    temp = getTreeNode(root, _data);
    temp->payPenalty(penalty);
    }
    else
        cout << "Wrong key: " << _data <<"\n\n";
}

// печать данных по ключу
template <class T>
void BinTree<T>::print_by_key(const T &_data){
     Node<T> * temp;
     temp = getTreeNode(root, _data);
    
    cout << temp->data << endl;
    for(size_t i = 0; i < temp->getIndex(); i++){
        cout << temp->penalty[i] << ": " <<  temp->was_payed[i] << "\n";
    }
    cout << endl;
}

// печать в диапазоне (вспомогательная)
template <class T>
void BinTree<T>::print_between(Node<T> * root, const T &data1, const T &data2){
    
    if(root == nullptr)
        return;
    
     print_between(root->left,data1, data2);
    
    if((root->data >= data1 && root->data <= data2) ){
        cout << root->data<< "\n";
        for(int i = 0; i < root->getIndex(); i++)
            cout <<root->penalty[i] << ": " << root->was_payed[i] << "\n";
        cout << "\n";
    }
           print_between(root->right,data1, data2);
                
}

// печать в диапазоне
template <class T>
void BinTree<T>::pint_in_diapason(const T &from, const T &till){
    print_between(root, from, till);
}

