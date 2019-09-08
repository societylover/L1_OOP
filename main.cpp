#include <iostream>
#include <windows.h>
#include "CreditMap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"Лабораторная 1, вариант 14. Кузнецов Е.О. ДИПРб - 21"<<std::endl;
    std::cout <<"Задание: создать класс CreditMap (кредитная карта).";
    std::cout << "\nВ классе должны быть следующие поля: ";
    std::cout << " \nномер карты, фамилия владельца, дата окончания действия, дата последнего снятия, количество дней после снятия без штрафа,";
    std::cout << "процент штрафа, лимит снимаемой суммы.\n";
    std::cout << " Необходимо выполнять следующие операции: ";
    std::cout << "изменить дату окончания действия, изменить количество дней без штрафа, снять некоторую сумму денег с кар-ты, \n";
    std::cout << "положить деньги на карту, начислить штраф. Реализовать метод сравнения по сумме на карте. \n";

    std::cout <<"Размер класса без использования pragma pack (1): "<<sizeof(CreditMap)<<std::endl;
    std::cout <<"Размер класса с использованием pragma pack (1): "<<sizeof(CreditMap)<<std::endl;

    std::cout <<"\nСоздание и заполнение объекта класса \n"<<std::endl;
    CreditMap firstCard;
    if (firstCard.Read()){
    CreditMap secondCard(firstCard);
    std::cout <<"\nВывод значений карты "<<std::endl;
    secondCard.Display();
    std::cout << std::endl;
    std::cout <<"\nЗадание. Изменение даты окончания действия карты "<<std::endl;
    CreditMap thirdCard = secondCard;
    thirdCard.end_date_change();
    std::cout <<"\nЗадание. Изменение количества дней без штрафа "<<std::endl;
    thirdCard.days_no_penalty_change();
    std::cout <<"\nЗадание. Снятие денег с карты  "<<std::endl;
    thirdCard.money_withdraw();
    std::cout <<"\nЗадание. Внесение денег на карту "<<std::endl;
    thirdCard.money_deposit();
    std::cout <<"\nЗадание. Начисление штрафа  "<<std::endl;
    thirdCard.do_penalty();
    std::cout <<"\nЗадание. Для метода сравнения по сумме заполним еще 1 карту  "<<std::endl;
    CreditMap fourthCard;
    if (fourthCard.Read()){
    std::cout << std::endl;
    std::cout <<"\nЗадание. Сравнение суммы двух карт  "<<std::endl;
    thirdCard.cards_equal(fourthCard);}}

    // массив классов из 5 элементов

    CreditMap Newest[5];
    CreditMap *NewestN = new CreditMap[5] ;

    return 0;
}
