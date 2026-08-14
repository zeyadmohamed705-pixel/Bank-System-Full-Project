#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString1.h"


class clsBankClient : public clsPerson
{
private:
	enum enMode {EmptyMode = 0, UpdateMode =1, AddNewMode=3 };
	enMode _Mode; 

	string _AccountNumber, _PinCode;
	double _AccountBalance; 
    bool _MarkedForDelete = false;


    static clsBankClient _ConvertLineToClientObject(string Line, string Seprator = "#//#")
    {
        vector <string> vClientsData;
        vClientsData = clsString::Split(Line, Seprator);

        return clsBankClient (enMode::UpdateMode, vClientsData[0], vClientsData[1], vClientsData[2], vClientsData[3], vClientsData[4], vClientsData[5], stod (vClientsData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
       // vClients = 
        stClientRecord = Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;


    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }



    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);
        if (MyFile.is_open())
        {
            string DataLine;
            for (clsBankClient& C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
        }
        MyFile.close();

    }
    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient & C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this; // pointer this has the updated info (in the run memory)
                // here we update the element obj in the vector with the updated object
                break;
            }
        }
        _SaveClientDataToFile(_vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }
    void _AddDataLineToFile(string DataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

string _PrepareTransferLogRecord(float Amount,clsBankClient DestinationClient, string Username, string Seperator = "#//#")
    {
        string TransferLog = "";
        TransferLog = clsDate::GetSystemDateTimeString() + Seperator;
        TransferLog += _AccountNumber + Seperator;
        TransferLog += DestinationClient.AccountNumber() + Seperator;
        TransferLog += to_string (Amount) + Seperator;
        TransferLog += to_string(_AccountBalance) + Seperator;
        TransferLog += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLog += Username;

        return TransferLog;
    }
struct stTransferLog;
static stTransferLog  _ConvertLineToTransferRecord(string Line, string Seprator = "#//#")
{
    vector <string > vTransferRecord = clsString::Split(Line, Seprator);

    stTransferLog TransferRecord;
    TransferRecord.SystemDateTime = vTransferRecord[0];
    TransferRecord.SourceAccNum = vTransferRecord[1];
    TransferRecord.DestinationAccNum = vTransferRecord[2];
    TransferRecord.Amount = stof(vTransferRecord[3]);
    TransferRecord.S_Balance = stof(vTransferRecord[4]);
    TransferRecord.D_Balance = stof(vTransferRecord[5]);
    TransferRecord.Username = vTransferRecord[6];

    return TransferRecord;
}
public :
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
		: clsPerson ( FirstName,  LastName,  Email,  Phone)
	{
        _Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

	string AccountNumber()
	{
		return _AccountNumber;
	}


    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(double AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    double GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }
    // No UI Related code iside object.
    /*
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/

    static clsBankClient FindAccountNumber (string AccountNumber)
    {
        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
        }
        return _GetEmptyClientObject();


    }


    static clsBankClient FindAccountNumber(string AccountNumber, string PinCode) // find client by matching AccountNum and PinCode 
    {
        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = Client1.FindAccountNumber(AccountNumber);
        return (!Client1.IsEmpty());
    }

    enum enSaveResults {svFailedEmptyObject =1, svSucceeded =2,svFailedAccountNumberexists =3};
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;
            break;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
            break;

        case enMode::AddNewMode:
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberexists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();


        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveClientDataToFile(vClients);
        *this = _GetEmptyClientObject(); // to delete the current object data from the memory too

        return true;
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }
    static  double GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();
        double TotalBalance = 0;
        for (clsBankClient& C : vClients)
        {
            TotalBalance += C.AccountBalance;
        }
        return TotalBalance;
    }

     void Deposite(double Amount)
    {
         _AccountBalance += Amount;
         Save();
    }
     bool WithDraw(double Amount)
     {
         if (_AccountBalance < Amount)
         {
             return false;
         }
         else 
         {
             _AccountBalance -= Amount;
             Save();
             return true;
         }
     }

     bool Transfer(float Amount, clsBankClient& DestinationClient, string Username)
     {
         if (Amount > AccountBalance)
         {
             return false;
         }
         WithDraw(Amount);
         DestinationClient.Deposite(Amount);
         RegisterTransferLog(Amount, DestinationClient, Username);
         return true;
     }

     //struct stTransferLog
     //{
     //    string TimeDate, AccountNum, DestinationClientAccountNum, Username;
     //    double TransferredAmount, BalanceAfterTransfer, DestinationClientBalanceAfterTransfer;
     //};

     void RegisterTransferLog(float  Amount, clsBankClient  DestinationClient, string Username)
     {
         string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, Username);
         fstream MyFile;
         MyFile.open("TransferLog", ios::out | ios::app);
         if (MyFile.is_open())
         {
             MyFile << stDataLine << endl;
         }
         MyFile.close();
     }

     struct stTransferLog 
     { 
        string SystemDateTime, SourceAccNum, DestinationAccNum, Username;
        float Amount, S_Balance, D_Balance;
     };

    static vector <stTransferLog> GetTransferLogList()
     {
         vector <stTransferLog> vTransferLogRecords;
         stTransferLog TransferLogRecord;

         fstream MyFile;
         MyFile.open("TransferLog", ios::in);
         string Line;
         if (MyFile.is_open())
         {
             while (getline(MyFile, Line))
             {
                  TransferLogRecord = _ConvertLineToTransferRecord(Line);
                  vTransferLogRecords.push_back(TransferLogRecord);
             }
         }
         MyFile.close();
         return vTransferLogRecords;
     }
};

