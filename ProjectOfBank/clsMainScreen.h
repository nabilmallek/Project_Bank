#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManagerUsersScreen.h"
#include <iomanip>
#include"Global.h"
#include"clsUser.h"
#include"clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
using namespace std;







class clsMainScreen :protected clsScreen
{
private:
	
	enum  enMainMenuOptions {eListClients = 1 , eAddNewClient = 2 , eDeleteClient = 3 , eUpdateClient = 4 , eFindClient = 5,
	eShowTransctionsMenu = 6 , eManagerUsers = 7 ,eLoginRegister = 8, eCurrencyExchange = 9 ,eExit = 10};
	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do  you want to do [ 1 to 10] : ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter number between 1 and 10 : ");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to main menu ...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManagerUsersMenu()
	{
		clsManagerUsersScreen::ShowManagerUsersMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegister();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		}
		case enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowTransctionsMenu:
		{
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eManagerUsers:
		{
			system("cls");
			_ShowManagerUsersMenu();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eExit:
		{
			system("cls");
			_Logout();
			
			break;
		}

		}
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << setw(37) << left << "" << "==========================================================\n";
		cout << setw(37) <<left << "" << "\t\t\t\tMain Menu\n";
		cout << setw(37) <<left<< "" << "==========================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manager Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] LogOut.\n";
		cout << setw(37) << left << "" << "==========================================================\n";
		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}


};

