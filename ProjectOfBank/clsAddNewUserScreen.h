#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;









class clsAddNewUserScreen :  protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\n Enter FirstName : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\n Enter LastName : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\n Enter Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "\n enter Phone : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\n Enter Password : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\n Enter Permission : ";
		User.Permissions = _ReadPemissionsToSet();
	}

	static int _ReadPemissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';
		
		cout << "\n Do you want to give all access y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\n Do you want to give access to  :";
		cout << "\n Show Clients : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\n Add New Clients : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClients;
		}

		cout << "\n Delete Clients : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClients;
		}

		cout << "\n Update Clients : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\n Find Clients : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClients;
		}

		cout << "\n Transactions : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\n Manager Users : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManagerUsers;
		}

		cout << "\n Login Register : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}
		return Permissions;
	}


	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}
public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		string UserName = "";
		cout << "\nPlease enter User Name : ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\n User Name already exist , enter another one : ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(NewUser);

		clsUser::enSaveResults  SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\n User Add Successfully ";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "Error User was not saved because empty object";
			break;
		}
		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "Error User was not saved because User Exist";
			break;
		}
		
		}
	}


};

