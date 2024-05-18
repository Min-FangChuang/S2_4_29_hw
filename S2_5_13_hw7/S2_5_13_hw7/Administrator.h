#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<iostream>
#include<string>
using namespace std;

class Administrator {
public:
	static bool Login(string username, string password);
};

#endif
