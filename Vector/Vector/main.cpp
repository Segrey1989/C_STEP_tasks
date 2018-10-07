
#include "Vector.h"
int main(){
    std::cout << "Testing double \n";
    Vector<double> new_vector(2);
    Vector<double>::iterator iter;

    for (iter = new_vector.begin(); iter <= new_vector.end(); iter++){
        *iter = 2.556;
        std::cout << *iter << " ";
    }
    std::cout << "\n\n";

    
    std::cout << "Testing int \n";
    Vector<int> vector_int;
     Vector<int>::iterator iter_int;
   iter_int = vector_int.begin();

    for(int i = 1; i <=4; i++)
         vector_int.push_back(i);
    
    vector_int.insert(100, 1);
    // vector_int.erase(2);
    std::cout << "pop_back: ";
    std::cout << vector_int.pop_back()<< "\n";
    //std::cout << t << "\n";

    for (iter_int = vector_int.begin(); iter_int <= vector_int.end(); iter_int++)
        std::cout << *iter_int << " ";
    std::cout << "\n\n";

      std::cout << "Testing drob \n";
    Vector<Drob> vec_drob;
     Vector<Drob> ::iterator iter_drob;
    vec_drob.push_back(Drob(2,3));
    vec_drob.push_back(Drob(4,5));
     vec_drob.push_back(Drob(8,9));
    
    std::cout << "pop_back: " << vec_drob.pop_back() << "\n";
    vec_drob.insert(Drob(11,13), 1);
    vec_drob.insert(Drob(3,8), 2);
    vec_drob.erase(1);
    for (iter_drob = vec_drob.begin(); iter_drob <= vec_drob.end(); iter_drob++)
        std::cout << *iter_drob;
    // std::cout << *iter_drob << "\n";

    
    //system("pause");
}
