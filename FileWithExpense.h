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

public:
    FileWithExpense(string NAMEOFTHEFILEWITHEXPENSE) : nameOfTheFileWithExpense(NAMEOFTHEFILEWITHEXPENSE){};
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedInUserId);

};

#endif
