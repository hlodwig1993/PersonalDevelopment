#include "PersonalDevelopment.h"
#include "AuxiliaryMethods.h"


using namespace std;


char chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << ">>> MAIN MENU <<<" << endl;
    cout << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}
char chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << ">>> USER MENU <<<" << endl;
    cout << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance for the current month" << endl;
    cout << "4. Balance for the previous month" << endl;
    cout << "5. Balance for the selected period" << endl;
    cout << "6. Change Password" << endl;

    cout << "9. Log Out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}



int main()
{
    PersonalDevelopment personalDevelopment ("FileWithUsers.xml","Incomes.xml","Expenses.xml");

    char choice;

    while(true)
    {

        if(!personalDevelopment.userLoggedIn())
        {


            choice = chooseOptionFromMainMenu();
            switch(choice)
            {
            case '1' :
                personalDevelopment.signUp();
                break;
            case '2' :
               personalDevelopment.signIn();
                break;
            case '9' :
                exit(0);
                break;
            default:
                cout<<endl<<"There is no such option in the main menu"<<endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = chooseOptionFromUserMenu();
            switch(choice)
            {
            case '1' :
                personalDevelopment.addIncome();
                break;
            case '2' :
                personalDevelopment.addExpense();
                break;
            case '3' :
                personalDevelopment.balanceForTheCurrentMonth();
                break;
            case '4' :
                personalDevelopment.balanceFromLastMonth();
                break;
            case '5' :
                personalDevelopment.balanceFromTheSelectPeriod();
                break;
            case '6' :
                personalDevelopment.changePassword();
                break;
            case '9' :
                personalDevelopment.logOut();
                break;
            default:
                cout<<endl<<"There is no such option in the main menu"<<endl;
                system("pauze");
                break;
            }

        }



    }
}

