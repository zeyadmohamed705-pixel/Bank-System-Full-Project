#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"

#include <string>
#include <vector>
class clsFindCurrencyScreen : protected clsScreen
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

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "Currency is found";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n Currency was not found\n";
        };
    }

public:


    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("Find Currency Screen");

        cout << "\nFind by [1] for Code [2] for Country: ";
        short Answer = 0;
        Answer = clsInputValidate::ReadShortNumberBetween(1, 2);
        if (Answer == 1)
        {
            cout << "\nPlease Enter a Country Code: ";
            string CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);


        }
        if (Answer == 2)
        {
            cout << "\nPlease Enter a Country Name: ";
            string CountryName = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _ShowResults(Currency);


        }





    }
};

