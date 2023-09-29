#pragma once
#include <iostream>
#include "clsString.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;






class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;


	static clsCurrency  _ConvertLineToCurrencyObject(string  Line,string Seperator ="#//#")
	{
		

		vector <string> vCurrency = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

 static 	vector <clsCurrency> _LoadCurrencyDataFromFile()
 {
		vector <clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrency;
 }

	string   _ConvertCurrencyObjectToLine(clsCurrency Currency , string Seperator ="#//#")
	{
		string CurrencyData = "";

		CurrencyData += Currency.Country() + Seperator;
		CurrencyData += Currency.CurrencyCode() + Seperator;
		CurrencyData += Currency.CurrencyName() + Seperator;
		CurrencyData += to_string(Currency.Rate());

		return CurrencyData;
	}
	
	void _SaveCurrencyDataToFile(vector <clsCurrency>  _vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrency& C : _vCurrency)
			{
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}
	
	void _Update()
	{
		vector <clsCurrency> _vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency &C : _vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrency);
	}
public:

	clsCurrency(enMode Mode, string Country , string CurrencyCode,string CurrencyName,float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

    static 	clsCurrency  FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static 	clsCurrency  FindByCountry(string Country)
	{
		Country = clsString::UpperFirstLetterOfEachWord(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.Country() == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency  Currency = clsCurrency::FindByCode(CurrencyCode);
		

		return (!Currency.IsEmpty());

	}

	

	static  vector <clsCurrency>  GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUsd(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount ,clsCurrency CurrencyTo)
	{
		float AmountInUsd = ConvertToUsd(Amount);

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return AmountInUsd;
		}

		return (float)(AmountInUsd * CurrencyTo.Rate());
	}
};

