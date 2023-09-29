#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;









class clsDeleteClientScreen : protected clsScreen
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

   static  void ShowDeleteClientScreen()
    {
        

       if (!CheckAccessRigth(clsUser::enPermissions::pDeleteClients))
       {
           return;
       }
       
       
       _DrawScreenHeader("Delete Client Screen");
       
       string AccountNumber = "";
        cout << "\n Please enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found,enter another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient  Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        char Answer;
        cout << "\nAre Sur you want to delete this Client : ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted successfuly : -)";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError client was not deleted ";
            }
        }
    }


};

