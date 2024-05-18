#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
using namespace std;

class User {
public:
	static bool Login(string username, string password);
};
#endif