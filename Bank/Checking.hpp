#ifndef CHECKING_HPP
#define CHECKING_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Account.hpp"
using namespace std;

class Checking : public Account
{
	int checks = 1;

public:

	Checking(int an, string ana, float b, float i): Account(an, ana, b, i) {}

	Checking(): Account (0,0,0,0) {}

	virtual void update();

	virtual void transaction(float trans);

	void setNext(Account* _n) { next = _n; }
};

void Checking::update()
{
	balance = balance - (checks * interest);
	checks = 0;
}

void Checking::transaction(float trans)
{
	if ((balance + trans) < 0)
		balance = balance - 25;
	else
	{
		balance = balance + trans;

		if (trans < 0)
		{
			checks++;
		}
	}
}

#endif