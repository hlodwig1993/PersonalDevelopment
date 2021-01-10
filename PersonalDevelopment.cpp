#include "PersonalDevelopment.h"

void PersonalDevelopment::signUp()
{
    userMenager.signUp();
}


void PersonalDevelopment::signIn()
{
    userMenager.signIn();
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
    operationOnFinance->showVector();
}
