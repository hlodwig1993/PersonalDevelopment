#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;


class UserMenager
{
    int loggedInUserId ;
    FileWithUsers fileWithUsers;
    int getIdOfLastUser();
    int downloadIdOfNewUser();
    vector <User> users;


public:
    UserMenager (string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers)
    {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void signUp();
    void signIn();
    bool userLoggedIn();
    int logOut();
    int getIdOfLoggedInUser();
    void changePassword();

};


#endif







