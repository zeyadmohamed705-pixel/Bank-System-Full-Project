#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"

#include <string>
#include <vector>

class clsCurrencyCalculatorScreen : protected clsScreen
{

    static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card")
    {
        cout << Title;
        cout << "\n___________________";
        cout << "\nFirstName   : " << Currency.Country;
        cout << "\nLastName    : " << Currency.Code;
        cout << "\nFull Name   : " << Currency.Name;
        cout << "\nRate       : " << Currency.Rate;

        cout << "\n___________________\n";

    }


    static float _ReadAmount()
    {
        cout << "\nEnter Amout to exchange: ";
        float Amount = 0;
        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode;
        cout << Message << ": ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found enter onther one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;


    }
    static void _PrintCalulationsResults(float Amount,clsCurrency CurrencyFrom, clsCurrency CurrencyTo )
    {

        _PrintCurrencyCard(CurrencyFrom, "Converting From : ");
        float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

        cout << Amount << " " << CurrencyFrom.Code << " = " << AmountInUSD << " USD\n";

        if (CurrencyTo.Code == "USD" || CurrencyTo.Code == "usd")
            return;

        _PrintCurrencyCard(CurrencyTo, "Converting From USD to: ");
        float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

        cout << Amount << " " << CurrencyFrom.Code << " = " << AmountInCurrencyTo << " " << CurrencyTo.Code;

    }

public:


    static void ShowCurrencyCalculatorScreen()
    {



        char Continue = 'y';
        while (Continue == 'Y' || Continue == 'y')
        {
            system("cls");
            _DrawScreenHeader("Calculator Screen");
            clsCurrency CurrencyFrom = _GetCurrency("\n Please Enter Currency1 Code");
            clsCurrency CurrencyTo = _GetCurrency("\n Please Enter Currency2 Code");
            float Amount = _ReadAmount();

            _PrintCalulationsResults(Amount, CurrencyFrom, CurrencyTo);
            cout << "\nDo you want to perform other calculation?: Y/N";
            cin >> Continue;

        };



    }

};

