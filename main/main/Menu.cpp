#include "Menu.h"

Menu::Menu(RegisterManager registrator) {
	_registrator = registrator;
}

bool Menu::Print(User currentUser)
{
	std::cout << std::endl;
	int UserChoice = 0;
	const int LastIndex = 6;
	std::string array[LastIndex] = {
		"Add wallet",
		"Add new card",
		"Top up balance",
		"Withdraw money",
		"Show the balance",
		"Exit"
	};

	for (int i = 0; i < LastIndex; i++)
	{
		std::cout << i + 1 << ". " << array[i] << std::endl;
	}

	do
	{
		std::cout << std::endl << "Set menu element: ";
		std::cin >> UserChoice;

		if (UserChoice < 0 || UserChoice > 6)
		{
			std::cout << std::endl << "Set menu element between from 1 to 6" << std::endl;
		}
	} while (UserChoice < 1 || UserChoice > 6);

	switch (UserChoice)
	{
	case 1:
	{
		std::cout << std::endl << "Set wallet name:" << std::endl;
		std::string walletName = "";
		std::cin >> walletName;
		currentUser.CreateWallet(walletName);
		currentUser.GetWallet()->SetStatus(true);
		system("cls");
		return true;
		break;
	}
	case 2:
	{
		if (currentUser.GetWallet()->GetStatus() == true) {
			unsigned int number;
			std::cout << std::endl << "Enter card number: " << std::endl;
			std::cin >> number;

			currentUser.GetWallet()->GetCard()->SetNumber(number);
			currentUser.GetWallet()->GetCard()->SetStatus(true);
			system("cls");
		}
		else {
			std::cout << std::endl << "Error! The wallet was not created" << std::endl;
		}
		return true;
		break;
	}
	case 3:
	{
		if (currentUser.GetWallet()->GetCard()->GetStatus() == true) {
			bool buf = false;
			while (!buf) {
				std::cout << std::endl << "Set sum:" << std::endl;
				unsigned int sum;
				std::cin >> sum;
				if (sum > 0) {
					currentUser.GetWallet()->GetCard()->TopUp(sum);
					buf = true;
				}
				else {
					std::cout << std::endl << "Error! Enter the correct amount to top up your balance" << std::endl;
				}
			}
			system("cls");
		}
		else {
			std::cout << std::endl << "Error! There are no cards in the wallet" << std::endl;
		}
		return true;
		break;
	}
	case 4:
	{
		if (currentUser.GetWallet()->GetCard()->GetStatus() == true) {
			bool buf = false;
			while (!buf) {
				std::cout << std::endl << "Set sum:" << std::endl;
				unsigned int sum;
				std::cin >> sum;

				if (currentUser.GetWallet()->GetCard()->GetBalance() > sum) {
					currentUser.GetWallet()->GetCard()->TakeOff(sum);
					buf = true;
				}
				else if (sum < 0 || sum == 0) {
					std::cout << std::endl << "Error! Specify the amount you want to withdraw from the account" << std::endl;
				}
				else {
					std::cout << std::endl << "Error! The card balance is less than the withdrawal amount!" << std::endl;
				}
			}
			system("cls");
		}
		else {
			std::cout << std::endl << "Error! There are no cards in the wallet" << std::endl;
		}
		return true;
		break;
	}
	case 5:
	{
		if (currentUser.GetWallet()->GetCard()->GetStatus() == true) {
			std::cout << std::endl << "The balance of the number " << currentUser.GetWallet()->GetCard()->GetNumber() << " card is: " << currentUser.GetWallet()->GetCard()->GetBalance() << std::endl;
		}
		else {
			std::cout << std::endl << "Error! There are no cards in the wallet" << std::endl;
		}
		return true;
		break;
	}
	case 6:
		Invite();
	default:
		std::cout << "Unexpected error..." << std::endl;
		break;
	}

	return false;
}

void Menu::Invite()
{
	std::cout << std::endl << "1. Sign in" << std::endl;
	std::cout << "2. Registration" << std::endl;
	std::cout << "3. Exit" << std::endl;

	int userChoice = 0;
	std::cin >> userChoice;
	std::string login = "";
	std::string password = "";

	bool isAuthentificate;
	switch (userChoice)
	{
	case 1:
		std::cout << "Enter login: ";
		std::cin >> login;

		std::cout << "Enter password: ";
		std::cin >> password;

		isAuthentificate = _registrator.checkLogin(login, password);
		if (isAuthentificate) {
			User currentUser = _registrator.GetUser(login);
			while (true) {
				Print(currentUser);
			}
		}
		else {
			std::cout << "Erroe! Could not create an account." << std::endl;
		}
		break;
	case 2:
	{
		std::cout << "Enter login: ";
		std::cin >> login;

		std::cout << "Enter password: ";
		std::cin >> password;

		Card card = Card();
		std::string a = "";
		Wallet wallet = Wallet(&card, a, false);
		bool isRegistered = _registrator.Registration(login, password, wallet);
		if (isRegistered)
		{
			User currentUser = _registrator.GetUser(login);
			while (true) {
				Print(currentUser);
			}
		}
		break;
	}
	case  3:
		break;
	default:
		break;
	}
}