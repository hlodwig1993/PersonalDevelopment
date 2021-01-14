#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"

vector <Income> FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId) {
    CMarkup incomesFile;
    incomesFile.Load( nameOfTheFileWithIncomes );
    incomesFile.ResetPos();
    incomesFile.FindElem();
    incomesFile.IntoElem();
    while (true) {
        bool ifNextPositionExists = incomesFile.FindElem();
        if (ifNextPositionExists == false) {
            break;
        }
        string incomeIdAsAString = incomesFile.GetElemContent();
        int incomeId = atoi(incomeIdAsAString.c_str());
        income.setIncomeId(incomeId);
        incomesFile.FindElem();
        string userIdAsAString = incomesFile.GetElemContent();
        int userId = atoi(userIdAsAString.c_str());
        income.setUserId(userId);
        incomesFile.FindElem();
        string data = incomesFile.GetElemContent();
        int date = AuxiliaryMethods::stringOnInt(data);
        income.setDate(date);
        incomesFile.FindElem();
        string item = incomesFile.GetElemContent();
        income.setItem(item);
        incomesFile.FindElem();
        string amountAsAString = incomesFile.GetElemContent();
        stringstream ss;
        double amountAsADouble;
        ss << amountAsAString;
        ss >> amountAsADouble;
        income.setAmount(amountAsADouble);
        idOfLastIncome++;
        if (loggedInUserId == income.getUserId()) {
            incomes.push_back(income);
        }
    }
    return incomes;
}

int FileWithIncomes::getTheIdOfLastIncome() {
    return idOfLastIncome;
}

void FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup incomesFile;
    bool ifFileWithIncomesExists = incomesFile.Load( nameOfTheFileWithIncomes );
    if (ifFileWithIncomesExists == false) {
        incomesFile.AddElem( "Incomes" );
        incomesFile.IntoElem();
    }
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "incomeId", income.getIncomeId() );
    incomesFile.AddElem( "userId", income.getUserId() );
    incomesFile.AddElem( "date", income.getDate() );
    incomesFile.AddElem( "item", income.getItem() );
    ostringstream strs;
    strs << income.getAmount();
    string amountAsString = strs.str();
    incomesFile.AddElem( "amount", amountAsString );
    incomesFile.Save( nameOfTheFileWithIncomes );
}
