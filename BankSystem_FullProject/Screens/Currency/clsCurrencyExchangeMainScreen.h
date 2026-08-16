#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"



#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]?\n ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5);
		return Choice;
	}
	enum enCurrencyExchangeMainMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5 };

	static void _ShowListCurrencies()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrency()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}
	static void _ShowUpdateRate()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculator()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GetBackToCurrenciesMenue()
	{
		cout << "\npress any key to get back to currencies Menue";
		system("pause>0");
		ShowCurrenciesMenue();

	}


	static void _PerformTransactionsMenueOption(enCurrencyExchangeMainMenueOptions CurrencyMenueOption)
	{
		switch (CurrencyMenueOption)
		{
		case clsCurrencyExchangeMainScreen::eListCurrencies:
		{
			system("cls");
			_ShowListCurrencies();
			_GetBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrency();
			_GetBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRate();
			_GetBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GetBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eShowMainMenue:
		{
			// we should do nothing here, main screen will handle it
		}

		};

	}
public:

	static void ShowCurrenciesMenue()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pCurrencyExchangeMainScreen))
		{
			return; // this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "===================================\n";
		cout << setw(37) << left << "" << "\tCurrency Exchange Menue \n";
		cout << setw(37) << left << "" << "===================================\n";
		cout << setw(37) << left << "" << "\t [1] List Currencies\n";
		cout << setw(37) << left << "" << "\t [2] Find Currency\n";
		cout << setw(37) << left << "" << "\t [3] Update Rate\n";
		cout << setw(37) << left << "" << "\t [4] Currency Calculator \n";
		cout << setw(37) << left << "" << "\t [5] Main Menue\n";
		cout << setw(37) << left << "" << "===================================\n";

		_PerformTransactionsMenueOption((enCurrencyExchangeMainMenueOptions)_ReadTransactionsMenueOption());

	}

};