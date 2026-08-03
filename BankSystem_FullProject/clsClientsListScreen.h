#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include <string>
#include <vector>


using namespace std;
class clsClientsListScreen :protected clsScreen
{
private:
    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << "" << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout  << "| " << left << setw(12) << Client.GetPhone();
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout  << "| " << left << setw(12) << Client.AccountBalance;
    }
public:
	static void ShowClientsList()
	{
        if (!CheckAccessRights(clsUser::enPermessions::pListClients))
        {
            return; // this will exit the function and it will not continue
        }
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "Client List Screen";
        string SubTitle = "\t\t" + to_string(vClients.size()) + " Client(s)";
        
        _DrawScreenHeader(Title, SubTitle);
        cout  << "\n" << setw(8) << ""<<"------------------------------------------------------------------------------------------------------------\n";
        cout  << setw(8) << "" << "| " << left << setw(15) << "Account Number";
        cout  << "| " << left << setw(20) << "Full Name";
        cout  << "| " << left << setw(12) << "Phone";
        cout  << "| " << left << setw(20) << "Email";
        cout  << "| " << left << setw(10) << "PinCode";
        cout  << "| " << left << setw(12) << "Account Balance";

        cout << "\n" << setw(8) << "" << "------------------------------------------------------------------------------------------------------------\n";

        if (vClients.size() == 0)
        {
            cout << "\n \t\t\t\t\t No Clients Available in the system";
        }

        else
        {
            for (clsBankClient& C : vClients)
            {
                PrintClientRecordLine(C);
                cout << endl;
            }
            cout<< endl << setw(8) << "" << " ------------------------------------------------------------------------------------------------------------\n";

        }
	}


};

