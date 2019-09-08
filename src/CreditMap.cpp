#include "CreditMap.h"
#include <string>
#include <iostream>
#include <conio.h>

// заполнение данных о карте
bool CreditMap::Read(){
    int fdays_no_penalty,fcardNum, fend_mon, fend_year, fwith_day, fwith_mon,fwith_year;
    double fpenalty_proc,fmoney_limit;
    std::string ffamilia;

    std::cout << "Введите номер карты: ";
    std::cin >> fcardNum;
    std::cin.ignore();
    std::cout << "Введите фамилию владельца: ";
    std::getline(std::cin,ffamilia);
    std::cout << "Введите месяц окончания действия карты ( 1 - 12 ) ";
    std::cin >> fend_mon;
    std::cin.ignore();
    std::cout << "Введите год окончания действия карты ( 2019 - 2030 ): ";
    std::cin >> fend_year;
    std::cin.ignore();
    std::cout << "Введите день последенего снятия с карты: ";
    std::cin >> fwith_day;
    std::cin.ignore();
    std::cout << "Введите месяц последенего снятия с карты: ";
    std::cin >> fwith_mon;
    std::cin.ignore();
    std::cout << "Введите год последенего снятия с карты: ";
    std::cin >> fwith_year;
    std::cin.ignore();
    std::cout << "Введите количество дней после снятия без штрафа: ";
    std::cin>>fdays_no_penalty;
    std::cin.ignore();
    std::cout << "Введите процент штрафа: ";
    std::cin>>fpenalty_proc;
    std::cin.ignore();
    std::cout << "Введите лимит снимаемой суммы (кол-во денег на карте): ";
    std::cin >> fmoney_limit;
    try {this->Init(fcardNum,ffamilia,fend_mon,fend_year,fwith_day,fwith_mon,fwith_year,fdays_no_penalty,fpenalty_proc,fmoney_limit); return true;}
    catch (const char* exc) {std::cout << exc; return false;}
}

// вывод данных о карте
void CreditMap::Display(){
    std::cout << "Номер карты: "<<this->cardNum<<std::endl;
    std::cout << "Фамилия владельца: "<<this->familia<<std::endl;
    std::cout << "Дата окончания действия (ММ ГГ): "<<this->end_mon<<" "<<this->end_year<<std::endl;
    std::cout << "Дата последнего снятия (ДД ММ ГГ): "<<this->with_day<<" "<<this->with_mon<<" "<<this->with_year<<std::endl;
    std::cout << "Количество дней после снятия без штрафа: "<<this->days_no_penalty<<std::endl;
    std::cout << "Процент штрафа: "<<this->penalty_proc<<"%"<<std::endl;
    std::cout << "Лимит снимаемой суммы: "<<this->money_limit<<" рублей"<<std::endl;
}

// изменение даты годности карты
void CreditMap::end_date_change(){
    std::cout << "На данный момент карта действительна до: "<<this->end_mon<<" "<<this->end_year<<std::endl;
    std::cout << "Введите новую дату действия карты (ММ ГГ): ";
    int fend_mon,fend_year;
    std::cout << "\nВведите месяц окончания действия карты ( 1 - 12 ) ";
    std::cin >> fend_mon;
    std::cin.ignore();
    std::cout << "Введите год окончания действия карты ( 2019 - 2030 ): ";
    std::cin >> fend_year;
    std::cin.ignore();
    // проверка на введенную дату без букв и 5 символов
    try { this->Init(this->cardNum,this->familia,fend_mon,fend_year,this->with_day,this->with_mon,this->with_year,this->days_no_penalty,this->penalty_proc,this->money_limit);
        std::cout << "На данный момент карта действительна до: "<<this->end_mon<<" "<<this->end_year<<std::endl;}
    catch (const char* exc) {std::cout << exc;}
    }


void CreditMap::days_no_penalty_change(){
    std::cout << "На данный количество дней без штрафа: "<<this->days_no_penalty<<std::endl;
    std::cout << "Введите новое количество дней без штрафа: ";
    int days;
    std::cin >> days;
    std::cin.ignore();
    try { this->Init(this->cardNum,this->familia,this->end_mon,this->end_year,this->with_day,this->with_mon,this->with_year,days,this->penalty_proc,this->money_limit);
    std::cout << "На данный количество дней без штрафа: "<<this->days_no_penalty<<std::endl; }
    catch (std::string exc) {std::cout << exc;}
}
void CreditMap::money_withdraw(){
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
    std::cout << "Введите количество денег для снятия: ";
    double money;
    std::cin>>money;
    std::cin.ignore();
    if (money < 0 || money > this->money_limit) std::cout <<"Снятие данной суммы невозможно!"<<std::endl;
    else this->money_limit -= money;
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
}
void CreditMap::money_deposit(){
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
    std::cout << "Введите количество денег для депозита (до 300000): ";
    double money;
    std::cin>>money;
    std::cin.ignore();
    if (money < 0 && money > 300001) std::cout<<"Внесение депозита не удалось!"<<std::endl;
    else this->money_limit += money;
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
}
void CreditMap::do_penalty(){
    std::cout << "На данный момент % штрафа = "<<this->penalty_proc<<std::endl;
    double summa;
    std::cout << "Введите сумму для вычисления штрафа = ";
    std::cin>>summa;
    if (summa < 0.000001) std::cout <<"Сумма для штрафа не корректна!"<<std::endl;
    else {
        this->money_limit-=summa*(this->penalty_proc/100);
    }
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
}

void CreditMap::cards_equal(CreditMap &newCard){

    if (this->money_limit>newCard.money_limit) std::cout <<"На карте с номером: "<<this->cardNum<<" денег больше!"<<std::endl;
    else if (this->money_limit<newCard.money_limit) std::cout <<"На карте с номером: "<<newCard.cardNum<<" денег больше!"<<std::endl;
    else if (this->money_limit - newCard.money_limit < 0.000001) std::cout <<"Количество денег на картах одинаково!"<<std::endl;
}
