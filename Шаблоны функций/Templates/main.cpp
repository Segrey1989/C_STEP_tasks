
#include "Templates.h"

int main() {
    int *intPtr = nullptr;
    double *doublePtr = nullptr;
    Drob *drobPtr = nullptr;
    

    std::cout << "Testing int \n";
    const size_t int_size = 4;
    intPtr = givemem(intPtr, int_size);
    read(intPtr, int_size);
    print(intPtr, int_size);
    int average = findAverage(intPtr, int_size);
    std::cout << average << "\n";

    std::cout << "Поиск максимального значения в массиве: \n";
    int i_el;
        size_t i_ind = findElem(intPtr, int_size, i_el);
    std::cout <<"Index: " <<i_ind << " " << "Element: " << i_el << "\n";

    std::cout << "Min: " <<findMin(12, 10) << "\n";
    std::cout << "Max: " <<findMax(12, 10) << "\n";
    std::cout << "\n";

    std::cout << "Нулевые позиции: \n";
    size_t pos_arr[int_size] = {0};
    size_t i_pos = 0;
    findZeroPositions(intPtr, int_size, pos_arr, i_pos);
    if(i_pos == 0)
        std::cout << "No zero elements \n";
    else
        for(size_t i = 0; i < i_pos; i++)
            std::cout << pos_arr[i]<< "\n";

    std::cout << "Возведение в степень: \n";
        std::cout << power(5, 3) << "\n";

   intPtr = freemem(intPtr);

   
    Double
    std::cout << "\nTesting double \n";
    const size_t double_size = 4;
    doublePtr = givemem(doublePtr, double_size);

    read(doublePtr, double_size);
    print(doublePtr, double_size);

    double averageDoub = findAverage(doublePtr, double_size);
    std::cout<< "Average: " << averageDoub << "\n";

    std::cout << "Поиск максимального значения в массиве: \n";
    double d_el;
    size_t d_ind = findElem(doublePtr, double_size, d_el);
    std::cout << "Index: " <<d_ind << " " << "Element: " << d_el << "\n";

    std::cout << "Min: " <<findMin(5.7, 1.3) << "\n";
    std::cout << "Max: " <<findMax(5.7, 1.3) << "\n";
    std::cout << "\n";

    std::cout << "Нулевые позиции: \n";
    size_t d_pos_arr[double_size] = {0};
    size_t d_pos = 0;
    findZeroPositions(doublePtr, double_size, d_pos_arr, d_pos);
    if(d_pos == 0)
        std::cout << "No zero elements \n";
    else
        for(size_t i = 0; i < d_pos; i++)
            std::cout << d_pos_arr[i]<< " ";
    std::cout << "\n";

    std::cout << "Возведение в степень: \n";
    std::cout << power(2.5, 3) << "\n";

    doublePtr = freemem(doublePtr);

    //Drob
    std::cout << "\nTesting Drob \n";
    const size_t drob_size = 3;
    drobPtr = givemem(drobPtr , drob_size);
    read(drobPtr , drob_size);
    print(drobPtr , drob_size);
    Drob averageDrob = findAverage(drobPtr , drob_size);
    std::cout <<"Среднее арифметическое: " << averageDrob << "\n";

    std::cout << "Поиск максимального значения в массиве: \n";
    Drob dr_el;
    size_t dr_ind = findElem(drobPtr, drob_size, dr_el);
    std::cout << "Индекс: " << dr_ind << "\nЭлемент: " << dr_el << "\n";

    std::cout << "Min: " <<findMin(Drob(1,4), Drob(1,4)) << "\n";
    std::cout << "Max: " <<findMax(Drob(1,4), Drob(2,3)) << "\n";
    std::cout << "\n";

    std::cout << "Нулевые позиции: \n";
    size_t dr_pos_arr[drob_size] = {0};
    size_t dr_pos = 0;
    findZeroPositions(drobPtr, drob_size, dr_pos_arr, dr_pos);
    if(dr_pos == 0)
        std::cout << "No zero elements \n";
    else
        for(size_t i = 0; i < dr_pos; i++)
            std::cout << dr_pos_arr[i]<< "\n";

    std::cout << "Возведение в степень: \n";
    std::cout << power(Drob(2,3), 3);

       drobPtr = freemem(drobPtr);

    std::cout<< "Линейное уравнение int : " << linearEquasion(2, 3) << "\n";
    std::cout<< "Линейное уравнение double:  " << linearEquasion(2.0, 3.0) << "\n";
    std::cout<< "Линейное уравнение drob: " << linearEquasion(Drob(2,1), Drob(3,1)) << "\n";
    
    std::cout<< "Квадратное уравнение: \n";
     std::cout<< "int : ";
     quadraticEquasion(2, 3, 1);
     std::cout<< "double : ";
    quadraticEquasion(2.0, 3.0, 1.0);
    //Для дроби не работает, т.к надо дополнительно переопределять sqrt
    //quadraticEquasion(Drob(2,1), Drob(3,1), Drob(1,1));
    
   // system("pause");
    return 0;

    
}
