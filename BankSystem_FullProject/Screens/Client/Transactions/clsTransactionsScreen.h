#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDeposieScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogListScreen.h"



#include <string>
#include <vector>
class clsTransactionsScreen :protected clsScreen
{
private:
	static short _ReadTransactionsMenueOption()
	{
		cout << setw (37) << left << "" << "Choose what do you want to do? [1 to 6]?\n ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6);
		return Choice;
	}
	enum enTransactionsMenueOptions { eDeposite = 1, eWithdraw = 2, eTotalBalances = 3,eTransfer = 4 ,eTransferLog = 5,eShowMainMenue = 6 };

	static void _ShowDepositeScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsDeposieScreen::ShowDepositeScreen();
	}
	static void _ShowWithDrawScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLog()
	{
		//cout << "\nscreen will be soon here ISA ";
		clsTransferLogListScreen::ShowTransferLogListScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		system("cls");
		ShowTransactionsScreenMenue();
	}



	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLog();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowMainMenue:
		{
			// do nothing here the main screen will handle it :-) ;
		}

		}
	}
public:

	static void ShowTransactionsScreenMenue()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pTransactions))
		{
			return; // this will exit the function and it will not continue
		}
		_DrawScreenHeader("Transactions Screen");
		cout << setw(37) << left << "" << "===================================\n";
		cout << setw(37) << left << "" << "\tTransactions Menue \n";
		cout << setw(37) << left << "" << "===================================\n";
		cout << setw(37) << left << "" << "\t [1] Deposite\n";
		cout << setw(37) << left << "" << "\t [2] Withdraw\n";
		cout << setw(37) << left << "" << "\t [3] Total Balances\n";
		cout << setw(37) << left << "" << "\t [4] Transfer \n";
		cout << setw(37) << left << "" << "\t [5] Transfer Log \n";
		cout << setw(37) << left << "" << "\t [6] Main Menue\n";
		cout << setw(37) << left << "" << "===================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());




	}
};

