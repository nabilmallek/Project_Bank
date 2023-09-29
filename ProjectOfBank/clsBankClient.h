#pragma once
#include "clsPerson.h"
#include"clsString.h"
#include <iostream>
#include <vector>
#include <string>
#include"clsDate.h"
#include"Global.h"
#include <fstream>

using namespace std;






class clsBankClient : public clsPerson
{

private :

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	 enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool   _MarkToDelete = false;

	struct stTransferLog;
	static string _ConvertTransferDataToLine(clsBankClient SourceClient,clsBankClient DestinationClient,double Amount,string Seperator = "#//#")
	{
		string TransferData = "";

		TransferData += clsDate::GetSystemDateTimeString() + Seperator;
		TransferData += SourceClient.AccountNumber() + Seperator;
		TransferData += DestinationClient.AccountNumber() + Seperator;
		TransferData +=  to_string(Amount) + Seperator;
		TransferData +=  to_string(SourceClient.AccountBalance) + Seperator;
		TransferData += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferData += CurrentUser.UserName;

		return TransferData;
	}

    static clsBankClient  _ConvertLineToClientObject(string Line,string Seperator ="#//#")
	{
		
		     vector <string> vClientData;
		      vClientData = clsString::Split(Line, Seperator);

		       return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			  vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient  _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientDataFromeFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	static string _ConvertClientObjectToLine(clsBankClient Client , string Seperator ="#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);


		return stClientRecord;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> _vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			string DataLine;
			for (clsBankClient C : _vClients)
			{
				if (C._MarkToDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
	 void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientDataFromeFile();

		for (clsBankClient & C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}


	 void _AddNew()
	 {
		 _AddDataLineToFile(_ConvertClientObjectToLine(*this));
	 }

	 void _AddDataLineToFile(string stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }
	 }

	static  stTransferLog _ConvertTransferDataToRecord(string Line,string Seperator = "#//#")
	 {
		stTransferLog  TransferLogData;

		vector <string> vTransferLog = clsString::Split(Line, Seperator);

		TransferLogData.DateTime = vTransferLog[0];
		TransferLogData.S_AcountNumber = vTransferLog[1];
		TransferLogData.D_AcountNumber = vTransferLog[2];
		TransferLogData.Amount = stod(vTransferLog[3]);
		TransferLogData.S_AcountBalance = stod(vTransferLog[4]);
		TransferLogData.D_AcountBalance = stod(vTransferLog[5]);
		TransferLogData.UserName = vTransferLog[6];

		return TransferLogData;
	 }
public :

	clsBankClient(enMode Mode , string FirstName,string LastName,string Email , string Phone,string AccountNumber
	,string PinCode ,double AccountBalance):clsPerson(FirstName ,LastName ,Email ,Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLog
	{
		string DateTime;
		string S_AcountNumber;
		string D_AcountNumber;
		double Amount;
		double S_AcountBalance;
		double D_AcountBalance;
		string UserName;
	};

	 bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	 bool MarkToDelete()
	 {
		 return _MarkToDelete;
	 }

	 string AccountNumber()
	{
		return _AccountNumber;
	}
	
	// Property Set

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	// Property Get

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;


	void Print()
	{
		cout << "\n Client Card : ";
		cout << "\n_____________________________________";
		cout << "\nFirstName : " << FirstName;
		cout << "\nLastName : " << LastName;
		cout << "\nFullName : " << FullName();
		cout << "\nEmail : " << Email;
		cout << "\nPhone : " << Phone;
		cout << "\nAccountNumer : " << _AccountNumber;
		cout << "\nPinCode : " << _PinCode;
		cout << "\nAccountBalance : " << _AccountBalance;
		cout << "\n______________________________________\n";
	}


	static clsBankClient  Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);// read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient  Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient  Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);// read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient  Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient  Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

	enum  enSaveResults {svFailEmptyObject = 0 , svSacceeded = 1, svFailAccountNumberExists = 2};

	enSaveResults  Save()
	{
		switch (_Mode)
		{
		 case enMode::EmptyMode:
		 {
			 return enSaveResults::svFailEmptyObject;
			 
		 }
		 case enMode::UpdateMode:
		 {
			 _Update();
			 return enSaveResults::svSacceeded;
			 break;
		 }
		 case enMode::AddNewMode:
		 {

			 if (clsBankClient::IsClientExist(_AccountNumber))
			 {
				 return enSaveResults::svFailAccountNumberExists;

			 }
			 else
			 {
				 _AddNew();
				 _Mode = enMode::UpdateMode;
				 return enSaveResults::svSacceeded;
			 }

			 break;


		 }
		}
	}

	 void Deposit(double Amount)
	{
		 _AccountBalance += Amount;
		 Save();
	}

	 bool Withdraw(double Amount)
	 {
		 if (_AccountBalance < Amount)
		 {
			 return false;
		 }
		 else
		 {
			 _AccountBalance -= Amount;
			 Save();
			 return true;
		 }
		 
		 
		 
		 
	 }
	
	 bool Delete()
	{
		vector <clsBankClient> vClients;

		vClients = _LoadClientDataFromeFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkToDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;

    }
	static clsBankClient   GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromeFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromeFile();

		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}

	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			return true;
		}
	}

	static void SaveTransferDataToFile(clsBankClient SourceClient,clsBankClient DestinationClient,double Amount)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			string TransferData = _ConvertTransferDataToLine(SourceClient,DestinationClient,Amount);

			MyFile << TransferData << endl;

			MyFile.close();
		}
		
	}

	static vector <stTransferLog> GetTransferLogData()
	{
		vector <stTransferLog> vTransferLog;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			stTransferLog  TransferLogInfo;

			while (getline(MyFile, Line))
			{
				TransferLogInfo = _ConvertTransferDataToRecord(Line);
				vTransferLog.push_back(TransferLogInfo);
			}

			MyFile.close();
		}

		return vTransferLog;
	}
};

