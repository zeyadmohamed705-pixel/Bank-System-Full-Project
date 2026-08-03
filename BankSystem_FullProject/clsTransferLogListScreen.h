#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include <string>
#include <vector>
#include "clsString1.h"
#include "clsDate.h"
#include "Global.h"

class clsTransferLogListScreen : protected clsScreen
{
	static void _PrintTransferLogRecord(clsBankClient::stTransferLog TransferRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << TransferRecord.SystemDateTime;
		cout << left  << "| " << setw(6) << left << TransferRecord.SourceAccNum;
		cout << left  << "| " << setw(6) << left << TransferRecord.DestinationAccNum;
		cout << left  << "| " << setw(16) << left << TransferRecord.Amount;
		cout << left  << "| " << setw(15) << left << TransferRecord.S_Balance;
		cout << left  << "| " << setw(15) << left << TransferRecord.D_Balance;
		cout << left  << "| " << setw(10) << left << TransferRecord.Username;



	}

public:





	static void ShowTransferLogListScreen()
	{

		vector <clsBankClient::stTransferLog> vTransferLogRecords= clsBankClient::GetTransferLogList();
		string Subtitle = "\t\t(" + to_string(vTransferLogRecords.size()) + ") Record(s)";

		_DrawScreenHeader("Login Register List Screen", Subtitle);
		cout << endl << setw(8) << left << "" << "---------------------------------------------------------------------------------------------------------\n";
		cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time";
		cout << "| " << setw(6) << left << "s.Acc" << "| " << setw(6) << left << "d.Acc" ;
		cout << "| "<< setw(16) << left << "Transferd Amount" << "| " << setw(15) << left << "s.Balance" << "| " << setw(15) << left << "d.Balance";
		cout << "| " << setw(10) << left << "Username";

		cout << endl << setw(8) << left << "" << "---------------------------------------------------------------------------------------------------------\n";

		if (vTransferLogRecords.size() == 0)
		{
			cout << "\n \t\t\t\t\t No Registerd Records Available in the system";
		}

		else
		{
			for (clsBankClient::stTransferLog& TransferRecord : vTransferLogRecords)
			{
				_PrintTransferLogRecord(TransferRecord);
				cout << endl;
			}

		}
		cout << endl << setw(8) << left << "" << "---------------------------------------------------------------------------------------------------------\n";

	}
};

