#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculator.h"
using namespace std;









class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeOptions {eCurrenciesList = 1 , eFindCurrency = 2 , eUpdateRate = 3 , eCurrencyCalculator = 4 ,
	eMainMenu = 5};

	static short _ReadCurrencyMenuOptions()
	{
		cout << setw(37) << left << "" << "Choose what do  you want to do [ 1 to 5] : ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter number between 1 and 5 : ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "\nPress any key to go back to Currency Exchange  menu ...";

		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenyListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}
	
  static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeOptions   ReadCurrencyMenuOptions)
  {
		switch (ReadCurrencyMenuOptions)
		{
		case enCurrencyExchangeOptions::eCurrenciesList:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptions::eMainMenu:
		{

		}
	    
		}
  }
public:


	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		
		_DrawScreenHeader("Currency Exchange Main  Screen ");

		cout << setw(37) << left << "" << "==================================================================\n";
		cout << setw(37) << left << "" << "\t\t\t Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "==================================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		
		cout << setw(37) << left << "" << "==================================================================\n";
		_PerformCurrencyExchangeMenuOption((enCurrencyExchangeOptions)_ReadCurrencyMenuOptions());


	}

};

