#include "CreditMap.h"
#include <string>
#include <iostream>

void cin_clear()
{
    while (std::cin.get() != '\n');
    std::cin.clear();
}

void CreditMap::Read(){
    int fdays_no_penalty;
    double fpenalty_proc,fmoney_limit;
    std::string ffamilia,fend_data,flast_data,fcardNum;
    std::cout << "Введите номер карты (прим.: 1234 5678 9123 4564): ";
    while (!std::getline(std::cin,fcardNum)) std::cout <<"Номер карты введен неверно!\n"<<"Введите номер карты (прим.: 1234 5678 9123 4564): ";
    std::cout << "\nВведите фамилию владельца: ";
    while (!std::getline(std::cin,ffamilia) || ffamilia.length() < 2) std::cout << "\nВведите фамилию владельца: ";;
    std::cout << "\nВведите дату окончания действия (через пробелы / ММ ГГ): ";
    while (!std::getline(std::cin,fend_data) && fend_data.length() != 5)
        std::cout << "\nВведите дату окончания действия (через пробелы / ММ ГГ): ";
    std::cout << "\nВведите дату последнего снятия (через пробелы / ДД ММ ГГ): ";
    while (!std::getline(std::cin,flast_data) && flast_data.length() != 8)
        std::cout << "\nВведите дату последнего снятия (через пробелы / ДД ММ ГГ): ";
        std::cout << "\nВведите количество дней после снятия без штрафа: ";
    while (!std::cin>>fdays_no_penalty)
        std::cout << "\nВведите количество дней после снятия без штрафа: ";
        cin_clear();
    std::cout << "\nВведите процент штрафа: ";
    std::cin>>fpenalty_proc;
    std::cout << "\nВведите лимит снимаемой суммы (кол-во денег на карте): ";
    std::cin>>fmoney_limit;
    CreditMap::Init(fcardNum,ffamilia,fend_data,flast_data,fdays_no_penalty,fpenalty_proc,fmoney_limit);
}

void CreditMap::Display(){
    std::cout << "Номер карты: "<<this->cardNum<<std::endl;
    std::cout << "Фамилия владельца: "<<this->familia<<std::endl;
    std::cout << "Дата окончания действия (ММ ГГ): "<<this->end_data<<std::endl;
    std::cout << "Дата последнего снятия (ДД ММ ГГ): "<<this->last_data<<std::endl;
    std::cout << "Количество дней после снятия без штрафа: "<<this->days_no_penalty<<std::endl;
    std::cout << "Процент штрафа: "<<this->penalty_proc<<"%"<<std::endl;
    std::cout << "Лимит снимаемой суммы: "<<this->money_limit<<" рублей"<<std::endl;
}

void CreditMap::end_date_change(){
    std::cout << "На данный момент карта действительна до: "<<this->end_data<<std::endl;
    std::cout << "Введите новую дату действия карты (ММ ГГ): ";
    std::string new_data;
    getline(std::cin, new_data);
    // проверка на введенную дату без букв и 5 символов
    this->end_data = new_data;
    }
void CreditMap::days_no_penalty_change(){
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
    std::cout << "На данный количество дней без штрафа: "<<this->days_no_penalty<<std::endl;
    std::cout << "Введите новое количество дней без штрафа: ";
    int days;
    std::cin >> days;
    this->days_no_penalty = days;
    std::cout << "На данный количество дней без штрафа: "<<this->days_no_penalty<<std::endl;
}
void CreditMap::money_withdraw(){
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
    std::cout << "Введите количество денег для снятия: ";
    double money;
    std::cin>>money;
    if (money < 0 || money-this->money_limit<0.000001) std::cout <<"Снятие данной суммы невозможно!"<<std::endl;
    else this->money_limit -= money;
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
}
void CreditMap::money_deposit(){
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
    std::cout << "Введите количество денег для депозита (до 1 млн): ";
    double money;
    std::cin>>money;
    if (money < 0 && money > 1000000) std::cout<<"Внесение депозита не удалось!"<<std::endl;
    else this->money_limit+=money;
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
}
void CreditMap::do_penalty(){
    std::cout << "На данный момент % штрафа = "<<this->penalty_proc<<std::endl;
    double summa;
    std::cout << "Введите сумму для вычисления процента: "<<std::endl;
    std::cin>>summa;
    if (summa < 0.000001) std::cout <<"Сумма для штрафа не корректна!"<<std::endl;
    else {
        this->money_limit-=summa*(this->penalty_proc/100);
    }
    std::cout << "На данный количество денег на карте: "<<this->money_limit<<std::endl;
}

void CreditMap::cards_equal(){
    CreditMap newCard;
    newCard.Read();
    if (this->money_limit>newCard.money_limit) std::cout <<"На карте с номером: "<<this->cardNum<<" денег больше!"<<std::endl;
    else if (this->money_limit<newCard.money_limit) std::cout <<"На карте с номером: "<<newCard.cardNum<<" денег больше!"<<std::endl;
    else if (this->money_limit - newCard.money_limit < 0.000001) std::cout <<"Количество денег на картах одинаково!"<<std::endl;
}
