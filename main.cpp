#include <iostream>
#include <windows.h>
#include "CreditMap.h"


using namespace std;
std::cout << '2' << std::endl;
std::cout << '3' << std::endl;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"Лабораторная 1, вариант 14. Кузнецов Е.О. ДИПРб - 21. Проект 2"<<std::endl;
    std::cout <<"Задание: создать класс CreditMap (кредитная карта).";
    std::cout << "\nВ классе должны быть следующие поля: ";
    std::cout << " \nномер карты, фамилия владельца, дата окончания действия, дата последнего снятия, количество дней после снятия без штрафа,";
    std::cout << "процент штрафа, лимит снимаемой суммы.\n";
    std::cout << " Необходимо выполнять следующие операции: ";
    std::cout << "изменить дату окончания действия, изменить количество дней без штрафа, снять некоторую сумму денег с кар-ты, \n";
    std::cout << "положить деньги на карту, начислить штраф. Реализовать метод сравнения по сумме на карте. \n";

    std::cout <<"Размер класса без использования pragma pack (1): "<<sizeof(CreditMaps)<<std::endl;
    std::cout <<"Размер класса с использованием pragma pack (1): "<<sizeof(CreditMap)<<std::endl;

    try {
    std::cout <<"\nСоздание и заполнение объекта класса данными: "<<std::endl;
    std::cout << "Номер карты: 1234"<<std::endl;
    std::cout << "Фамилия владельца: Кузнецов"<<std::endl;
    std::cout << "Дата окончания действия (ММ ГГГГ): 3 2020"<<std::endl;
    std::cout << "Дата последнего снятия (ДД ММ ГГГГ): 10 4 2019"<<std::endl;
    std::cout << "Количество дней после снятия без штрафа: 90"<<std::endl;
    std::cout << "Процент штрафа: 15%"<<std::endl;
    std::cout << "Лимит снимаемой суммы: 250000 рублей"<<std::endl;
    CreditMap firstCard(1234,"Кузнецов",3,2020,10,4,2019,90,15,250000);
    // создание через другой объект класса
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
    fourthCard.Read();
    std::cout << std::endl;
    std::cout <<"\nЗадание. Сравнение суммы двух карт  "<<std::endl;
    thirdCard.cards_equal(fourthCard);}
    catch (const char* exc){
        std::cout << exc<<std::endl;
    }
    // массив классов из 5 элементов

    CreditMap Newest[5];
    CreditMap *NewestN = new CreditMap[5];
    for (int i = 0; i < 5; i++) NewestN[i] = CreditMap(1234,"Кузнецов",3,2020,10,4,2019,90,15,250000);

    return 0;
}
