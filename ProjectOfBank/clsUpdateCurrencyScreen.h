#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsUtil.h"
using namespace std;







class clsUpdateCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		
		cout << "\nCurrency Card :\n";
		cout << "-----------------------------------------\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.CurrencyCode() << endl;
		cout << "Name      : " << Currency.CurrencyName() << endl;
		cout << "Rate / 1$ : " << Currency.Rate() << endl;
		cout << "--------------------------------------------\n";
	}

	static void _ShowReasult(clsCurrency    Currency)
	{
		if (!Currency.IsEmpty())
		{
			
			_PrintCurrencyCard(Currency);

		}
		else
		{
			cout << "\n Currency is not found .\n";
		}


	}


public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode;
		cout << "\nPlease enter Currency Code : ";
		CurrencyCode = clsInputValidate::ReadString();
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		clsCurrency  Currency = clsCurrency::FindByCode(CurrencyCode);
		_ShowReasult(Currency);

		char Answer = 'n';
		cout << "\n Are you sur you want to update the Rate of Currency : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n Update Currency Rate : \n";
			cout << "----------------------------\n";
			float NewRate;
			cout << "Enter New Rate : ";
			NewRate = clsInputValidate::ReadFloatNumber();
		 Currency.UpdateRate(NewRate);
		 cout << "\nCurrency Rate Updated Successfully -).\n";
		 _ShowReasult(Currency);


		}
	}






};

