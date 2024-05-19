#include<iostream>
#include<string>
#include "Security.h"
#include "User.h"
using namespace std;

bool User::Login(string username, string password) {
	//not user and administrator return false
	if (Security::validate(username, password) == 0) {
		return false;
	}
	else {
		return true;
	}
}