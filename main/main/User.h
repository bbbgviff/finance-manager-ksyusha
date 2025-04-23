#pragma once


#include <string>
#include "Wallet.h"

class User
{
private:
	Wallet* _wallet;
	std::string _login;
	std::string _password;
public:
	bool operator==(User second);

	Wallet* GetWallet();

	void CreateWallet(std::string walletName);

	std::string GetLogin();
	std::string GerPassvord();

	void SetWallet(Wallet* wallet);
	void SetLogin(std::string login);
	void SetPassvord(std::string passvord);
};