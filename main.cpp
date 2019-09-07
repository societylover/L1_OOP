#include <iostream>
#include <windows.h>
#include "CreditMap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"������������ 1, ������� 14. �������� �.�. ����� - 21"<<std::endl;
    std::cout <<"������ ������ ��� ������������� pragma pack (1): "<<sizeof(CreditMap)<<std::endl;
    CreditMap t;
    CreditMap *p = new CreditMap;
    #pragma pack(0)
    std::cout <<"������ ������ � �������������� pragma pack (1): "<<sizeof(p)<<std::endl;
    CreditMap newCard;
    newCard.Read();
    newCard.Display();
    std::cout<<std::endl;
    newCard.end_date_change();
    newCard.days_no_penalty_change();
    newCard.money_withdraw();
    newCard.money_deposit();
    newCard.do_penalty();
    return 0;
}
