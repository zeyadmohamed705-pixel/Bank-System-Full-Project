#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsDeposieScreen : clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("Deposite Screen");
		cout << "Please enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount with [" << AccountNumber << "] is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::FindAccountNumber(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter deposite Amount: ";

		double Amount = clsInputValidate::ReadNumber<double>("Invalid Input, please enter a valid Amount");
		cout << "\nAre you sure you want to perform this Transaction? Y/N";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposite(Amount);
			cout << "\nAmount deposited successfully";
			cout << "\nNew Balance is: " << Client.AccountBalance;
		}
		else
		{
			cout << "\nOperation has been cancelled";

		}


	}


};

