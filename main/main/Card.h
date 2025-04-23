#pragma once


#include <iostream>
#include <string>

class Card
{
private:	
	unsigned int _balance;
	unsigned int _number;
	bool _status;
public:
	Card() = default;
	Card(int balance, unsigned int number);

	bool TopUp(int sum);
	bool TakeOff(int sum);

	void SetNumber(unsigned int number);
	void SetStatus(bool status);

	unsigned int GetBalance();
	unsigned int GetNumber();
	bool GetStatus();

	bool Rebalance(int sumMinus);

	//void Print();
};