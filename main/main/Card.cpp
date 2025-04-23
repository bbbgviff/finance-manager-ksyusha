#include "Card.h"

Card::Card(int balance, unsigned int number) {
	_balance = balance;
	_number = number;
	_status = false;
}

void Card::SetNumber(unsigned int number) {
	_number = number;
}
void Card::SetStatus(bool status) {
	_status = status;
}

unsigned int Card::GetBalance()
{
	return _balance;
}
unsigned int Card::GetNumber() {
	return _number;
}
bool Card::GetStatus() {
	return _status;
}

bool Card::Rebalance(int sumMinus)
{
	if (sumMinus > 0)
	{
		this->_balance -= sumMinus;
		return true;
	}

	return false;
}

bool Card::TopUp(int sum)
{
	_balance += sum;
	return true;

}

bool Card::TakeOff(int sum) {
	if (sum > 0 && _balance >= sum)
	{
		this->_balance -= sum;
		return true;
	}
	return false;
}