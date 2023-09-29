#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;






class clsAddNewClientScreen : protected clsScreen
{
private:
  static  void  _ReadClientInfo(clsBankClient& Client1)
    {
        cout << "\nEnter FirstName : ";
        Client1.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName : ";
        Client1.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        Client1.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        Client1.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode : ";
        Client1.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter AccountBalance : ";
        Client1.AccountBalance = clsInputValidate::ReadDblNumber();
    }

 static void _PrintClient(clsBankClient Client)
  {
      cout << "\n Client Card : ";
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

   static  void ShowAddNewClientScreen()
    {

       if (!CheckAccessRigth(clsUser::enPermissions::pAddNewClients))
       {
           return;
       }
       
       
       _DrawScreenHeader(" Add New Client Screen");
       
       string AccountNumber = "";
        cout << "Please Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number used , enter another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient  NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults  SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svFailEmptyObject:
        {
            cout << "Error Account was not savesd because Account is empty";
            break;
        }
        case clsBankClient::enSaveResults::svFailAccountNumberExists:
        {
            cout << "Error Account was not saved becouse Account is already exists";
            break;
        }
        case clsBankClient::enSaveResults::svSacceeded:
        {
            cout << " Account Added Successfuly : -)";
            _PrintClient(NewClient);
            break;
        }

        }
    }



};

