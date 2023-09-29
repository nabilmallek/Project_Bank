#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"

using namespace std;








class clsCurrencyCalculator : protected clsScreen
{
private :

	static float _ReadAmount()
	{
		float Amount;
		cout << "\n Enter Amount to exchange : ";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency,string Message)
	{

		cout << Message << endl;
		cout << "-----------------------------------------\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.CurrencyCode() << endl;
		cout << "Name      : " << Currency.CurrencyName() << endl;
		cout << "Rate / 1$ : " << Currency.Rate() << endl;
		cout << "--------------------------------------------\n\n";
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency you entred is not found,enter another one : ";
			CurrencyCode = clsInputValidate::ReadString();
			

		}

		clsCurrency  Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "\nConvert From : ");
		float AmountInUsd = CurrencyFrom.ConvertToUsd(Amount);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUsd << " USD ";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		_PrintCurrencyCard(CurrencyTo, "\nConvert To : ");
		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode();
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';
		
		do
		{
		   system("cls");
		
		  _DrawScreenHeader("Currency Calculator Screen");

		  clsCurrency  CurrencyFrom = _GetCurrency("\nPlease enter CurrencyCode1 : ");
		  clsCurrency CurrencyTo = _GetCurrency("\nPlease enter CurrencyCode2 : ");
		   
		   float  Amount = _ReadAmount();

		    _PrintCalculationsResults(Amount , CurrencyFrom,CurrencyTo);
		
			
			cout << "\n Do you want to perform another calculation y/n : ";
			cin >> Answer;

		} while (Answer == 'y' || Answer == 'Y');
		
	}

};

