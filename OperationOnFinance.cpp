#include "OperationOnFinance.h"

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
    cout << setprecision (2);
    cout << fixed; //stała notacja zmienno przecinkowa
    vector <Income> incomesFromCurrentMonth;
    vector <Income> sortedIncomesFromCurrentMonth;
    double totalIncomes;
    double totalExpenses;

    incomesFromCurrentMonth = loadIncomesFromPeriod();
    sortedIncomesFromCurrentMonth = sortIncomesFromSelectedPeriodOfTime(incomesFromCurrentMonth);

    cout << "INCOMES" << endl;
    for(int i = 0; i < sortedIncomesFromCurrentMonth.size(); i++)
    {
        cout<<AuxiliaryMethods::intOnStringWithDashes(sortedIncomesFromCurrentMonth.at(i).getDate())<<" "<<sortedIncomesFromCurrentMonth.at(i).getItem()<< " " <<sortedIncomesFromCurrentMonth.at(i).getAmount()<<endl;
        totalIncomes += sortedIncomesFromCurrentMonth.at(i).getAmount();
    }
    cout << "Total incomes: " << totalIncomes << endl;
    cout << endl;

    vector <Expense> expensesFromCurrentMonth;
    vector <Expense> sortedExpensesFromCurrentMonth;

    expensesFromCurrentMonth = loadExpensesFromPeriod();
    sortedExpensesFromCurrentMonth = sortExpensesFromSelectedPeriodOfTime(expensesFromCurrentMonth);

    cout << "EXPENSES"<<endl;
    for(int j = 0; j < sortedExpensesFromCurrentMonth.size(); j++)
    {
        cout<< AuxiliaryMethods::intOnStringWithDashes(sortedExpensesFromCurrentMonth.at(j).getDate())<<" "<<sortedExpensesFromCurrentMonth.at(j).getItem()<< " " <<sortedExpensesFromCurrentMonth.at(j).getAmount()<< endl;
        totalExpenses += sortedExpensesFromCurrentMonth.at(j).getAmount();
    }
    cout << "Total expenses: " << totalExpenses << endl<<endl;
    double balance = totalIncomes - totalExpenses;
    cout<< "Balance from current month : " << balance  <<endl;

    system("pause");
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

    return incomesFromCurrentMonth;
}

vector<Expense>OperationOnFinance::loadExpensesFromPeriod()
{
    Expense expense;
    vector <Expense> expensesFromCurrentMonth;

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
            expensesFromCurrentMonth.push_back(expense);
        }
        itr++;
    }

    return expensesFromCurrentMonth;
}
vector<Income>OperationOnFinance::loadIncomesFromLastMonth()
{
    Income income;
    vector <Income> incomesFromLastMonth;
    int lastYear;
    int lastMonth = dateOperation.getLastMonth();
    int currentYear = dateOperation.getCurrentYear();
    if(lastMonth == 12)
    {
        lastYear = currentYear -1;
    }
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end())
    {
        int data = itr -> getDate();
        string date = AuxiliaryMethods::intOnString(data);
        int yearFromUsersDate = dateOperation.getYear(date);
        int monthFromUsersDate = dateOperation.getMonth(date);
        if (yearFromUsersDate == lastYear && monthFromUsersDate == lastMonth)
        {
            income.setIncomeId(itr -> getIncomeId());
            income.setUserId(itr -> getUserId());
            income.setDate(data);
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            incomesFromLastMonth.push_back(income);
        }
        itr++;
    }

    return incomesFromLastMonth;
}
vector<Expense>OperationOnFinance::loadExpensesFromLastMonth()
{
    Expense expense;
    vector <Expense> expensesFromLastMonth;
    int lastYear;
    int lastMonth = dateOperation.getLastMonth();
    int currentYear = dateOperation.getCurrentYear();
    if(lastMonth == 12)
    {
        lastYear = currentYear -1;
    }
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end())
    {
        int data = itr -> getDate();
        string date = AuxiliaryMethods::intOnString(data);
        int yearFromUsersDate = dateOperation.getYear(date);
        int monthFromUsersDate = dateOperation.getMonth(date);
        if (yearFromUsersDate == lastYear && monthFromUsersDate == lastMonth)
        {
            expense.setExpenseId(itr -> getExpenseId());
            expense.setUserId(itr -> getUserId());
            expense.setDate(data);
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expensesFromLastMonth.push_back(expense);
        }
        itr++;
    }

    return expensesFromLastMonth;
}



vector <Income> OperationOnFinance::sortIncomesFromSelectedPeriodOfTime(vector<Income>incomes)
{

    sort(incomes.begin(),incomes.end(),
         []( Income & lhs, Income & rhs)
    {
        return lhs.getDate()< rhs.getDate();
    });
    return incomes;
}
vector <Expense> OperationOnFinance::sortExpensesFromSelectedPeriodOfTime(vector<Expense>expenses)
{

    sort(expenses.begin(),expenses.end(),
         []( Expense & s, Expense & r)
    {
        return s.getDate()< r.getDate();
    });
    return expenses;
}

void OperationOnFinance::balanceFromLastMonth()
{
    cout << setprecision (2);
    cout << fixed; //stała notacja zmienno przecinkowa
    vector <Income> incomesFromLastMonth;
    vector <Income> sortedIncomesFromLastMonth;
    double totalIncomes;
    double totalExpenses;
    incomesFromLastMonth = loadIncomesFromLastMonth();
    sortedIncomesFromLastMonth = sortIncomesFromSelectedPeriodOfTime(incomesFromLastMonth);
    cout << "INCOMES" << endl;
    for(int i = 0; i < sortedIncomesFromLastMonth.size(); i++)
    {
        cout<<AuxiliaryMethods::intOnStringWithDashes(sortedIncomesFromLastMonth.at(i).getDate())<<" "<<sortedIncomesFromLastMonth.at(i).getItem()<< " " <<sortedIncomesFromLastMonth.at(i).getAmount()<<endl;
        totalIncomes += sortedIncomesFromLastMonth.at(i).getAmount();
    }
    cout << "Total incomes: " << totalIncomes << endl;
    cout << endl;
    vector <Expense> expensesFromLastMonth;
    vector <Expense> sortedExpensesFromLastMonth;
    expensesFromLastMonth = loadExpensesFromLastMonth();
    sortedExpensesFromLastMonth = sortExpensesFromSelectedPeriodOfTime(expensesFromLastMonth);
    cout << "EXPENSES"<<endl;
    for(int j = 0; j < sortedExpensesFromLastMonth.size(); j++)
    {
        cout<< AuxiliaryMethods::intOnStringWithDashes(sortedExpensesFromLastMonth.at(j).getDate())<<" "<<sortedExpensesFromLastMonth.at(j).getItem()<< " " <<sortedExpensesFromLastMonth.at(j).getAmount()<< endl;
        totalExpenses += sortedExpensesFromLastMonth.at(j).getAmount();
    }
    double balance = totalIncomes - totalExpenses;
    cout << "Total expenses: " << totalExpenses << endl<<endl;
    cout<< "Balance from last month : " << balance  <<endl;

    system("pause");
}

void OperationOnFinance::balanceFromTheSelectPeriod()
{
    cout << setprecision (2);
    cout << fixed; //stała notacja zmienno przecinkowa
    vector <Income> incomesFromSelectPeriod;
    vector <Income> sortedIncomesFromSelectPeriod;
    double totalIncomes;
    double totalExpenses;
    cout<<"Start date : " << endl;
    string dateStart = dateOperation.userDate();
    if(dateStart == "0")
    {
        cout << "Date is incorrect. Try again"<<endl;
        system("pause");
        return;
    }
    cout << "End date : " << endl;
    string dateEnd = dateOperation.userDate();
    if(dateEnd == "0")
    {
        cout << "Date is incorrect. Try again"<<endl;
        system("pause");
        return;
    }
    cout << "End date : " << endl;
    incomesFromSelectPeriod = loadIncomesFromSelectPeriod(dateStart,dateEnd);
    sortedIncomesFromSelectPeriod = sortIncomesFromSelectedPeriodOfTime(incomesFromSelectPeriod);
    cout << "INCOMES" << endl;
    for(int i = 0; i < sortedIncomesFromSelectPeriod.size(); i++)
    {
        cout<<AuxiliaryMethods::intOnStringWithDashes(sortedIncomesFromSelectPeriod.at(i).getDate())<<" "<<sortedIncomesFromSelectPeriod.at(i).getItem()<< " " <<sortedIncomesFromSelectPeriod.at(i).getAmount()<<endl;
        totalIncomes += sortedIncomesFromSelectPeriod.at(i).getAmount();
    }
    cout << "Total incomes: " << totalIncomes << endl;
    cout << endl;
    vector <Expense> expensesFromSelectPeriod;
    vector <Expense> sortedExpensesFromSelectPeriod;
    expensesFromSelectPeriod = loadExpensesFromSelectPeriod(dateStart,dateEnd);
    sortedExpensesFromSelectPeriod = sortExpensesFromSelectedPeriodOfTime(expensesFromSelectPeriod);
    cout << "EXPENSES"<<endl;
    for(int j = 0; j < sortedExpensesFromSelectPeriod.size(); j++)
    {
        cout<< AuxiliaryMethods::intOnStringWithDashes(sortedExpensesFromSelectPeriod.at(j).getDate())<<" "<<sortedExpensesFromSelectPeriod.at(j).getItem()<< " " <<sortedExpensesFromSelectPeriod.at(j).getAmount()<< endl;
        totalExpenses += sortedExpensesFromSelectPeriod.at(j).getAmount();
    }
    double balance = totalIncomes - totalExpenses;
    cout << "Total expenses: " << totalExpenses << endl<<endl;
    cout<< "Balance from select period : " << balance <<endl;

    system("pause");
}
vector<Expense>OperationOnFinance::loadExpensesFromSelectPeriod(string dateStart,string dateEnd)
{
    Expense expense;
    vector <Expense> expensesFromSelectPeriod;
    int startDate = dateOperation.dateToInteger(dateStart);
    int endDate= dateOperation.dateToInteger(dateEnd);

    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end())
    {
        int data = itr -> getDate();
        if (startDate <= itr->getDate() && endDate >= itr -> getDate())
        {
            expense.setExpenseId(itr -> getExpenseId());
            expense.setUserId(itr -> getUserId());
            expense.setDate((itr->getDate()));
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expensesFromSelectPeriod.push_back(expense);
        }
        itr++;
    }

    return expensesFromSelectPeriod;
}

vector<Income>OperationOnFinance::loadIncomesFromSelectPeriod(string dateStart,string dateEnd)
{
    Income income;
    vector <Income> incomesFromSelectPeriod;
    int startDate = dateOperation.dateToInteger(dateStart);
    int endDate= dateOperation.dateToInteger(dateEnd);
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end())
    {
        if (startDate <= itr->getDate() && endDate >= itr -> getDate())
        {
            income.setIncomeId(itr -> getIncomeId());
            income.setUserId(itr -> getUserId());
            income.setDate(itr -> getDate());
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            incomesFromSelectPeriod.push_back(income);
        }
        itr++;
    }

    return incomesFromSelectPeriod;
}

