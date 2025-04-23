#include "RegisterManager.h"

User RegisterManager::GetUser(std::string login) {
	for (User user : _users) {
		if (user.GetLogin() == login) {
			return user;
		}
	}
}

bool RegisterManager::checkLogin(std::string login, std::string passvord) {
	for (auto user : _users) {
		if (user.GetLogin() == login && user.GerPassvord() == passvord) {
			return true;
		}
	}
	return false;
}

bool RegisterManager::Registration(std::string login, std::string passvord, Wallet wallet) {
	if (!checkLogin(login, passvord)) {
		User user = User();
		user.SetLogin(login);
		user.SetPassvord(passvord);

		user.SetWallet(&wallet);

		_users.push_back(user);
		return true;
	}
	return false;
}