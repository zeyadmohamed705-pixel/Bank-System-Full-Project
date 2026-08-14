#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h"
#include <string>
class clsAddNewUser : protected clsScreen
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

			cout << "\nShow Login Register List Y/N : ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permessions += clsUser::enPermessions::pLoginRegisterList;

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
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		cout << "\n Please enter a user name: ";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		// putting the user in the add mode 
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadNewUserInfo(NewUser);

		clsUser::enSaveResult Save = NewUser.Save();

		switch (Save)
		{
		case clsUser::enSaveResult::svSucceeded:
		{
			cout << "\n save succedeed ";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResult::svFailedEmptyObject:
		{
			cout << "\n Error User was not saved because it's Empty";
			break;
		}
		case clsUser::enSaveResult::svFailedUserAlreadyExists:
		{
			cout << "\n failed to save the User entered is already existing ";
			break;
		}

		}
	}
};

