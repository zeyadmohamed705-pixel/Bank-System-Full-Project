#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>

#include <fstream>
#include "clsPerson.h"
#include "clsString1.h"
#include "clsUtil.h"

#include "clsDate.h"

using namespace std;
class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };
	enMode _Mode;
	string _UserName, _Password;
	int _Permissions;
	bool _MarkedForDelete = false;


	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUsersData = clsString::Split(Line, Seperator); 
		return clsUser(enMode::UpdateMode, vUsersData[0], vUsersData[1], vUsersData[2], vUsersData[3], vUsersData[4], clsUtil::DecryptText(vUsersData[5]),stoi(vUsersData[6]) );
	}
	static string _ConvertUserObjectToLine(clsUser User, string Sepretor = "#//#")
	{
		string UserStringLine = "";
		UserStringLine += User.FirstName + Sepretor;
		UserStringLine += User.LastName + Sepretor;
		UserStringLine += User.Email + Sepretor;
		UserStringLine += User.Phone + Sepretor;
		UserStringLine += User.UserName + Sepretor;
		UserStringLine += clsUtil::EncryptText(User.Password) + Sepretor;
		UserStringLine += to_string(User.Permissions);

		return UserStringLine;

	}
	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if(MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;

	}
	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}

	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		string DataLine = "";
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsUser& User : vUsers)
			{
				if (User._MarkedForDelete == false) // remember here only the objects inside the vector which not marked for delete will be written
				{
					DataLine = _ConvertUserObjectToLine(User);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser & User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User = *this; // pointer this has the updated info (in the run memory)
                // here we update the element obj in the vector with the updated object
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareLoginRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord = clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line, string Seprator = "#//#")
	{
		vector <string> vLoginRegisterDataLine = clsString::Split(Line, Seprator);
		stLoginRegisterRecord LoginRegisterRecord;
		LoginRegisterRecord.DateTime = vLoginRegisterDataLine[0];
		LoginRegisterRecord.Username = vLoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegisterDataLine[2]);
		LoginRegisterRecord.Permessions = stoi(vLoginRegisterDataLine[3]);

		return LoginRegisterRecord;
	}

public:

	enum enPermessions {pAll = -1, pListClients = 1, pAddNewClient= 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegisterList = 128, pCurrencyExchangeMainScreen = 256};
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permessions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permessions;
	};
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec (property (get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	__declspec (property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermissions()
	{
		return _Permissions;
	}
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;



	static clsUser Find (string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;

				}

			}
			// incase the User Is Not Found 
			MyFile.close();

		}
			return _GetEmptyUserObject();
	}


	static clsUser Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;

				}

			}
			// incase the User Is Not Found 
			MyFile.close();


		}
			return _GetEmptyUserObject();
	}
	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}
	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject(); // to delete the actual data of the deleted user from the memory, because the User card will be printed with deleted user data 
		return true;
	}
	enum enSaveResult {svFailedEmptyObject = 1, svSucceeded = 2, svFailedUserAlreadyExists = 3};
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::svFailedEmptyObject;
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFailedUserAlreadyExists;
				break;

			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
				break;

			}
		}

		}
	}


	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	// no need to be static because it will be called on the object level 
	bool CheckAccessPermessions(enPermessions ScreenPermession) 
	{
		if (this->Permissions == enPermessions::pAll) // comparing permession of the object 'this->Permissions = _Permissions' with screen permession 
			return true;
		if ((this->Permissions & ScreenPermession) == ScreenPermession)
			return true;
		else
			return false;
	}





	 void RegisterLogin()
	 {
		 fstream MyFile;
		 clsDate Date;
		 string LoginRecord = _PrepareLoginRecord();
		 MyFile.open("LoginRegister", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << LoginRecord << endl;
		 }
		 MyFile.close();
	 }
	 struct stLoginRegisterRecord
	 {
		 string DateTime, Username, Password;
		 int Permessions;
	 };
	 static vector <stLoginRegisterRecord> GetLoginRegisterList()
	 {
		 vector <stLoginRegisterRecord> vLoginRegisterRecord;
		 fstream MyFile;
		 MyFile.open("LoginRegister", ios::in);

		 if (MyFile.is_open())
		 {
			 stLoginRegisterRecord LoginRegisterRecord;
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 LoginRegisterRecord = _ConvertLineToLoginRegisterRecord(Line);
				 vLoginRegisterRecord.push_back(LoginRegisterRecord);
			 };
			 MyFile.close();
		 }
		 return vLoginRegisterRecord;
	 }
};

