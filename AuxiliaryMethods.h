#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include <winbase.h>

using namespace std;

class AuxiliaryMethods
{
public:
    static string intOnString(int number);
    static string getLine();
    static int stringOnInt (string number);
    static char getChar();
    static double stringOnDouble(string number);
    static string intOnStringWithDashes(int number);
    static string doubleOnString (double number);



};
#endif
