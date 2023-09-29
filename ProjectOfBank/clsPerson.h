#pragma once
#include <iostream>
using namespace std;



class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;


public:

	clsPerson(string FirstName , string LastName,string Email ,string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//property Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	// Property Get

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;


	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;


	string FullName()
	{
		return _FirstName + " " + _LastName;
	}


	void Print()
	{
		cout << "\n Info :";
		cout << "\n_________________________________________";
		cout << "\n FirstName : " << _FirstName;
		cout << "\n LastName : " << _LastName;
		cout << "\n FullName : " << FullName();
		cout << "\n Email : " << _Email;
		cout << "\n Phone : " << _Phone;
		cout << "\n_________________________________________\n";
	}
};

