#ifndef LOAN_HPP
#define LOAN_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Account.hpp"
using namespace std;

class Loan : public Account 
{
public:

	Loan(int an, string ana, float b, float i): Account(an, ana, b, i) {}

	Loan(): Account(0, 0, 0, 0) {}

	virtual void update();

	virtual void transaction(float trans);

	void setNext(Account* _n) { next = _n; }
};

void Loan::update()
{
	balance = balance + (balance * interest);
}

void Loan::transaction(float trans)
{
	balance = balance - trans;
}

#endif