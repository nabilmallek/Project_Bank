#pragma once
#include <iostream>
#include "clsBankClient.h"
#include"clsUtil.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;







class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void   _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(40) << Client.FullName();
        cout << "|" << left << setw(12) << Client.AccountBalance;
    }

public:

	static void ShowTotalBalancesScreen()
	{
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "Client List Screen";
        string SubTitle = "\t (" + to_string(vClients.size()) + ") Client(s)";

        _DrawScreenHeader(Title, SubTitle);


        cout <<setw(25) << left<< "" << "\n\t\t_________________________________________________________________________________________________\n\n";
        cout << setw(25) << left << "" << "|" << left << setw(15) << "Account Number ";
        cout << "|" << left << setw(40) << "Client Name";
        cout << "|" << left << setw(12) << "Balance";
        cout <<setw(25) << left << "" << "\n\t\t_________________________________________________________________________________________________\n";

        
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

        cout << setw(25) << left << "" << "\n\t\t________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "" << "\n\tTotal Balances : " << TotalBalances<< endl;
        cout << setw(8) << left << "" << "(" << clsUtil::NumberToText(TotalBalances) << ")" <<endl <<endl;

    }
	


};

