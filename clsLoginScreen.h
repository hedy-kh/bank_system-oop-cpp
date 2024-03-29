#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include"clsCETT.h"
class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short Trial = 3;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                Trial--;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "you have " << Trial << " trial(s) to login\n";
               
               
            }
            if (Trial == 0)
            {
                cout << "you are locked after 3 trials \n";
                return false;
            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
           

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return _Login();

    }

};

