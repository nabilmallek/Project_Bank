#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"







class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\n\n Client Card : ";
        cout << "\n_____________________________________";
        cout << "\n\nFullName : " << Client.FullName();
        cout << "\nAccountNumer : " << Client.AccountNumber();
        cout << "\nAccountBalance : " << Client.AccountBalance;
        cout << "\n______________________________________\n\n";
    }

    static double ReadAmount(clsBankClient  SourceClient)
    {
        double Amount;
        cout << "\nPlease enter deposit amount : ";
        Amount = clsInputValidate::ReadDblNumber();
        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\n Amount Exceeds the available Balance, Enter another Amount ?";
            Amount = clsInputValidate::ReadDblNumber();
        }

        return Amount;

    }

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

        string AccountNumber = "";
        cout << "\n Please enter Account Number to transfer from : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found,enter another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient  SourceClient = clsBankClient::Find(AccountNumber);

        _PrintClient(SourceClient);

        cout << "\n Please enter Account Number to transfer to : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found,enter another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient  DestinationClient = clsBankClient::Find(AccountNumber);

        _PrintClient(DestinationClient);

        double Amount = ReadAmount(SourceClient);
        

        

        char Answer = 'n';
        cout << "\nAre you sur you want to perform this operation ? : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\n Transfer done successfully";
            }
            else
            {
                cout << "\n Transfer failed";
            }
            
            
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
        clsBankClient::SaveTransferDataToFile(SourceClient, DestinationClient, Amount);
	}

    
};

