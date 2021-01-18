#include "FileWithIncome.h"
#include "AuxiliaryMethods.h"

void FileWithIncome::addIncomeToFile(Income income)
{
    CMarkup userFile;

    bool fileExists = userFile.Load(nameOfTheFileWithIncome);
    if(!fileExists)
    {
        userFile.AddElem("Incomes");
    }
    userFile.FindElem();
    userFile.IntoElem();
    userFile.AddElem( "UserId",income.getUserId() );
    userFile.AddElem( "IncomeId",income.getIncomeId() );
    int date = income.getDate();
    string data = AuxiliaryMethods::intOnStringWithDashes(date);

    userFile.AddElem( "Date", data );
    userFile.AddElem( "Item Name", income.getItem() );

    userFile.AddElem( "Amount", AuxiliaryMethods::doubleOnString(income.getAmount()) );

    userFile.Save(nameOfTheFileWithIncome);
}

vector <Income> FileWithIncome::loadIncomesFromFile(int loggedUserId)
{
    Income income;
    vector<Income>incomes;

    CMarkup incomeFile;
    incomeFile.Load(nameOfTheFileWithIncome);
    incomeFile.ResetPos();
    incomeFile.FindElem();
    incomeFile.IntoElem();
    while(true)
    {

            bool nextPositionExists = incomeFile.FindElem();
            if (nextPositionExists == false)
            {
                break;
            }
            string id = incomeFile.GetElemContent();
            int idA = atoi(id.c_str());
            income.setUserId(idA);
            incomeFile.FindElem();
            string id1 = incomeFile.GetElemContent();
            int idA1 = atoi(id1.c_str());
            income.setIncomeId(idA1);
            incomeFile.FindElem();
            string date = incomeFile.GetElemContent();
            int data = dateOperation.dateToInteger(date);
            income.setDate(data);
            incomeFile.FindElem();
            string item = incomeFile.GetElemContent();
            income.setItem(item);
            incomeFile.FindElem();
            string amount = incomeFile.GetElemContent();
            double amountD = AuxiliaryMethods::stringOnDouble (amount);
            income.setAmount(amountD);
            idOfLastIncome = idA1;
            if (loggedUserId == income.getUserId()){
            incomes.push_back(income);
            }

    }

    return incomes;
}

int FileWithIncome::getTheIdOfLastIncome() {
    CMarkup incomeFile;
    incomeFile.Load(nameOfTheFileWithIncome);
    incomeFile.ResetPos();
    incomeFile.FindElem();
    incomeFile.IntoElem();
    while(true)
    {

            bool nextPositionExists = incomeFile.FindElem();
            if (nextPositionExists == false)
            {
                break;
            }
            incomeFile.FindElem();
            string id1 = incomeFile.GetElemContent();
            int idA1 = atoi(id1.c_str());;
            incomeFile.FindElem();
            incomeFile.FindElem();
            incomeFile.FindElem();
            idOfLastIncome = idA1;
    }

   return idOfLastIncome;
}
