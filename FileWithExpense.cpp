#include "FileWithExpense.h"
#include "AuxiliaryMethods.h"

void FileWithExpense::addExpenseToFile(Expense expense)
{
    CMarkup userFile;

    bool fileExists = userFile.Load(nameOfTheFileWithExpense);
    if(!fileExists)
    {
        userFile.AddElem("Expense");
    }
    userFile.FindElem();
    userFile.IntoElem();
    userFile.AddElem( "UserId",expense.getUserId() );
    userFile.AddElem( "ExpenseId",expense.getExpenseId() );
    int date = expense.getDate();
    string data = AuxiliaryMethods::intOnStringWithDashes(date);

    userFile.AddElem( "Date", data );
    userFile.AddElem( "Item Name", expense.getItem() );

    userFile.AddElem( "Amount", AuxiliaryMethods::doubleOnString(expense.getAmount()) );

    userFile.Save(nameOfTheFileWithExpense);
}
vector <Expense> FileWithExpense::loadExpensesFromFile(int loggedInUserId)
{
    Expense expense;
    vector<Expense>expenses;

    CMarkup expenseFile;

    expenseFile.Load(nameOfTheFileWithExpense);
    expenseFile.ResetPos();
    expenseFile.FindElem();
    expenseFile.IntoElem();

    while(true)
    {

            bool nextPositionExists = expenseFile.FindElem();
            if (nextPositionExists == false)
            {
                break;
            }
            string id = expenseFile.GetElemContent();
            int idA = atoi(id.c_str());
            expense.setUserId(idA);
            expenseFile.FindElem();

            string id1 = expenseFile.GetElemContent();
            int idA1 = atoi(id1.c_str());
            expense.setExpenseId(idA1);
            expenseFile.FindElem();

            string date = expenseFile.GetElemContent();
            int data = dateOperation.dateToInteger(date);
            expense.setDate(data);
            expenseFile.FindElem();

            string item = expenseFile.GetElemContent();
            expense.setItem(item);
            expenseFile.FindElem();

            string amount = expenseFile.GetElemContent();
            double amountD = AuxiliaryMethods::stringOnDouble (amount);
            expense.setAmount(amountD);
            if(loggedInUserId == expense.getUserId())
            {
            expenses.push_back(expense);
            }
    }
    return expenses;
}

int FileWithExpense::getTheIdOfLastExpense() {
    CMarkup expenseFile;

    expenseFile.Load(nameOfTheFileWithExpense);
    expenseFile.ResetPos();
    expenseFile.FindElem();
    expenseFile.IntoElem();

    while(true)
    {

            bool nextPositionExists = expenseFile.FindElem();
            if (nextPositionExists == false)
            {
                break;
            }
            expenseFile.FindElem();
            string id1 = expenseFile.GetElemContent();
            int idA1 = atoi(id1.c_str());
            expenseFile.FindElem();
            expenseFile.FindElem();
            expenseFile.FindElem();
            idOfLastExpense = idA1;
    }
    return idOfLastExpense;
}
