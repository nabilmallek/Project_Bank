#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"
using namespace std;












class clsFindCurrencyScreen :protected clsScreen
{
private:



	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "Currency Found :-)\n";
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
			cout << "\n Currency is found -)\n";
			_PrintCurrencyCard(Currency);

		}
		else
		{
			cout << "\n Currency is not found .\n";
		}


	}


public:


	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "\nFind By : Code [1] Or Country [2] : ";
		short Answer = 1;

		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\n Please enter the Code of Currency : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowReasult(Currency);

		}
		else
		{
			string Country;
			cout << "\n Please enter the name of Country : ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowReasult(Currency);


		}
	}

};