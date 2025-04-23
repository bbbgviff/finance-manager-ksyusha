#pragma once


#include "User.h"

class RegisterManager
{
private:
	std::list<User> _users;
public:
	User GetUser(std::string login);
	bool checkLogin(std::string login, std::string passvord);
	bool Registration(std::string login, std::string passvord, Wallet wallet);
};