#ifndef DATEOPERATION_H
#define DATEOPERATION_H
#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <sstream>

using namespace std;

class DateOperation
{

    string currentlyDate;
    bool numberOfDays(string currentlyDate);


public:
    string CurrentlyDate();
    string userDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getYear(string date);
    int getMonth(string date);
    int dateToInteger(string currentlyDate);
    int getLastMonth();
};


#endif
