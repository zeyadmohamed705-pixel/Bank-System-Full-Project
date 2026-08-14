#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"

#include <string>
#include <vector>
class clsDeleteClientScreen : protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermessions::pDeleteClient))
        {
            return; // this will exit the function and it will not continue
        }
        _DrawScreenHeader("Delete Client Screen");
        string AccountNumber;
        cout << "Please enter the Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account number is not found choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::FindAccountNumber(AccountNumber);
        _PrintClient(Client);
        cout << "\nAre you sure that you want to delete this Client: Y/N";
        char Answer = 'N';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Delete())
            {
                cout << "Client has been deleted successfully";
                _PrintClient(Client);
            }
            else
            {
                cout << "Client was not deleted ";
            }

        }


    

	}
};

