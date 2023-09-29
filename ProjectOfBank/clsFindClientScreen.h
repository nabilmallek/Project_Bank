#pragma once
#include <iostream>
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include"clsScreen.h"
using namespace std;






class clsFindClientScreen : protected clsScreen
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

public:


	static void ShowFindClientScreen()
	{

        if (!CheckAccessRigth(clsUser::enPermissions::pFindClients))
        {
            return;
        }
        
        _DrawScreenHeader("Find Client Screen");

        string AccountNumber = "";
        cout << "\n Please enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found,enter another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient  Client1 = clsBankClient::Find(AccountNumber);
        
        if (!Client1.IsEmpty())
        {
            cout << " \nClient is founded";
        }
        else
        {
            cout << "\nClient was not founded";
        }
        
        _PrintClient(Client1);
	}

};

