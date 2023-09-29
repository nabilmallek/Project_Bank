#pragma once
#include <iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include<iomanip>
#include "clsTransferLogScreen.h"
using namespace std;






class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsMenuOptions {eDeposit = 1 , eWithdraw = 2 , eShowTotalBalances = 3 ,eTransfer = 4 ,eShowTransferLog = 5  ,eShowMainMenu = 6};
	
	static short _ReadTransactionsMenuOptions()
	{
		cout << setw(37) << left << "" << "Choose what do  you want to do [ 1 to 6] : ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter number between 1 and 6 : ");
		return Choice;
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << "\nPress any key to go back to transaction menu ...";

		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWitdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTrasferLogScreen();
	}
	
	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOptions)
	{
		switch (TransactionsMenuOptions)
		{
		case enTransactionsMenuOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eWithdraw:
		{
			system("cls");
			_ShowWitdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case  enTransactionsMenuOptions::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;

		}
		case  enTransactionsMenuOptions::eShowMainMenu:
		{

		}
		
		}
	}
public:

	static void ShowTransactionsMenu()
	{
		

		if (!CheckAccessRigth(clsUser::enPermissions::pTransactions))
		{
			return;
		}
		
		system("cls");
		
		_DrawScreenHeader("Transactions Screen");
		cout << setw(37) << left << "" << "==================================================================\n";
		cout << setw(37) << left << "" << "\t\t\t Transactions Menu\n";
		cout << setw(37) << left << "" << "==================================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================================================\n";
		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOptions());
	}


};

