#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"
#include <string>
#include <vector>
#include "clsString1.h"
#include "clsDate.h"
#include "Global.h"


class clsLoginRegisterListScreen : protected clsScreen
{


	static void PrintLoginRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.DateTime;
		cout << left << "" << "| " << setw(15) << left << LoginRegisterRecord.Username;
		cout << left << "" << "| " << setw(15) << left << LoginRegisterRecord.Password;
		cout << left << "" << "| " << setw(15) << left << LoginRegisterRecord.Permessions;

	}

public:





	static void ShowLoginRegisterlistScreen()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pLoginRegisterList))
		{
			return;
		}
		vector <clsUser::stLoginRegisterRecord> vLoginsRegisterRecords = clsUser::GetLoginRegisterList();
		string Subtitle = "\t\t(" + to_string(vLoginsRegisterRecords.size()) + ") Record(s)";

		_DrawScreenHeader("Login Register List Screen", Subtitle);
		cout << endl << setw(8) << left << "" << "---------------------------------------------------------------------------------------------\n";
		cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time" << "| " << setw(15) << left << "Username";
		cout << "| " << setw(15) << left << "Password" << "| " << setw(15) << left << "Permessions";
		cout << endl << setw(8) << left << "" << "---------------------------------------------------------------------------------------------\n";

		if (vLoginsRegisterRecords.size() == 0)
		{
			cout << "\n \t\t\t\t\t No Registerd Records Available in the system";
		}

		else 
		{
			for (clsUser::stLoginRegisterRecord& LoginRecord : vLoginsRegisterRecords)
			{
				PrintLoginRecord(LoginRecord);
				cout << endl;
			}

		}
		cout << endl << setw(8) << left << "" << "---------------------------------------------------------------------------------------------\n";

	}
};

