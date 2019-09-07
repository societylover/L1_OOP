#include <iostream>
#include <windows.h>
#include "CreditMap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"Ëàáîðàòîðíàÿ 1, âàðèàíò 14. Êóçíåöîâ Å.Î. ÄÈÏÐá - 21"<<std::endl;
    std::cout <<"Ðàçìåð êëàññà áåç pragma pack (1): "<<sizeof(CreditMap)<<std::endl;
    CreditMap t;
    CreditMap *p = new CreditMap;
    #pragma pack(0)
    // Hello to all, it's me
    std::cout <<"Ðàçìåð êëàññà ñ pragma pack (1): "<<sizeof(p)<<std::endl;
    CreditMap newCard;
    newCard.Read();
    return 0;
}
