
#include"Header.h"

int main(){
    ifstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Flowerbeds/Flowerbeds/Text.txt");
    if (!in.is_open()){
        cout << "File opening error\n";
        return 0;
    }
    
    ofstream out_file("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Flowerbeds/Flowerbeds/Output.txt");
    if (!out_file.is_open()){
        cout << "Out_file opening error\n";
        return 0;
    }
    
     list<Clumb> clumb_list;
    // сортировка по форме клумбы
    out_file << "Flowerbeds shape sorted:\n";
    istream_iterator<Clumb> it(in), it_cur;
    copy(it, it_cur, back_inserter(clumb_list));
    clumb_list.sort([](const Clumb &a, const Clumb &b){return a.form < b.form; });
    
    ostream_iterator<Clumb> outIt(out_file, "\n");
    copy(clumb_list.begin(), clumb_list.end(), outIt);
    out_file << endl;

    // вывод названий неповторяющихся цветов
    out_file << "\nList of flower names: \n";
    set<string> flower_set;
    for_each(clumb_list.begin(), clumb_list.end(), [&flower_set](const Clumb &l){
        copy(l.flowers.begin(), l.flowers.end(), inserter(flower_set, flower_set.begin()));
    });

    ostream_iterator<string> outSet(out_file, "\t");
    copy(flower_set.begin(),flower_set.end(), outSet);
    out_file << endl;

    // создание мультимэп
   out_file << "\nMultimap: \n";
    multimap<string, Clumb> cl_map;
    for_each(clumb_list.begin(), clumb_list.end(), [&cl_map](const Clumb &m){
        cl_map.insert(make_pair(m.form, m));
    });

    ostream_iterator<pair<string, Clumb>> outMap(out_file);
    copy(cl_map.begin(), cl_map.end(), outMap);
    out_file << endl;

    //поис клумбы, где нет указанного вида цветов
    string flower;
   cout << "Input the flower name: \n";
    cin >> flower;
    FindFlower fl(flower);
    out_file << "\n Flowerbeds with " << flower << " were deleted: \n";
    remove_copy_if(cl_map.begin(), cl_map.end(), outMap, fl); // удаляет все клумбы, где есть цветок

    //вывод всех различных форм
    out_file << "\nShapes of the flowerbeds: \n";
    set<string> shape_set;
    for_each(cl_map.begin(), cl_map.end(),[&shape_set](const pair<string, Clumb> &m){
        shape_set.insert(m.first);
    });

    ostream_iterator<string> out(out_file, "\n");
    copy(shape_set.begin(), shape_set.end(), out);

    //подсчет числа различных цветов на всех клумбах
    map<string, size_t> fl_count;
    //занесение в map названий цветов в качестве ключа и инициализация нулем
    for_each(flower_set.begin(), flower_set.end(), [&fl_count](const string &st){
        fl_count.insert(make_pair(st, 0));
    });

    // проходим по каждому элементу мультимэпа
    for_each(cl_map.begin(), cl_map.end(), [&fl_count](const pair<string,Clumb> & cl){
        //проходим по каждому значению vector flowers
        for_each(cl.second.flowers.begin(), cl.second.flowers.end(), [&fl_count](const string &flower){
            // находим данный цветок в map fl_count и увеличиваем значение на 1, если нашли
            auto ptr = fl_count.find(flower);
            if(ptr != fl_count.end())
                ptr->second++;
    });
         });
    //вывод содержимого map, функция copy не работает для вывода map
    out_file << "\nNumber of each flower in the all flowerbeds: \n";
    for_each(fl_count.begin(), fl_count.end(), [&out_file](const pair<string, size_t>  &obj){
        out_file << obj;
    });

  //  замена указанного цветка на другой
    string fl1, fl2;

    cout << "Input a fl1 and fl2: \n";
    cin >> fl1 >> fl2;
    out_file << "\n" << fl1 << " was changed for " << fl2 << endl;
    for(auto i = cl_map.begin(); i != cl_map.end(); i++ ){
        replace(i->second.flowers.begin(), i->second.flowers.end(), fl1, fl2);
 };
     copy(cl_map.begin(), cl_map.end(), outMap);

    //поиск клумбы с нвибольшим количеством цветов
   size_t max_fl = 0;
   size_t max_flowerbed;
    for_each(cl_map.begin(), cl_map.end(), [&max_fl, &max_flowerbed](const pair<string, Clumb> &obj){
        if(obj.second.flowers.size() > max_fl){
            max_fl = obj.second.flowers.size();
            max_flowerbed = obj.second.id;
        }
    });
   out_file<< "\nId of the flowerbed with more flowers: " << max_flowerbed << endl;
   // system("pause");
    return 0;
}
