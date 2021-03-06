/*
 Реализовать базовый класс динамический массив с полями размер и указатель на целочисленный тип и необходимые методы конструктор копирования, перегрузить операции =, >>,<<, виртуальную функцию print().
 Реализовать классы наследники стек и очередь добавив к стеку поле top (вершина стека), в класс очередь поля (head и tail) и реализовать соответствующие методы стек (push() pop()) очередь(добавить в конец извлечь из начала).
 Сформировать массив указателей на объекты обоих классов. Массив объектов прочитать из файла.

 */

#include "stack.h"
#include "fifo.h"

int main()
{
    Array*obj[2];
    obj[0] = new Stack;
    obj[1] = new Fifo;
    
    obj[0]->push(2);
    obj[0]->push(3);
    obj[0]->push(1);
    obj[0]->push(5);
    obj[0]->print(std::cout);
    obj[1]->push(6);
    obj[1]->push(4);
    obj[1]->print(std::cout);
    
    std::cout << obj[0]->pop();
    std::cout << obj[1]->pop();
    delete obj[0];
    delete obj[1];
    
    system("pause");
    return 0;
}
