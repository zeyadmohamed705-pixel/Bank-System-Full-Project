#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h"
#include <string>
class clsUpdateUserScreen : protected clsScreen
{
private:
	static void _ReadNewUserInfo(clsUser& NewUser)
	{
		cout << "\nEnter First Name:";
		NewUser.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name:";
		NewUser.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email:";
		NewUser.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone:";
		NewUser.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password:";
		NewUser.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permessions:";
		NewUser.Permissions = _ReadPermessions();

	};
	static short _ReadPermessions()
	{
		char Answer = 'n';
		short Permessions = 0;
		cout << "\ndo you want to give full access? :";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			return -1;

		else
		{
			cout << "\nDo you want to give access to : \n ";

			cout << "\nShow Clients List Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pListClients;

			cout << "\nAdd New Client Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pAddNewClient;

			cout << "\nDelete Clients Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pDeleteClient;

			cout << "\nUpdate Clients Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pUpdateClient;

			cout << "\Find Client Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pFindClient;

			cout << "\nTransactions Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pTransactions;

			cout << "\nManage Users Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pManageUsers;

			return Permessions;
		}
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}
public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		cout << "\n Please enter a user name: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		
		_PrintUser(User);

		cout << "\nAre you sure you want to update this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			_ReadNewUserInfo(User);

			clsUser::enSaveResult Save = User.Save();

			switch (Save)
			{
			case clsUser::enSaveResult::svSucceeded:
			{
				cout << "\n User updated successfully ";
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResult::svFailedEmptyObject:
			{
				cout << "\n Error User was not saved because it's Empty";
				break;
			}

			}


		}
	}
};

