#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;



class clsUpdateClientScreen : protected clsScreen
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


    static  void ShowUpdateClientScreen()
    {


        if (!CheckAccessRigth(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        _DrawScreenHeader("Update Client Screen");

        string AccountNumber = "";

        cout << "\nPlease enter Client AccountNumber : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n AccountNumber is not found , choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\n Update Client Info : ";
        cout << "\n_________________________________\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults   SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSacceeded:
        {
            cout << "\nClient Updated Successfuly :-)" << endl;
            _PrintClient(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFailEmptyObject:
        {
            cout << " Error Account was not saved Because it is Empty";
            break;
        }

        }

    }
    
};

