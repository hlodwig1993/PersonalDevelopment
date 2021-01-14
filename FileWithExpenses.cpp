#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

vector <Expense> FileWithExpenses::loadExpensesOfLoggedInUserFromFile(int loggedInUserId) {
    CMarkup expensesFile;
    expensesFile.Load( nameOfTheFileWithExpenses );
    expensesFile.ResetPos();
    expensesFile.FindElem();
    expensesFile.IntoElem();
    while (true) {
        bool ifNextPositionExists = expensesFile.FindElem();
        if (ifNextPositionExists == false) {
            break;
        }
        string expenseIdAsAString = expensesFile.GetElemContent();
        int expenseId = atoi(expenseIdAsAString.c_str());
        expense.setExpenseId(expenseId);
        expensesFile.FindElem();
        string userIdAsAString = expensesFile.GetElemContent();
        int userId = atoi(userIdAsAString.c_str());
        expense.setUserId(userId);
        expensesFile.FindElem();
        string data = expensesFile.GetElemContent();
        int date = AuxiliaryMethods::stringOnInt(data);
        expense.setDate(date);
        expensesFile.FindElem();
        string item = expensesFile.GetElemContent();
        expense.setItem(item);
        expensesFile.FindElem();
        string amountAsAString = expensesFile.GetElemContent();
        stringstream ss;
        double amountAsADouble;
        ss << amountAsAString;
        ss >> amountAsADouble;
        expense.setAmount(amountAsADouble);
        idOfLastExpense++;
        if (loggedInUserId == expense.getUserId()) {
            expenses.push_back(expense);
        }
    }
    return expenses;
}

int FileWithExpenses::getTheIdOfLastExpense() {
    return idOfLastExpense;
}

void FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup expensesFile;
    bool ifFileWithexpensesExists = expensesFile.Load( nameOfTheFileWithExpenses );
    if (ifFileWithexpensesExists == false) {
        expensesFile.AddElem( "ExpensesList" );
        expensesFile.IntoElem();
    }
    expensesFile.FindElem();
    expensesFile.IntoElem();
    expensesFile.AddElem( "expenseId", expense.getExpenseId() );
    expensesFile.AddElem( "userId", expense.getUserId() );
    expensesFile.AddElem( "date", expense.getDate() );
    expensesFile.AddElem( "item", expense.getItem() );
    ostringstream strs;
    strs << expense.getAmount();
    string amountAsString = strs.str();
    expensesFile.AddElem( "amount", amountAsString );
    expensesFile.Save( nameOfTheFileWithExpenses );
}
