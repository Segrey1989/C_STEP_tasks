#include "Header.h"
#include "Source.h"

int main() {
    ifstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/STL(candies , bind, set, multimap)/Candies/Candies/input.txt");
    ofstream out("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/STL(candies , bind, set, multimap)/Candies/Candies/Output.txt");
    if(!in.is_open()){
        cout << "Error opening in file\n";
        return 0;
    }

    if(!out.is_open()){
        cout << "Error opening out file\n";
        return 0;
    }

  vector<string> v_str; // хранятся строки для послед обработки
  vector<Candy*> gift; // хранится ассортимент конфет

    // заполняем v_str
    while(in){
         string line;
        getline(in, line);
        if(line == "") break;
        v_str.insert(v_str.end(), line);
    }

    // заполняем gift указателями на объекты, соответственно их расположению и input.txt
    for_each(v_str.begin(), v_str.end(), [&gift](const string &str){
        istringstream str_obj(str);
        gift.push_back(getPtr(str_obj));
       
    });
    
    in.close();
    in.open("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/STL(candies , bind, set, multimap)/Candies/Candies/input.txt");

    // считывание информации в gift
    for_each(gift.begin(), gift.end(), [&in](Candy* &obj){
        obj->read(in);
    });

    // вывод информации в файл
    out << "Имеющийся ассортимент конфет: \n";
    for_each(gift.begin(), gift.end(), [&out](Candy* &obj){
        out << *obj;
    });
    cout << gift.size() << endl;
    // подсчет количества в категории шоколадные и карамель
    size_t gift_weight; // вес подарка
    size_t choc = 0, car = 0, wf = 0;// количество конфет каждого класса
    size_t per_choc = 0, per_wf =0; // процент всех шокол конфет в подарке, процент с наполнителем относ шокол конфет
    size_t weight_choc = 0, weight_car = 0, weight_wf;
    count_candies(gift,choc,car, wf);

    cout << "Введите массу подарка, сколько процентов шоколадных конфет и какой из них процент\
    будет с наполнителем: \n";
    cin >> gift_weight >> per_choc >> per_wf;
    weight_choc = gift_weight * per_choc/100; //вес всех шок конфет(и с наполнителем и без)
    weight_car = gift_weight - weight_choc; // вес карамелек
    weight_wf = weight_choc * per_wf/100; // вес шок конфет с наполнителем
    weight_choc -=  weight_wf; // вес чисто шокол конфет

    // подарок, который будем формировать в процентном соотношении
    // на каждый класс приходится определенный вес, заполняем подарок, пока не наполним вес
    vector<Candy*> present;
    for_each(gift.begin(), gift.end(),
             [&weight_choc, &weight_car, &weight_wf, &choc, &car, &wf, &present](Candy* &obj){
        string id = typeid(*obj).name();
        if(id.compare("4Choc")== 0){
             present.insert(present.end(), weight_choc/choc/obj->getWeight(), obj);
        }
        else if(id.compare("7Caramel")== 0)
            present.insert(present.end(), weight_car/car/obj->getWeight(), obj);

        else
            present.insert(present.end(), weight_wf/wf/obj->getWeight(), obj);
    });

// вывод подарка в файл
    out << "Сформированный подарок массой " << gift_weight << " и " << per_choc << "% шоколадных конфет." << endl;
    quantity_candies(out, present, gift);

    //сортировка
    out << "После сортировки по весу\n";
    sort(gift.begin(), gift.end(), []( Candy* &ob1, Candy* &ob2){
        //return ob1->getSugar() < ob2->getSugar() ;
        return (*ob1) < (*ob2);
    });
   for_each(gift.begin(), gift.end(), [&out](Candy* &obj){
    out << *obj;
   });
    
    //поиск в диапазоне сахара
    size_t sugar_fr1, sugar_fr2;
    cout << "Поиск в диапазоне сахара\n";
    out << "Поиск в диапазоне сахара\n";
    cout << "Введите 2 значения диапазона сахара: \n";
    cin >> sugar_fr1 >> sugar_fr2;
   Find_sugar_d obj(sugar_fr1, sugar_fr2);

    // вывод всех элементов в диапазоне
    for_each(gift.begin(), gift.end(),  [&sugar_fr1, &sugar_fr2, &out](Candy* &obj){
        if((obj->getSugar() >= sugar_fr1 && obj->getSugar() <= sugar_fr2 ))
            out << *obj;
    });
    
   //удаление gift
    for_each(gift.begin(), gift.end(), [](Candy* &obj){
        delete obj;
    });
    
    return 0;
}

