#include<iostream>
#include<string>
using namespace std;
#include "Security.h"

int Security::validate(string username, string password) {
	if ((username == "abbott") && (password == "monday")) {
		return 1;
	}
	if ((username == "costello") && (password == "tuesday")) {
		return 2;
	}
	return 0;
}
