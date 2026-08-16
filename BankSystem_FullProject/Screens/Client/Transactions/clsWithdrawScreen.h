#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsWithdrawScreen : clsScreen
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
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("WithDraw Screen");
		cout << "Please enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount with [" << AccountNumber << "] is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::FindAccountNumber(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter Withdraw Amount: ";

		double Amount = clsInputValidate::ReadNumber<double>("Invalid Input, please enter a valid Amount");
		cout << "\nAre you sure you want to perform this Transaction? Y/N";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.WithDraw(Amount))
			{
				cout << "Amount is withdrew successfully, New Balance is " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot witdrew insuffecient balance! ";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nyour Balance is: " << Client.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation has been cancelled";

		}



	}


};


