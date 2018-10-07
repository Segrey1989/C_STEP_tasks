#ifndef Source_h
#define Source_h
#include "Header.h"

//подсчет количества типов конфет (нужно для формирования подарка соответственно доле данного типа в подарке)
void count_candies(vector<Candy*> &gift, size_t &choc, size_t &car, size_t &wf){
    for_each(gift.begin(), gift.end(), [&choc, &car, &wf](Candy* &obj){
        string id = typeid(*obj).name();
        if(id.compare("4Choc")== 0)
            choc++;
        else if(id.compare("7Caramel")==0)
            car++;
        else if(id.compare("11With_filler")==0)
            wf++;
        return true;
    });
}

// вывод финальных данных о сформированном подарке
size_t quantity_candies(ostream &out, vector<Candy*> &present, vector<Candy*> &gift){
    out << "В этом подарке: " << endl;
    size_t final_weight = 0;
    for_each(gift.begin(), gift.end(), [&present, &out, &final_weight](Candy* &obj){
        size_t count = count_if(present.begin(), present.end(), [&present, &obj](Candy* &pr){
            return (pr->getName().compare(obj->getName()) == 0) ? true : false;
        });
        final_weight+= count * obj->getWeight();
        out << obj->getName() << ": " << count << endl;
    });
    
    out << "Вес подарка с учетом погрешности: "<< final_weight << endl << endl;
    return final_weight;
}

// класс для поиска в диапазоне сахара
class Find_sugar_d{
    size_t fr1;
    size_t fr2;
public:
    Find_sugar_d(size_t f1, size_t f2): fr1(f1), fr2(f2){}
    bool operator()(Candy* &obj){
        return (obj->getSugar() >= fr1 && obj->getSugar() <= fr2) ? true:false;
    }
};

#endif 
