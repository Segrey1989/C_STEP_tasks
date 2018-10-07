
#include "Array.cpp"
#include "Octal.cpp"

int main() {
    std:: ifstream in("/Users/Siarhei/Desktop/STEP/C++/Домашнее С++/Исключения/Array(exeptions)/Array(exeptions)/Decimal_numbs.txt");
    if(!in.is_open()){
        cout<< "File opening error \n";
        return 0;
    }
    try{
   Array a1(12);
        a1.read(in);
       cout << a1;
        
        Array a2(a1);
        cout << a2 << endl;
    }
    catch(Array::ErrorMax &e){
        cout << e.what();
    }
    ///////////////////////////////////////
    
    try
    {
        Array arr(150);
        
        for (int i = 0; i < arr.getSize(); i++)
        {
            arr[100] = 'z';
        }
        cout << arr;
    }
    catch (Array::IndexError & e)
    {
        cout << e.what() << e.ind << endl;
    }
    catch (Array::ErrorMax & e)
        {
            cout << e.what() << endl;
        }
    //////////////////////////////////////
    
    try
        {
            Array arr(50);
    
            for (int i = 0; i < arr.getSize(); i++)
            {
                arr[50] = 'z';
            }
            cout << arr;
        }
    catch (Array::IndexError & e)
        {
            cout << e.what() << e.ind << endl;
        }
    catch (Array::ErrorMax & e)
        {
            cout << e.what() << endl;
        }
    /////////////////////////////////////
        try {
            Octal nuby(10, 9);
    
        }
        catch (Octal::ErrorMax & e)
        {
            cout << e.what() << endl;
        }
    /////////////////////////////////
    
        try {
            Octal nuby(10, 1);
            nuby.set(1, 10);
    
        }
        catch (Octal::ErrorMax & e)
        {
            cout << e.what() << endl;
        }
   //////////////////////////////////////
    
        Octal first(5,2), second(6, 7), third(0);
        third = first + second;
        cout << "first " << first;
        cout << "second " <<second;
        cout << third;
    
    return 0;
}





