#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"

#include <string>
#include <vector>
class clsUpdateCurrencyRateScreen : protected clsScreen
{


    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Currency.Country;
        cout << "\nLastName    : " << Currency.Code;
        cout << "\nFull Name   : " << Currency.Name;
        cout << "\nRate       : " << Currency.Rate;

        cout << "\n___________________\n";

    }


    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;
        NewRate = clsInputValidate::ReadNumber<float>();
        return NewRate;
    }

public:


    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("Update Currency Rate Screen");

        cout << "\nPlease enter the currency code: ";
        string CurrencyCode = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure that you want to update the currency rate? Y/N: ";
        char Answer = 'n';
        cin >> Answer;
        float NewRate = 0;
        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
            Currency.UpdateRate(_ReadRate());


            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);

        }

    }
};

