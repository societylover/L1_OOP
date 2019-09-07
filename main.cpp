#include <iostream>
#include <windows.h>
#include "CreditMap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"Лабораторная 1, вариант 14. Кузнецов Е.О. ДИПРб - 21"<<std::endl;
    std::cout <<"Размер класса без pragma pack (1): "<<sizeof(CreditMap)<<std::endl;
    CreditMap t;
    CreditMap *p = new CreditMap;
    #pragma pack(0)
    std::cout <<"Размер класса с pragma pack (1): "<<sizeof(p)<<std::endl;
    CreditMap newCard;
    newCard.Read();
    return 0;
}
