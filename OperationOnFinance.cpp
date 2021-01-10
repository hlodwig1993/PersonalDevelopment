#include "OperationOnFinance.h"
#include "AuxiliaryMethods.h"

string OperationOnFinance::addIncomeDate()
{
    Income income;
    DateOperation dateOperation;
    char choice;

    cout << "Choose from menu below:" << endl;
    cout << "Press 1 to add operation with current date." << endl;
    cout << "Press 2 to set date for the operation." << endl;
    choice = AuxiliaryMethods::getChar();
    if(choice == '1')
    {
        string data = dateOperation.CurrentlyDate();
        return data;

    }
    if (choice == '2')
    {
        string data = dateOperation.userDate();
        return data;


    }

}

int OperationOnFinance::getIdOfIncomeAmount()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId()+1 ;

}

void OperationOnFinance::addIncome()
{
    Income income;
    string date = addIncomeDate();

    income.setUserId(loggedInUserId);

    income.setIncomeId(getIdOfIncomeAmount());
    cout<< "dziala 1";
    system("pause");

    if(date == "0")
    {
        cout << "Date is incorrect";
        system("pause");
        return;
    }
    int dataInt = dateOperation.dateToInteger(date);
    income.setDate(dataInt);

    cout << "Enter name of income : ";
    string nameOfIncome = AuxiliaryMethods::getLine();
    income.setItem(nameOfIncome);

    cout << "Enter the value  of income : ";
    string amountOfIncome;
    amountOfIncome = AuxiliaryMethods::getLine();
    double amount = AuxiliaryMethods::stringOnDouble (amountOfIncome);
    income.setAmount(amount);

    incomes.push_back(income);

    fileWithIncome.addIncomeToFile(income);

}

void OperationOnFinance::addExpense()
{
    Expense expense;
    string date = addExpenseDate();
    if(date == "0")
    {
        cout << "Date is incorrect";
        system("pause");
        return;
    }
    else
    {

        expense.setUserId(loggedInUserId);

        expense.setExpenseId(getIdOfExpenseAmount());

        int dataInt = dateOperation.dateToInteger(date);
        expense.setDate(dataInt);

        cout << "Enter name of income : ";
        string nameOfExpense = AuxiliaryMethods::getLine();
        expense.setItem(nameOfExpense);

        cout << "Enter the value  of expense : ";
        string amountOfExpense;
        amountOfExpense = AuxiliaryMethods::getLine();
        double amount = AuxiliaryMethods::stringOnDouble (amountOfExpense);
        expense.setAmount(amount);

        expenses.push_back(expense);

        fileWithExpense.addExpenseToFile(expense);

    }

}
string OperationOnFinance::addExpenseDate()
{
    Expense expense;
    DateOperation dateOperation;
    char choice;

    cout << "Choose from menu below:" << endl;
    cout << "Press 1 to add operation with current date." << endl;
    cout << "Press 2 to set date for the operation." << endl;
    choice = AuxiliaryMethods::getChar();
    if(choice == '1')
    {
        string data = dateOperation.CurrentlyDate();
        return data;

    }
    if (choice == '2')
    {
        string data = dateOperation.userDate();
        return data;


    }
}

int OperationOnFinance::getIdOfExpenseAmount()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId()+1 ;

}

void OperationOnFinance::balanceForTheCurrentMonth()
{
    vector <Income> incomesFromCurrentMonth;
    vector <Income> sortedIncomesFromCurrentMonth;
    system("cls");
    incomesFromCurrentMonth = loadIncomesFromPeriod();
    //sort(incomes.begin(),incomes.end());
    for(int i = 0; i < incomes.size(); i++) {
        cout<<incomesFromCurrentMonth.at(i).getDate()<<" "<<incomesFromCurrentMonth.at(i).getItem()<< " " <<incomesFromCurrentMonth.at(i).getAmount()<< endl;
    }
}

vector<Income>OperationOnFinance::loadIncomesFromPeriod()
{
    Income income;
    vector <Income> incomesFromCurrentMonth;
    int currentYear = dateOperation.getCurrentYear();
    int currentMonth = dateOperation.getCurrentMonth();
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end())
    {
        int data = itr -> getDate();
        string date = AuxiliaryMethods::intOnString(data);
        int yearFromUsersDate = dateOperation.getYear(date);
        int monthFromUsersDate = dateOperation.getMonth(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth)
        {
            income.setIncomeId(itr -> getIncomeId());
            income.setUserId(itr -> getUserId());
            income.setDate(data);
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            incomesFromCurrentMonth.push_back(income);
        }
        itr++;
    }
    for(int i = 0; i < incomesFromCurrentMonth.size(); i++) {
        cout<<incomesFromCurrentMonth.at(i).getDate()<<" "<<incomesFromCurrentMonth.at(i).getItem()<< " " <<incomesFromCurrentMonth.at(i).getAmount()<< endl;
    }

    return incomesFromCurrentMonth;
}

vector<Expense>OperationOnFinance::loadExpensesFromPeriod()
{
    Expense expense;
    vector <Expense> expenseFromCurrentMonth;
    int currentYear = dateOperation.getCurrentYear();
    int currentMonth = dateOperation.getCurrentMonth();
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end())
    {
        int data = itr -> getDate();
        string date = AuxiliaryMethods::intOnString(data);
        int yearFromUsersDate = dateOperation.getYear(date);
        int monthFromUsersDate = dateOperation.getMonth(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth)
        {
            expense.setExpenseId(itr -> getExpenseId());
            expense.setUserId(itr -> getUserId());
            expense.setDate(data);
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expenseFromCurrentMonth.push_back(expense);
        }
        itr++;
    }

    return expenseFromCurrentMonth;
}
void OperationOnFinance::showVector()
{
    system("pause");
    for(int i = 0; i < incomes.size(); i++) {
        cout<<incomes.at(i).getDate()<<" "<<incomes.at(i).getItem()<< " " <<incomes.at(i).getAmount()<< endl;
    }
}
