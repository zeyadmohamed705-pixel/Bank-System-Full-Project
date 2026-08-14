#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsUser.h"


class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFailed = false;
		string Username, Password;

		short FailedLoginCounter = 0;
		do
		{
			if (LoginFailed)
			{
				cout << "\n Invalid Username/Password";
				FailedLoginCounter++;
				cout << "\n you have "<< 3- FailedLoginCounter << " Trials";

				if (FailedLoginCounter == 3)
				{
					cout << " \n\nyou are locked after 3 failed trials";
					return false;
				}
			}
			cout << "\n\nEnter Username: ";
			cin >> Username;

			cout << "\nEnter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFailed = CurrentUser.IsEmpty();


		} while (LoginFailed);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenueScreen();

		return true;
	}
public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tlogIn Screen");
		return _Login();
	}
};

