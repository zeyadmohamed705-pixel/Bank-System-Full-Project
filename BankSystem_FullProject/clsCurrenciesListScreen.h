#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include <string>
#include <vector>

class clsCurrenciesListScreen : protected clsScreen
{
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << "" << "| " << left << setw(35) << Currency.Country;
        cout << "| " << left << setw(10) << Currency.Code;
        cout << "| " << left << setw(40) << Currency.Name;
        cout << "| " << left << setw(10) << Currency.Rate;

    }


public:

    static void ShowCurrenciesListScreen()
    {

        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "Currency List Screen";
        string SubTitle = "\t\t" + to_string(vCurrencies.size()) + " Currency(ies)";

        _DrawScreenHeader(Title, SubTitle);
        cout << "\n" << setw(8) << "" << "------------------------------------------------------------------------------------------------------------\n";
        cout << setw(8) << "" << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(40) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate";


        cout << "\n" << setw(8) << "" << "------------------------------------------------------------------------------------------------------------\n";

        if (vCurrencies.size() == 0)
        {
            cout << "\n \t\t\t\t\t No Currencies Available in the system";
        }

        else
        {
            for (clsCurrency& Currency : vCurrencies)
            {
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
            cout << endl << setw(8) << "" << " ------------------------------------------------------------------------------------------------------------\n";

        }
    }
	
};

