#ifndef SAVINGS_HPP
#define SAVINGS_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Account.hpp"
using namespace std;

class Savings : public Account
{
public:

	Savings(int an, string ana, float b, float i): Account(an, ana, b, i) {}

	Savings(): Account(0, 0, 0, 0) {}

	virtual void update();

	virtual void transaction(float trans);

	void setNext(Account* _n) { next = _n; }
};

void Savings::update()
{
	balance = balance + (balance * interest);
}

void Savings::transaction(float trans)
{
	if (trans < 0 && (balance + trans) < 0)
	{

	}
	else
		balance = balance + trans;
}


#endif
