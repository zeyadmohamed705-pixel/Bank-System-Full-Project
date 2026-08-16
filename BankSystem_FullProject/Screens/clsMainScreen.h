#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterListScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

#include "Global.h"







using namespace std;

class clsMainScreen : protected clsScreen
{

private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eLoginRegister = 8 ,eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenueOptions()
	{
		cout << setw(37) << left << "" << "choose what do you want to do from [1] to [10] ?\n";

		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}
	void static _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";		
		system("pause>0");
		ShowMainMenueScreen();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\n the Screen Will be here soon...\n";
		clsClientsListScreen::ShowClientsList();
	};

	static void _ShowAddNewClientScreen()
	{
		//cout << "\n the Screen Will be here soon...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();

	};
	static void _ShowDeleteClientScreen()
	{
		//cout << "\n the Screen Will be here soon...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();

	};
	static void _ShowUpdateClientScreen()
	{
		//cout << "\n the Screen Will be here soon...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();


	};
	static void _ShowFindClientsScreen()
	{
		//cout << "\n the Screen Will be here soon...\n";
		clsFindClientScreen::ShowFindClientScreen();

	};
	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsScreenMenue();

	};
	static void _ShowManageUsersMenue()
	{
		//cout << "\n the Screen Will be here soon...\n";
		clsManageUsersScreen::ShowManageUsersScreenMenue();

	};

	static void _ShowLoginRegisterListScreen()
	{
		clsLoginRegisterListScreen::ShowLoginRegisterlistScreen();
	}

	static void _clsCurrencyExchangeMainScreen()
	{
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		// clsLoginScreen::ShowLoginScreen(); // cause an error  adding the the loginScreen() from Mainmenue the program will crash and compiler will stop working 
		//because the LoginScreen calls the clsMainScreen::ShowMainMenue() and as stack flow the  loginScreen will wait till  the clsMainScreen::ShowMainMenue() finished 
		// but here we are adding other stack flow that the MainScreen() will call Login() (it's too complex for the compiler ) - this problem called circular reference 
	}

	void static _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterListScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_clsCurrencyExchangeMainScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eExit:
		{
			system("cls");
			//_ShowEndScreen();
			 _Logout();
			 break;

		}
		}
	}
public:

	static void ShowMainMenueScreen()
	{

		system("cls");
		_DrawScreenHeader("\tMain Screen");
		cout << setw(37) << left << "" << "  ========================================\n";
		cout << setw(37) << left << "" << "\t\tMain Menue Screen\n";
		cout << setw(37) << left << "" << "  ========================================\n";

		cout << setw(37) << left << "" << "\t [1] Show Client List\n"; 		// note:   setw(37) << left << "" means put 37 free space first

		cout << setw(37) << left << "" << "\t [2] Add New Client\n";
		cout << setw(37) << left << "" << "\t [3] Delete Client \n";
		cout << setw(37) << left << "" << "\t [4] Update Client\n";
		cout << setw(37) << left << "" << "\t [5] Find Client \n";
		cout << setw(37) << left << "" << "\t [6] Transactions\n";
		cout << setw(37) << left << "" << "\t [7] Manage Users\n";
		cout << setw(37) << left << "" << "\t [8] Login Register\n";
		cout << setw(37) << left << "" << "\t [9] Currency Exchange\n";

		cout << setw(37) << left << "" << "\t [10] Log Out\n";

		cout << setw(37) << left << "" << "  ========================================\n";



		
		_PerformMainMenueOption( (enMainMenueOptions)_ReadMainMenueOptions() );

	}

};

