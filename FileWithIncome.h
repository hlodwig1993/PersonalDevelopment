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
    int idOfLastIncome;

public:
    FileWithIncome(string NAMEOFTHEFILEWITHINCOME) : nameOfTheFileWithIncome(NAMEOFTHEFILEWITHINCOME){
    idOfLastIncome = 0;};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedUserId);
    int getTheIdOfLastIncome();


};

#endif
