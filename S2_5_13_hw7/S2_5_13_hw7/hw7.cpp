#include<iostream>
#include<string>
using namespace std;
#include "Security.h"
#include "Administrator.h"
#include "User.h"

int main() {
	string User_password = "monday"
		, User_name = "abbott"
		, Administrator_password = "tuesday"
		, Administrator_name = "costello"
		, Other_password = "wednesday"
		, Other_name = "aaaaa";

	cout << "Administrator Test:" << endl;
	cout << "name: " << Administrator_name << "\npassword: " << Administrator_password << endl;
	cout << "Is administract ?";
	if (Administrator::Login(Administrator_name, Administrator_password)) {
		cout << " True" << endl;
	}
	else {
		cout << " False" << endl;
	}

	cout << "Is user ?";
	if (User::Login(Administrator_name, Administrator_password)) {
		cout << " True" << endl;
	}
	else {
		cout << " False" << endl;
	}

	cout << endl;

	cout << "User Test:" << endl;
	cout << "name: " << User_name << "\npassword: " << User_password << endl;
	cout << "Is administract ?";
	if (Administrator::Login(User_name, User_password)) {
		cout << " True" << endl;
	}
	else {
		cout << " False" << endl;
	}

	cout << "Is user ?";
	if (User::Login(User_name, User_password)) {
		cout << " True" << endl;
	}
	else {
		cout << " False" << endl;
	}

	cout << endl;

	cout << "Other Test:" << endl;
	cout << "name: " << Other_name << "\npassword: " << Other_password << endl;
	cout << "Is administract ?";
	if (Administrator::Login(Other_name, Other_password)) {
		cout << " True" << endl;
	}
	else {
		cout << " False" << endl;
	}

	cout << "Is user ?";
	if (User::Login(Other_name, Other_password)) {
		cout << " True" << endl;
	}
	else {
		cout << " False" << endl;
	}
}