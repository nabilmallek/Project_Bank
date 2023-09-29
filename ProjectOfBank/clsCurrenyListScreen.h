#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include "clsCurrency.h"
#include <iomanip>
using namespace std;








class clsCurrenyListScreen :protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Record)
	{
		cout << setw(25) << left << "" << "|" << left << setw(35) << Record.Country();
		cout << "|" << left << setw(15) << Record.CurrencyCode();
		cout << "|" << left << setw(30) << Record.CurrencyName();
		cout << "|" << left << setw(12) << Record.Rate();
	}


public:

	static void ShowCurrenciesListScreen()
	{
		
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		string Title = "Currencies List Screen";
		string   SubTitle = "\t (" + to_string(vCurrency.size()) + ") Client(s)";
		_DrawScreenHeader(Title,SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________________________\n\n";
		cout << setw(25) << left << "" << "|" << left << setw(35) << "Country ";
		cout << "|" << left << setw(15) << "Currency Code";
		cout << "|" << left << setw(30) << "Currency Name";
		cout << "|" << left << setw(12) << "Rate / 1 $";
		cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________________________\n";

		if (vCurrency.size() == 0)
		{
			cout << "Currencires List Not Found";
		}

		for (clsCurrency& Record : vCurrency)
		{
			_PrintCurrencyRecord(Record);
			cout << endl ;
		}
	}


};

