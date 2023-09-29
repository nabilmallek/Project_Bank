#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;





class clsDepositScreen: protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\n Client Card : ";
		cout << "\n_____________________________________";
		cout << "\nFirstName : " << Client.FirstName;
		cout << "\nLastName : " << Client.LastName;
		cout << "\nFullName : " << Client.FullName();
		cout << "\nEmail : " << Client.Email;
		cout << "\nPhone : " << Client.Phone;
		cout << "\nAccountNumer : " << Client.AccountNumber();
		cout << "\nPinCode : " << Client.PinCode;
		cout << "\nAccountBalance : " << Client.AccountBalance;
		cout << "\n______________________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "Enter Account Number : ";
		cin >> AccountNumber;

		return AccountNumber;
	}

public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client  with [" << AccountNumber << "] does not exist enter another one : ";
			string AccountNumber = _ReadAccountNumber();
		}

		clsBankClient  Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter deposit amount : ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\n Are you sur you want to perform this transaction : ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Deposit(Amount);
			cout << "\n Amont deposited successfully.\n";
			cout << "New Balances is : " << Client1.AccountBalance << endl;
		}
		else
		{
			cout << "\n Deposit cannceled\n";
		}
		
		
		
		
		


	}

};

