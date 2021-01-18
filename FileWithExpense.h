#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"
#include "DateOperation.h"

using namespace std;


class FileWithExpense
{
 const string nameOfTheFileWithExpense;
 DateOperation dateOperation;
 int idOfLastExpense;

public:
    FileWithExpense(string NAMEOFTHEFILEWITHEXPENSE) : nameOfTheFileWithExpense(NAMEOFTHEFILEWITHEXPENSE){
    idOfLastExpense = 0;};
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedInUserId);
    int getTheIdOfLastExpense();

};

#endif
