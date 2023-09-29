#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include <iomanip>

using namespace std;




class clsTransferLogScreen : protected clsScreen
{
private:

	static void  _PrintTransferLogData(clsBankClient::stTransferLog Record)
	{
		cout << setw(8) << left << "" << "|" << left << setw(20) << Record.DateTime;
		cout << "|" << left << setw(15) << Record.S_AcountNumber;
		cout << "|" << left << setw(15) << Record.D_AcountNumber;
		cout << "|" << left << setw(12) << Record.Amount;
		cout << "|" << left << setw(12) << Record.S_AcountBalance;
		cout << "|" << left << setw(12) << Record.D_AcountBalance;
		cout << "|" << left << setw(10) << Record.UserName ;
	}
public:


	static void ShowTrasferLogScreen()
	{
		
		vector <clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLogData();
		string Title = "Transfer Log Screen";
		string SubTitle = "\t (" + to_string(vTransferLog.size()) + ") Transfer(s)";

		
		_DrawScreenHeader(Title,SubTitle);

		cout << "\n\t_______________________________________________________________________________________________________\n\n";
		cout << setw(8) << left << "" << "|" << left << setw(20) << "DateTime ";
		cout << "|" << left << setw(15) << "S.A.Number";
		cout << "|" << left << setw(15) << "D.A.Number";
		cout << "|" << left << setw(12) << "Amount";
		cout << "|" << left << setw(12) << "S.A.Balance";
		cout << "|" << left << setw(12) << "D.A.Balance";
		cout << "|" << left << setw(10) << "User Name";
		cout << "\n\t________________________________________________________________________________________________________\n";

		if (vTransferLog.size() == 0)
		{
			cout << "\ No Transfer Log Data founded\n";
		}
		
		
		for (clsBankClient::stTransferLog Record : vTransferLog)
		{
			 _PrintTransferLogData(Record);
			 cout << endl;
		}

		

	}


};

