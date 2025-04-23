#include "User.h"

bool User::operator==(User second)
{
	if (this->_login == second._login &&
		this->_password == second._password)
	{
		return true;
	}

	return false;
}

Wallet* User::GetWallet()
{
	return this->_wallet;
}

void User::CreateWallet(std::string walletName)
{
	this->_wallet->SetName(walletName);
}

std::string User::GetLogin() {
	return _login;
}
std::string User::GerPassvord() {
	return _password;
}

void User::SetWallet(Wallet* wallet) {
	this->_wallet = wallet;
}
void User::SetLogin(std::string login) {
	_login = login;
}
void User::SetPassvord(std::string passvord) {
	_password = passvord;
}