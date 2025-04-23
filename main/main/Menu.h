#pragma once


#include "User.h"
#include "RegisterManager.h"

class Menu
{
private:
	RegisterManager _registrator;
	bool Print(User user);
public:
	Menu(RegisterManager registrator);
	void Invite();
};