#include "Bus.h"

int main() {
    std::ifstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Bus/Bus/input.txt");
    List<Bus> inPark, inRoute;
    Bus b;
    for(int i = 0; i < 3; i++){
        in >> b;
        inPark.push_back(b);
   }

    std::cout<< "На маршруте: "<< inRoute.getSize() << "\n";
    std::cout<<"В парке: " <<inPark.getSize() << "\n";
   
    while(true){
        char number[10];
        int mode = 0;
        std::cout << "Выезд на маршрут - 1, возвращение в парк - 2, конец - 3 \n";
        std::cin >> mode;
        switch(mode){
            case 1:
                if(inPark.getSize() == 0){
                    std::cout << "Нет автобусов в парке\n";
                }
                else{
                    std::cout << "Введите номер автобуса\n";
                      std::cin >> number;
                    
                        if(inPark.search(number)){
                            b = inPark.remove(number);
                            inRoute.push_back(b);
                       }
                }
                break;
            case 2:
                if(inRoute.getSize() == 0)
                 std::cout << "Нет автобусов в парке\n";
                
            else{
                    std::cout << "Введите номер автобуса\n";
                    std::cin >> number;
                  
                    if(inRoute.search(number)){
                        b = inRoute.remove(number);
                        inPark.push_back(b);
                    }
                }
                break;
            case 3:
                std:: cout << "Конец программы\n";
                exit(1);

        }
        std::cout<< "На маршруте: "<< inRoute.getSize() << "\n";
        std::cout<<"В парке: " <<inPark.getSize() << "\n";
       
    }
    return 0;
}


//void leave(List<Bus> inPark, List<Bus> inRoute){
//    char number[10];
//    std::cin >> number;
//
//    Bus b = inPark.search(number);
//    if(strcmp(b.number, "")!=0){
//        inPark.remove(b);
//        inRoute.push_back(b);
//    }
//}

