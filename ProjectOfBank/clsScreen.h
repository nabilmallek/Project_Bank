#pragma once
#include <iostream>
#include "clsUser.h"
#include"Global.h"
#include "clsDate.h"
using namespace std;



class clsScreen 
{

protected:

	static void _DrawScreenHeader(string Title , string subTitle ="")
	{
		cout << "\t\t\t\t\t________________________________________________";
		cout << "\n\n                   \t\t\t\t\t" << Title;
		if (subTitle != "")
		{
			cout << " \n\t\t\t\t\t\t" << subTitle;
		}
		cout << "\n\n\t\t\t\t\t_________________________________________________\n\n";
		cout << "\t\t\t\tUser : " << CurrentUser.UserName << endl;
		cout << "\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl;
	}

	static bool CheckAccessRigth(clsUser::enPermissions  Permissions)
	{
		if (!CurrentUser.CheckAccessPermission(Permissions))
		{
			cout << "\t\t\t\t_________________________________________________________";
			cout << "\n\n\t\t\t\t Access Denied , contact your Admin";
			cout << "\n\t\t\t\t_________________________________________________________";

			return false;
		}
		else
		{
			return true;
		}

		
	}

	
	
};

