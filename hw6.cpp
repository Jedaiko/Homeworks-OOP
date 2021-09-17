#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cassert>
#include<algorithm>
#include<strstream>
#include<fstream>
#include <cstdlib>

using namespace std;


void Task1()
{
     int i;
    cout<<"Введите целое число : ";
    while(!(cin>>i)) 
    {
        cout<<"Неверно !! Введите снова !\n";
        cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
        cin.sync();//Удалим данные из буффера
        cout<<"Введите целое число : ";
    }
    system("pause");
}

ostream & endll( ostream & os )
{
    os.put( os.widen('\n') );
    os.put( os.widen('\n') );
    os.flush(); 

    return os;
}

void Task2()
{

    int i = 10;
    int j =200;
    int k = 100;
    cout << i << endll;
    cout << k << endll;
    cout << j << endll;
}

int main()
{
    
    //Task1();
    Task2();
   
    return 0;
}