#include "AuxiliaryMethods.h"
using namespace std;

string AuxiliaryMethods::getLine()
{
    string entry = "";
    cin.sync();
    cin.clear();
    getline(cin, entry);
    return entry;
}



string AuxiliaryMethods::intOnString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::intOnStringWithDashes(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    string year = str.substr( 0, 4);
    string month = str.substr( 4, 2);
    string day = str.substr( 6, 2);
    string results = year + "-" + month + "-" + day;
    return results;

}


int AuxiliaryMethods::stringOnInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}



char AuxiliaryMethods::getChar()
{
    string wejscie = "";
    char znak  = {0};
    cin.sync();

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "This is not single char. Try again" << endl;
        system ("pause");
    }
    return znak;
}
double AuxiliaryMethods::stringOnDouble(string number)
{
    size_t a = number.find(",");
    if (a != string::npos)
        number.replace(a,1,".");
    stringstream ss;
    double numberDouble;
    ss << number;
    ss >> numberDouble;

    return numberDouble;
}
string AuxiliaryMethods::doubleOnString (double number)
{
    ostringstream strs;
    strs << number;
    string amountAsString = strs.str();
    return amountAsString;
}

