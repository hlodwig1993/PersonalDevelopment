#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Expense.h"
#include "Markup.h"


using namespace std;

class FileWithExpenses {
    Expense expense;
    vector <Expense> expenses;
    const string nameOfTheFileWithExpenses;
    int idOfLastExpense;

public:
    FileWithExpenses(string NAMEOFTHEFILEWITHEXPENSES) : nameOfTheFileWithExpenses(NAMEOFTHEFILEWITHEXPENSES) {
        idOfLastExpense = 0;
    };

    vector <Expense> loadExpensesOfLoggedInUserFromFile(int loggedInUserId);
    int getTheIdOfLastExpense();
    void addExpenseToFile(Expense expense);
};

#endif //FILEWITHEXPENSES_H
