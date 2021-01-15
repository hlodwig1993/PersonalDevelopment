#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "DateOperation.h"

using namespace std;


class FileWithIncome
{
    const string nameOfTheFileWithIncome;
    DateOperation dateOperation;

public:
    FileWithIncome(string NAMEOFTHEFILEWITHINCOME) : nameOfTheFileWithIncome(NAMEOFTHEFILEWITHINCOME){};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedUserId);


};

#endif
