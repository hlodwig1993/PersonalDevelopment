#include "UserMenager.h"
#include "AuxiliaryMethods.h"

void UserMenager::signUp()
{
    User user;
    int userId;
    string name;
    string surname;
    string login;
    string password;

    user.setUserId(downloadIdOfNewUser());
    cout << "Enter yours name :";
    name = AuxiliaryMethods::getLine();
    user.setUserName(name);
    cout << "Enter yours surname :";
    surname = AuxiliaryMethods::getLine();
    user.setUserSurname(surname);
    cout << "Enter the login :";
    login = AuxiliaryMethods::getLine();
    user.setUserLogin(login);
    cout << "Enter the password :";
    password = AuxiliaryMethods::getLine();
    user.setUserPassword(password);

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "User has been added." << endl;
    system("pause");

}

int UserMenager::downloadIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;

}
int UserMenager::getIdOfLastUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() ;

}

void UserMenager::signIn()
{
    User user;
    loggedInUserId = 0;
    int i = 0;
    string login = "";
    string password = "";

    cout << "Enter login :";
    login = AuxiliaryMethods::getLine();


    for(int i= 0; i < users.size(); i++)
    {

        if(users[i].getUserLogin() == login)
        {

            for (int attemptsNumber = 2; attemptsNumber >= 0; attemptsNumber--)
            {
                cout << "Enter password : ";
                password = AuxiliaryMethods::getLine();

                if (users[i].getUserPassword() != password)
                {
                    cout << endl << "Wrong password. You have " << attemptsNumber << " attempts left: "<<endl;

                }
                else
                {
                    cout << endl << "You are logged in." << endl << endl;
                    loggedInUserId = users[i].getUserId();
                    system("pause");
                    return;
                }
            }
            cout << "Incorrect password has been entered 3 times." << endl;
            system("pause");
            return;
        }

    }
    cout<< "There is no such login in our database" <<endl;
    system("pause");

}
bool UserMenager::userLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}
void UserMenager::changePassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    cin >> newPassword;

    for (int i = 0; i<users.size(); i++) {
        if (users[i].getUserId() == loggedInUserId) {
            users[i].setUserPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.addAllUsersToFile(users);
}

int UserMenager::logOut()
{
    return loggedInUserId = 0;
}
int UserMenager::getIdOfLoggedInUser() {
    return loggedInUserId;
}
