#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsUser.h"
using namespace std;





class clsLoginRegisterScreen : protected clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }

public:


	static void ShowLoginRegister()
	{
        
        if (!CheckAccessRigth(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }
        
        
        
        
        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
        string Title = "Login Register Screen";
        string SubTitle = "\t (" + to_string(vLoginRegisterRecord.size()) + ") Record(s)";

        _DrawScreenHeader(Title, SubTitle);


        cout << "\n\t__________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "|" << left << setw(35) << "DateTime ";
        cout << "|" << left << setw(20) << "User Name";
        cout << "|" << left << setw(20) << "Password";
        cout << "|" << left << setw(10) << "Permissions";
        
        cout << "\n\t___________________________________________________________________________________________________\n";

        

        if (vLoginRegisterRecord.size() == 0)
        {
            cout << "No Logins Register in the System";
        }

        for ( clsUser::stLoginRegisterRecord  Record : vLoginRegisterRecord)
        {
            PrintLoginRegisterRecordLine(Record);
            cout << endl << endl;
        }

	}


};

