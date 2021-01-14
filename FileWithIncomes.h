#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Income.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes {
    Income income;
    vector<Income> incomes;
    const string nameOfTheFileWithIncomes;
    int idOfLastIncome;

public:
    FileWithIncomes(string NAMEOFTHEFILEWITHINCOMES) : nameOfTheFileWithIncomes(NAMEOFTHEFILEWITHINCOMES) {
        idOfLastIncome = 0;
    };

    vector <Income> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
    int getTheIdOfLastIncome();
    void addIncomeToFile(Income income);
};

#endif
