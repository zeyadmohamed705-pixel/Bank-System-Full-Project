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
class clsCurrency 
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2 };
	enMode _Mode;
	string _Country, _Code, _CurrencyName;
	float _Rate;
	bool _MarkedForDelete = false;



	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencyData = clsString::Split(Line, Seperator);
		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Sepretor = "#//#")
	{
		string CurrencyStringLine = "";
		CurrencyStringLine += Currency._Country + Sepretor;
		CurrencyStringLine += Currency._Code + Sepretor;
		CurrencyStringLine += Currency._CurrencyName + Sepretor;
		CurrencyStringLine += to_string(Currency._Rate) ;

		return CurrencyStringLine;

	}
	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector <clsCurrency> vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencies;

	}
	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}

	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertCurrencyObjectToLine(*this));
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencies)
	{
		string DataLine = "";
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency& Currency : vCurrencies)
			{
				if (Currency._MarkedForDelete == false) // remember here only the objects inside the vector which not marked for delete will be written
				{
					DataLine = _ConvertCurrencyObjectToLine(Currency);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.Name == _CurrencyName)
			{
				Currency = *this; // pointer this has the updated info (in the run memory)
				// here we update the element obj in the vector with the updated object
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}






public:

	clsCurrency(enMode Mode,string Country, string Code, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Code = Code;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetName()
	{
		return _CurrencyName;
	}
	void SetName(string Name)
	{
		_CurrencyName = Name;
	}

	__declspec (property (get = GetName, put = SetName)) string Name;





	float GetCurrencyRate() 
	{
		return _Rate;
	}
	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}

	__declspec (property (get = GetCurrencyRate, put = SetCurrencyRate)) float Rate;



	string GetCountry()
	{
		return _Country;
	}
	void SetCountry(string Country)
	{
		_Country = Country;
	}

	__declspec (property (get = GetCountry, put = SetCountry)) string Country;


	string GetCode()
	{
		return _Code;
	}
	void SetCode(string Code)
	{
		_Code = Code;
	}

	__declspec (property (get = GetCode, put = SetCode)) string Code;

	static clsCurrency GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}



	static clsCurrency FindByCountry(string CountryName)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.Country == CountryName)
				{
					MyFile.close();
					return Currency;

				}

			}
			// incase the Currency Is Not Found 
			MyFile.close();

		}
		return GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCode(string Code)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.Code == Code)
				{
					MyFile.close();
					return Currency;

				}

			}
			// incase the Currency Is Not Found 
			MyFile.close();

		}
		return GetEmptyCurrencyObject();
	}

	static clsCurrency Find(string CodeOrCountry )
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.Code == CodeOrCountry || Currency.Country == CodeOrCountry)
				{
					MyFile.close();
					return Currency;

				}

			}
			// incase the Currency Is Not Found 
			MyFile.close();

		}
		return GetEmptyCurrencyObject();
	}


	
	static bool IsCurrencyExist(string CurrencyName)
	{
		clsCurrency Currency = Find(CurrencyName);
		return (!Currency.IsEmpty());
	}


	bool Delete()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.Name == _CurrencyName)
			{
				Currency._MarkedForDelete = true;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
		*this = GetEmptyCurrencyObject(); // to delete the actual data of the deleted user from the memory, because the Currency card will be printed with deleted user data 
		return true;
	}

	/*
	enum enSaveResult { svFailedEmptyObject = 1, svSucceeded = 2 };
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::svFailedEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
		}
		
		default:
			break;

		}
	};*/




	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUSD( float Amount)
	{
		return (float)(Amount / Rate);
	
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency DestinationCurrency)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (DestinationCurrency.Code == "USD" || DestinationCurrency.Code == "usd")
		{
			return AmountInUSD;
		}

		return (float) (AmountInUSD * DestinationCurrency.Rate);

	}




};

