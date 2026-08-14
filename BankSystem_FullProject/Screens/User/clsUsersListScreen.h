#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"
#include <string>
#include <vector>
class clsUsersListScreen : protected clsScreen
{
private:
    static void PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << "" << "| " << left << setw(15) << User.UserName;
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(10) << User.Password;
        cout << "| " << left << setw(12) << User.Permissions;
    }
public:
    static void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "Users List Screen";
        string SubTitle = "\t\t" + to_string(vUsers.size()) + " User(s)";
      //  string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << "\n" << setw(8) << "" << "------------------------------------------------------------------------------------------------------------\n";
        cout << setw(8) << "" << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permessions";

        cout << "\n" << setw(8) << "" << "------------------------------------------------------------------------------------------------------------\n";

        if (vUsers.size() == 0)
        {
            cout << "\n \t\t\t\t\t No Users Available in the system";
        }

        else
        {
            for (clsUser& C : vUsers)
            {
                PrintUserRecordLine(C);
                cout << endl;
            }
            cout << endl << setw(8) << "" << " ------------------------------------------------------------------------------------------------------------\n";

        }
    }

};

