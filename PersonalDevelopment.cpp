#include "PersonalDevelopment.h"

void PersonalDevelopment::signUp()
{
    userMenager.signUp();
}

void PersonalDevelopment::signIn()
{
    userMenager.signIn();
     if (userMenager.userLoggedIn()) {
        operationOnFinance = new OperationOnFinance (NAME_OF_THE_FILE_WITH_INCOME, NAME_OF_THE_FILE_WITH_EXPENSE, userMenager.getIdOfLoggedInUser());
    }
}
int PersonalDevelopment::userLoggedIn()
{
    userMenager.userLoggedIn();

}
void PersonalDevelopment::changePassword()
{
    userMenager.changePassword();
}
int PersonalDevelopment::logOut()
{
    userMenager.logOut();
}
void PersonalDevelopment::addIncome()
{
    operationOnFinance->addIncome();
}
void PersonalDevelopment::addExpense()
{
    operationOnFinance->addExpense();
}
void PersonalDevelopment::balanceForTheCurrentMonth()
{
    operationOnFinance->balanceForTheCurrentMonth();
}
void PersonalDevelopment::balanceFromLastMonth()
{
    operationOnFinance->balanceFromLastMonth();
}

void PersonalDevelopment::balanceFromTheSelectPeriod()
{
    operationOnFinance->balanceFromTheSelectPeriod();
}

