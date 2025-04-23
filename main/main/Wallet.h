#pragma once


#include "Card.h"
#include <list>

class Wallet
{
private:
    Card* _card;
	std::string _name;
    bool _status;
public:
    Wallet() = default;
    Wallet(Card* card, std::string name, bool status);

    Card* GetCard();

    std::string GetName();
    bool GetStatus();

    void SetName(std::string walletName);
    void SetStatus(bool status);
};