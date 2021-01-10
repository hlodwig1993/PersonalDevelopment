#include "FileWithUsers.h"


void FileWithUsers::addUserToFile(User user)
{
    CMarkup userFile;

    bool fileExists = userFile.Load(nameOfFileWithUsers);
    if(!fileExists)
    {
        userFile.AddElem("Users");
    }
    userFile.FindElem();
    userFile.IntoElem();
    userFile.AddElem( "User" );
    userFile.IntoElem();
    userFile.AddElem( "UserId",user.getUserId() );
    userFile.AddElem( "Name", user.getUserName() );
    userFile.AddElem( "Surname", user.getUserSurname() );
    userFile.AddElem( "Login", user.getUserLogin() );
    userFile.AddElem( "Password", user.getUserPassword() );

    userFile.Save(nameOfFileWithUsers);

}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector<User>users;

    CMarkup userFile;

    userFile.Load(nameOfFileWithUsers);
    userFile.ResetPos();
    userFile.FindElem();
    userFile.IntoElem();

    while(true)
    {
        userFile.FindElem();
        userFile.IntoElem();
        int i=1;
        if(i==1)
        {

            bool nextPositionExists = userFile.FindElem();
            if (nextPositionExists == false)
            {
                break;
            }
            string id = userFile.GetElemContent();
            int idA = atoi(id.c_str());
            user.setUserId(idA);
            userFile.FindElem();
            string name = userFile.GetElemContent();
            user.setUserName(name);
            userFile.FindElem();
            string surname = userFile.GetElemContent();
            user.setUserSurname(surname);
            userFile.FindElem();
            string login = userFile.GetElemContent();
            user.setUserLogin(login);
            userFile.FindElem();
            string password = userFile.GetElemContent();
            user.setUserPassword(password);
            users.push_back(user);
            userFile.OutOfElem();
        }
    }
    return users;
}

void FileWithUsers::addAllUsersToFile(vector <User> &users) {
    CMarkup userFile;
    userFile.AddElem( "Users" );
    userFile.IntoElem();
    userFile.AddElem("User");
    userFile.FindElem();
    userFile.IntoElem();
    vector <User>::iterator itrEnd = --users.end();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        userFile.AddElem( "Id", itr -> getUserId() );
        userFile.AddElem( "Name", itr -> getUserName() );
        userFile.AddElem( "Surname", itr -> getUserSurname() );
        userFile.AddElem( "Login", itr -> getUserLogin() );
        userFile.AddElem( "Password", itr -> getUserPassword() );
        userFile.Save( nameOfFileWithUsers );
    }
}
