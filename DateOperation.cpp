#include "DateOperation.h"
#include "AuxiliaryMethods.h"

string DateOperation::CurrentlyDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    string yearString = AuxiliaryMethods::intOnString(st.wYear);
    if(yearString.length() == 1)
    {
        yearString = "0" + yearString;
    }

    string monthString = AuxiliaryMethods::intOnString(st.wMonth);
    if(monthString.length() == 1)
    {
        monthString = "0" + monthString;
    }

    string dayString= AuxiliaryMethods::intOnString(st.wDay);
    if(dayString.length() == 1)
    {
        dayString = "0" + dayString;
    }


    currentlyDate = yearString + "-" + monthString + "-" + dayString;


    return currentlyDate;
}
int DateOperation::getCurrentYear()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    return year;
}
int DateOperation::getCurrentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int month = st.wMonth;
    return month;
}
string DateOperation::userDate()
{
    currentlyDate = "";
    cout << "Please enter the date (yyyy-mm-dd): ";
    currentlyDate = AuxiliaryMethods::getLine();
    if (currentlyDate.length() < 10 || currentlyDate.length() > 10)
    {
        currentlyDate = "0";
        return currentlyDate;

    }
    else if(numberOfDays(currentlyDate))
    {
        return currentlyDate;
    }
    else
        return "0";
}




bool DateOperation::numberOfDays(string currentlyDate)
{
    string year = currentlyDate.substr( 0, 4);
    int yearInt = AuxiliaryMethods::stringOnInt(year);
    string month = currentlyDate.substr( 5, 2);
    int monthInt = AuxiliaryMethods::stringOnInt(month);
    string day = currentlyDate.substr( 8, 2);
    int dayInt = AuxiliaryMethods::stringOnInt(day);


    switch(monthInt)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (1 > dayInt || dayInt > 31)
        {
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (1> dayInt|| dayInt >30)
        {
            return false;
        }

        break;
    case 2:
        if (((yearInt % 4 == 0) && (yearInt % 100 != 0)) || (yearInt % 400 == 0))
        {
            if(1 >dayInt || dayInt > 29)
            {
                return false;
            }
            break;
        }
        else if(1 > dayInt || dayInt >28)
        {
            return false;
            break;
        }
    }
    return true;
}


int DateOperation::dateToInteger(string currentlyDate)
{
    string year = currentlyDate.substr( 0, 4);
    string month = currentlyDate.substr( 5, 2);
    string day = currentlyDate.substr( 8, 2);
    string date = year + month + day;

    int dataInt = AuxiliaryMethods::stringOnInt(date);

    return dataInt;

}

int DateOperation::getYear(string date)
{

    string year = date.substr( 0, 4);
    int yearInt = AuxiliaryMethods::stringOnInt(year);
    return yearInt;
}
int DateOperation::getMonth(string date)
{

    string year = date.substr( 4, 2);
    int yearInt = AuxiliaryMethods::stringOnInt(year);
    return yearInt;
}
