#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;








class clsWithdrawScreen: protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

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
			if (Client1.Withdraw(Amount))
			{
				cout << "\n Amount WithDraw  successfully.";
				cout << "\n New Balances is : " << Client1.AccountBalance << endl;
			}
			else
			{
				cout << "\n Can not WithDraw ; Insufficent Balances .";
				cout << "\n Amount to withdraw is : " << Amount;
				cout << "\n Your Balances is : " << Client1.AccountBalance << endl;
			}
		}
	}


};

