#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;







class clsUpdateUserScreen : protected clsScreen
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

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");
		string UserName = "";
		cout << "Please enter User Name : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name not found ,Please enter another one : ";
			UserName = clsInputValidate::ReadString();
		}


		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);
		char Answer = 'n';
		cout << "\nAre you sur you want to update this  user : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n Update user info : ";
			cout << "\n___________________________";
			_ReadUserInfo(User1);

		}

		clsUser::enSaveResults  SaveResult;

		SaveResult = User1.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "User Updated successfully\n";
			_PrintUser(User1);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "Error user was not saved because empty object\n";
			break;
		}
		
		}
	}

	

};

