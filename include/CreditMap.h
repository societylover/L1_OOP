#ifndef CREDITMAP_H
#define CREDITMAP_H
#include <string>
#include <iostream>

#pragma pack(1)

class CreditMap
{
    int days_no_penalty;
    double penalty_proc,money_limit;
    std::string cardNum,familia,end_data,last_data;
    // проверка поля с цифрами на наличие в нем букв
    bool char_in_card(const std::string &cardNums){
    int cardNum_size = cardNums.size();
        for (int i = 0; i < cardNum_size; i++)
        {
            if (isalpha(cardNums[i]) || (cardNums[i]>='A' && cardNums[i] <= 'я'))
                if (cardNums[i] != ' ') return false;
        }
    return true;
        }

    // проверка поля на наличие в цифр, когда нужны только буквы
    bool num_in_card(const std::string &cardNums){
    int cardNum_size = cardNums.size();
    for (auto &i : cardNums) {
        if (!isdigit(i)) return false;
    }
    return true;
    }

    public:
           // CreditMap(const std::string &fcardNum, const std::string &ffamilia, const std::string &fend_data, const std::string &flast_data, const int &fdays_no_penalty, const double &fpenalty_proc, const double &fmoney_limit);

        void Init (const std::string &fcardNum, const std::string &ffamilia, const std::string &fend_data, const std::string &flast_data, const int &fdays_no_penalty, const double &fpenalty_proc, const double &fmoney_limit){
        //if () Нужно реализовать проверку
        if (char_in_card(fcardNum)) { cardNum = fcardNum;
            if (num_in_card(ffamilia)){
                    end_data = fend_data;
                    last_data = flast_data;
                    days_no_penalty = fdays_no_penalty;
                    penalty_proc = fpenalty_proc;
                    money_limit = fmoney_limit;
            }
        } // проверка всех полей
        else { std::cout << "не корректные данные!"<<std::endl;}
        /*if (familia = ffamilia;
        end_data = fend_data;
        last_data = flast_data;
        days_no_penalty = fdays_no_penalty;
        penalty_proc = fpenalty_proc;
        money_limit = fmoney_limit;*/
        }

        void Read();
        void Display();
        void end_date_change();
        void days_no_penalty_change();
        void money_withdraw();
        void money_deposit();
        void do_penalty();
        void cards_equal();
};

#endif // CREDITMAP_H
