#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUser.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


#include "clsInputValidate.h"
class clsManageUsersScreen : protected clsScreen
{
private:
	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]?\n ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6);
		return Choice;
	}
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static void _ShowListUsersScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsUsersListScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsAddNewUser::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsFindUserScreen::ShowFindUserScreen();
	}
	
	static void _ShowMainMenue()
	{

	}
	static void _GoBackManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		system("cls");
		ShowManageUsersScreenMenue();
	}



	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackManageUsersMenue();
			break;

		}
		case enManageUsersMenueOptions::eMainMenue:
		{

		}

		}
	}
public:

	static void ShowManageUsersScreenMenue()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pManageUsers))
		{
			return; // this will exit the function and it will not continue
		}
		_DrawScreenHeader("Manage Users Screen");
		cout << setw(37) << left << "" << "===================================\n";
		cout << setw(37) << left << "" << "\tTransactions Menue \n";
		cout << setw(37) << left << "" << "===================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());



	}
};

