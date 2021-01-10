#ifndef OPERATIONONFINANCE_H
#define OPERATIONONFINANCE_H
#include <iostream>
#include <algorithm>
#include <iomanip>

#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "FileWithExpense.h"
#include "FileWithIncome.h"
#include "DateOperation.h"



class OperationOnFinance
{
    FileWithIncome fileWithIncome;
    FileWithExpense fileWithExpense;
    DateOperation dateOperation;
    vector <Income> incomes;
    vector <Expense> expenses;
    const int loggedInUserId;
    string addIncomeDate();
    int getIdOfIncomeAmount();
    string addExpenseDate();
    int getIdOfExpenseAmount();
    vector<Income>loadIncomesFromPeriod();
    vector<Expense>loadExpensesFromPeriod();

public:
    OperationOnFinance (string nameOfTheFileWithIncomes,string nameOfTheFileWithExpenses,int LOGGED_IN_USER_ID) :
        fileWithIncome(nameOfTheFileWithIncomes), fileWithExpense(nameOfTheFileWithExpenses), loggedInUserId(LOGGED_IN_USER_ID)
    {
        incomes = fileWithIncome.loadIncomesFromFile(loggedInUserId);
        expenses = fileWithExpense.loadExpensesFromFile(loggedInUserId);
    };
    void addIncome();
    void addExpense();
    void balanceForTheCurrentMonth();
    void showVector();

};
#endif
