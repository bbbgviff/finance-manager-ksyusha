#include "Wallet.h"

Wallet::Wallet(Card* card, std::string name, bool status)
{
    this->_card = card;
    _name = name;
    _status = status;
}

Card* Wallet::GetCard()
{
    return this->_card;
}

std::string Wallet::GetName()
{
    return _name;
}
bool Wallet::GetStatus() {
    return _status;
}

void Wallet::SetName(std::string walletName) {
    _name = walletName;
}
void Wallet::SetStatus(bool status) {
    _status = status;
}