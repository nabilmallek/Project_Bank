#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;




class clsClientListScreen : protected clsScreen
{
private:

   static void   _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(20) << Client.FullName();
        cout << "|" << left << setw(20) << Client.Email;
        cout << "|" << left << setw(12) << Client.Phone;
        cout << "|" << left << setw(10) << Client.PinCode;
        cout << "|" << left << setw(12) << Client.AccountBalance;
    } 

public:

   static  void   ShowClientsList()
    {

       if (!CheckAccessRigth(clsUser::enPermissions::pListClients))
       {
           return;
       }
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "Client List Screen";
        string   SubTitle = "\t (" + to_string(vClients.size()) + ") Client(s)";

        _DrawScreenHeader(Title, SubTitle);
       
       
        cout  << "\n\t__________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "|" << left << setw(15) << "Account Number ";
        cout << "|" << left << setw(20) << "Client Name";
        cout << "|" << left << setw(20) << "Email";
        cout << "|" << left << setw(12) << "Phone";
        cout << "|" << left << setw(10) << "PinCode";
        cout << "|" << left << setw(12) << "Balance";
        cout << "\n\t___________________________________________________________________________________________________\n";

        double TotalBalances = clsBankClient::GetTotalBalances();
        
        if (vClients.size() == 0)
        {
            cout << "No Clients list founded";
        }

        for (clsBankClient& Client : vClients)
        {
            _PrintClientRecordLine(Client);
            cout << endl << endl;
        }

        cout << "\t_______________________________________________________________________________________________\n";
        cout << "\t\t\t\t Total Balances : " << TotalBalances << endl;
        cout << "\t\t\t\t" << clsUtil::NumberToText(TotalBalances);

    }

};

