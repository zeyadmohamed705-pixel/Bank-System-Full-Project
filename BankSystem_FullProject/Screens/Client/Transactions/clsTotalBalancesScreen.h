#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;


	}
public:
	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "Total Balances Screen";
		string SubTitle = "\t\t\t (" + to_string( vClients.size()) + ") Client(s)";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(40) << left << "Client Name";
		cout << "| " << setw(12) << left << "Balance";

		cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________\n" << endl;
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else 
		{
			for (clsBankClient& Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		}

		cout << setw(25) << left << "" << "\t\t_________________________________________________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";

	}
};

