#ifndef PERSONALDEVELOPMENT_H
#define PERSONALDEVELOPMENT_H
#include <iostream>

#include "UserMenager.h"
#include "OperationOnFinance.h"
#include "FileWithExpense.h"
#include "FileWithIncome.h"

using namespace std;

class PersonalDevelopment
{
    UserMenager userMenager;
    OperationOnFinance *operationOnFinance;
    const string NAME_OF_THE_FILE_WITH_INCOME;
    const string NAME_OF_THE_FILE_WITH_EXPENSE;

public :
    PersonalDevelopment (string nameOfFileWithUsers, string nameOfTheFileWithIncome, string nameOfTheFileWithExpense):
        userMenager(nameOfFileWithUsers),NAME_OF_THE_FILE_WITH_INCOME(nameOfTheFileWithIncome), NAME_OF_THE_FILE_WITH_EXPENSE(nameOfTheFileWithExpense) {operationOnFinance = NULL;};
    ~PersonalDevelopment()
    {
        delete operationOnFinance;
        operationOnFinance = NULL;
    }
    void signUp();
    void signIn();
    int userLoggedIn();
    int logOut();
    void addIncome();
    void addExpense();
    void balanceForTheCurrentMonth();
    void balanceFromLastMonth();
    void balanceFromTheSelectPeriod();
    void changePassword();
};


#endif


