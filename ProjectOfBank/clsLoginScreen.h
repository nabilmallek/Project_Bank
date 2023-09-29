#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
using namespace std;









class clsLoginScreen  : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		string UserName, Password;
		short FailedLoginCount = 0;

		do
		{
			
			
			
				if (LoginFaild  )
				{
					FailedLoginCount++;
					
						cout << "\nInvalid UserName/Password\n";
						 
						cout << "\nyou have " << (3 - FailedLoginCount) << " Trails to login\n ";
						
					
					
				}

				if (FailedLoginCount == 3)
				{
					cout << "\nyou are loked after 3 failed trails\n";
					return false;
				}
				cout << "Enter User Name : ";
				cin >> UserName;
				cout << "\n Enter Password : ";
				cin >> Password;
			
			

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild );

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenu();

		return true;
	}
public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("LogIn Screen");
		return _Login();
	}

	

};

