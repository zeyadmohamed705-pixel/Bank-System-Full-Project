#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsTransferScreen : protected clsScreen
{

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n Client Card: \n";
		cout << "-------------------------------\n " ;
		cout << "\nFull Name: " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nAcc. Balance : " << Client.AccountBalance;
		cout << "\n-------------------------------\n ";


	}


	static string _ReadAccountNum()
	{
		string AccountNum = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNum))
		{
			cout << "\nAccount Number Is not existing, Choose another one: ";
			AccountNum = clsInputValidate::ReadString();
		}
		return AccountNum;

	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount? ";
		double Amount = clsInputValidate::ReadDoubleNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDoubleNumber();
		}
		return Amount;
	}
public:
	static void ShowTransferScreen()
	{

		_DrawScreenHeader("Transfer Screen");

		cout << "\nPlease Enter Account Number to transfer from: ";
		clsBankClient SourceClient = clsBankClient::FindAccountNumber(_ReadAccountNum());

		_PrintClientCard(SourceClient);


		cout << "\nPlease Enter Account Number to transfer to: ";
	
		clsBankClient DestinationClient = clsBankClient::FindAccountNumber(_ReadAccountNum());

		_PrintClientCard(DestinationClient);

		double TransferAmount = _ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(TransferAmount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully ";
				//SourceClient.TransferLog(DestinationClient.AccountNumber(), TransferAmount, DestinationClient.AccountBalance);
			}
			else
			{
				cout << "\nTransfer done successfully ";
			}
		}

	
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

	}
};


