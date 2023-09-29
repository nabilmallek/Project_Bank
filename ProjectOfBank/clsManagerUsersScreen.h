#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;






class clsManagerUsersScreen: protected clsScreen
{
private :

	enum enManagerUsersMenuOptions {eListUsers = 1 , eAddNewUser = 2 , eDeleteUser = 3 , eUpdateUser = 4,
	eFindUser = 5 , eMainMenu = 6};
	
	static short _ReadManagerUsersMenuOptions()
	{
		cout << setw(37) << left << "" << "Choose what do  you want to do [ 1 to 6] : ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter number between 1 and 6 : ");
		return Choice;
	}

	static void _GoBackToMangerUsersMenu()
	{
		cout << "Press any key to go back to manager users menu ...";
		system("pause > 0");
		ShowManagerUsersMenu();
	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void 	_ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManagerUsersMenuOption(enManagerUsersMenuOptions  ManagerUsersMenuOptions)
	{
		switch (ManagerUsersMenuOptions)
		{
		case enManagerUsersMenuOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToMangerUsersMenu();
			break;
		}
		case enManagerUsersMenuOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToMangerUsersMenu();
			break;
		}
		case enManagerUsersMenuOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToMangerUsersMenu();
			break;
			
		}
		case enManagerUsersMenuOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToMangerUsersMenu();
			break;
		}
		case enManagerUsersMenuOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToMangerUsersMenu();
			break;
		}
		case enManagerUsersMenuOptions::eMainMenu:
		{

		}
		
		}
	}

public:

	static void ShowManagerUsersMenu()
	{
		

		if (!CheckAccessRigth(clsUser::enPermissions::pManagerUsers))
		{
			return;
		}
		system("cls");
		
		_DrawScreenHeader("Manager Users Screen");

		cout << setw(37) << left << "" << "==================================================================\n";
		cout << setw(37) << left << "" << "\t\t\t Manager Users  Menu\n";
		cout << setw(37) << left << "" << "==================================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================================================\n";
		_PerformManagerUsersMenuOption((enManagerUsersMenuOptions)_ReadManagerUsersMenuOptions());
	}



};

