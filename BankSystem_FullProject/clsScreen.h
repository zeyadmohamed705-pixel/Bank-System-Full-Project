#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string Subtitle = "")
	{
		cout << "\t\t\t\t\t ________________________________________________";
		cout << "\n\n\t\t\t\t\t\t  " << Title;
		if (Subtitle != "")
		{
			cout << "\n\t\t\t\t\t" << Subtitle;
		}
		cout << "\n\t\t\t\t\t ________________________________________________" << endl;
		//AddUserNameAndDate();
		cout << "\n\t\t\t\t\t Username: " << CurrentUser.UserName << endl;
		cout << "\n\t\t\t\t\t Date: " <<clsDate::DateToString(clsDate()) << endl;


		
	}
	static bool CheckAccessRights(clsUser::enPermessions ScreenPermission)
	{
		if (!CurrentUser.CheckAccessPermessions(ScreenPermission))
		{
			cout << "\n\t\t\t\t -----------------------------------------------------------";
			cout << "\n\t\t\t\t\t Access denied, Please contact your admin";
			cout << "\n\t\t\t\t -----------------------------------------------------------";
			return false;

		}
		else
			return true;
	};

	static void AddUserNameAndDate()
	{

		cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate: ";
		clsDate Date = clsDate();
		Date.Print();


	}
};

