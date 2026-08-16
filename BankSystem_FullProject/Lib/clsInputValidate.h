
#pragma once
#include <iostream>
#include <string>
#include "clsString1.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{

public:

	template <typename T>
	static bool IsNumberBetween(T Num, T From, T To)
	{
		return (Num >= From) && (Num <= To);
	}

	// Dates 
	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
	{
		return clsDate::IsDateBetween(Date, Date1, Date2);
	}



	template <typename T>
	static T ReadNumber(string ErrorMsg = "Invalid Num, Enter again\n")
	{
		T Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg;
		}
		return Num;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Num = ReadNumber<T>();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadNumber<T>();
		}

		return Num;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);

	}

	static string ReadString()
	{
		string S1 = "";
		// remember: Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};







/*

#pragma once
#include <iostream>
#include <string>
#include "clsString1.h"
#include "clsDate.h"


class clsInputValidate
{

public:
	static bool IsNumberBetween(short Num, short From, short To)
	{
		return (Num >= From) && (Num <= To);
	}
	static bool IsNumberBetween(int Num, int From, int To)
	{
		return (Num >= From) && (Num <= To);
	}

	static bool IsNumberBetween(float Num, float From, float To)
	{
		return (Num >= From) && (Num <= To);
	}

	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From) && (Num <= To);
	}

	// Dates 
	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
	{
		return clsDate::IsDateBetween(Date, Date1, Date2);
	}



	static int ReadIntNumber(string ErorrMsg = "Invalid Num, Enter again\n")
	{
		int Num = 0;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErorrMsg;
			cin >> Num;

		}
		return Num;
	}

	static float ReadFloatNumber(string ErorrMsg = "Invalid Num, Enter again\n")
	{
		float Num = 0;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErorrMsg;
			cin >> Num;

		}
		return Num;
	}

	static double ReadDoubleNumber(string ErorrMsg = "Invalid Num, Enter again")
	{
		double Num = 0;

		while (!(cin >> Num))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErorrMsg;
			cin >> Num;

		}
		return Num;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Num = ReadIntNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadIntNumber();
		}

		return Num;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Num = ReadIntNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadIntNumber();
		}

		return Num;
	}

	static float ReadFloatNumberBetween(float From, float To, string Msg)
	{
		float Num;
		do
		{
			cout << Msg;
			cin >> Num;
		} while (!IsNumberBetween(Num, From, To));
		return Num;
	}

	static double ReadDoubleNumberBetween(double From, double To, string Msg)
	{
		double Num;
		do
		{
			cout << Msg;
			cin >> Num;
		} while (!IsNumberBetween(Num, From, To));
		return Num;
	}
	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);

	}
	
	static string ReadString()
	{
		string S1 = "";
		// remember: Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};

*/


