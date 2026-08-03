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

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nConvert Form:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Currency.Country;
        cout << "\nLastName    : " << Currency.Code;
        cout << "\nFull Name   : " << Currency.Name;
        cout << "\nRate       : " << Currency.Rate;

        cout << "\n___________________\n";

    }


    static float _ReadAmount()
    {
        float Amount = 0;
        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }
    static double _CurrencyCalculator(clsCurrency& ExchangeFromCurrency, clsCurrency& ExchangeToCurrency, double ExchaneAmount)
    {
        double Result = 0;
        if (ExchangeToCurrency.Code == "USD")
        {
            Result = ExchangeFromCurrency.ConvertToUSD(ExchaneAmount);
            return Result;
        }

        else
        {
            Result = ExchangeFromCurrency.ConvertToUSD(ExchaneAmount);
            Result = ExchangeToCurrency.ConvertFromUSD(Result);
            return Result;

        }


    }

public:


    static void ShowCurrencyCalculatorScreen()
    {
        _DrawScreenHeader("Calculator Screen");

        cout << "\nPlease enter Currency1 code (Exchange from): ";
        string CurrencyCode1 = clsInputValidate::ReadString();
        clsCurrency ExchangeFromCurrency = clsCurrency::FindByCode(CurrencyCode1);

        cout << "\nPlease enter Currency2 code: (Exchange to): ";
        string CurrencyCode2 = clsInputValidate::ReadString();
        clsCurrency ExchangeToCurrency = clsCurrency::FindByCode(CurrencyCode2);



        cout << "\nEnter amount to exchange: ";
        double ExchangeAmount = clsInputValidate::ReadDoubleNumber();

        if (CurrencyCode2 == "USD" || CurrencyCode2 == "usd")
        {
          _PrintCurrency(ExchangeFromCurrency);

          cout << ExchangeAmount << " " << ExchangeFromCurrency.Code << " = " << ExchangeFromCurrency.ConvertToUSD(ExchangeAmount) << " " << ExchangeToCurrency.Code;
        }
        


    }
};

