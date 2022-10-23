#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "Account.hpp" // ONLY BARE minimum skeleton provided


// CREATE these files ...
#include "Checking.hpp"
#include "Savings.hpp"
#include "Loan.hpp"
using namespace std;


// FEEL FREE to ADD/DELETE Anything, but make sure it does not fail compilation of UNMODIFIED test.cpp
class Bank {
private:
	int accounts = 0;										//starts with no accounts
	Account* head;
	Account* end;
	Account* temp;

	public:
		Bank()
		{
			head = NULL;
			end = NULL;
			temp = NULL;
		}// Constructor
		void account(char f_letter, int acc_number, string acc_name, float balance, float interest);//creates an account

		void process(string line); //processes the input file text

		Account* findNumber(int acc_num); // Finds the account Number

		int getCount() { return accounts; }

		// Provided for YOU :-)

		Account* operator[](int acc_num) { return findNumber(acc_num); }										//overloads the [] operator to find the account


		// ADD any other functions you deem necessary

};

// ALL IMPLEMENTATION Goes Here

void Bank::account(char f_letter, int acc_n, string acc_na, float bal, float inte)
{
	Account* to_new;
	if (f_letter == 115)			//"s"
	{
		Savings *ne = new Savings(acc_n, acc_na, bal, inte);
		to_new = ne;
	}
	else
	{
		if (f_letter == 99)			//"c" 
		{
			Checking *ne = new Checking(acc_n, acc_na, bal, inte);
			to_new = ne;
		}
		else						//"l"
		{
			Loan *ne = new Loan(acc_n, acc_na, bal, inte);
			to_new = ne;
		}
	}

	if (accounts <= 0)
	{
		head = to_new;
		temp = to_new;
	}
	else
	{
		end = to_new;

		temp->setNext(to_new);

		temp = to_new;
	}

	accounts++;
}

void Bank::process(string line)
{
	size_t found = 0, temp = 0;
	char f_letter = 0;
	int acc_n = 0;
	string acc_na, b, i;
	float bal=0, inte=0;

	f_letter = line.at(0);

	found = line.find_first_not_of(" ", 1);

	acc_n = stoi(line.substr(found,1));

	if(f_letter == 115 || f_letter == 99 || f_letter == 108)
	{ 
		found = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", found);
		temp = line.find_first_of(" ", found);
		acc_na = line.substr(found, (temp-found));

		found = temp+1;

		temp = line.find_first_of(" ", found);

		b = line.substr(found, (temp-found));

		bal = stof(b);

		found = temp+1;

		i = line.substr(found, string::npos);

		inte = stof(i);

		account(f_letter, acc_n, acc_na, bal, inte);
	}
	else
	{
		Account* one = NULL, * two = head;

		for (int j = 0; j < acc_n; j++)
		{
			one = two->getNext();
			two = one;
		}

		if (f_letter == 116) //"t"
		{
			found = line.find_first_of("0123456789-", (found + 1));

			b = line.substr(found, string::npos);

			bal = stof(b);

			two->transaction(bal);
		}
		else
		{
			two->update();
		}
	}

}

Account* Bank::findNumber(int acc_num)
{
	Account* tem = NULL, * cur = head;
	int i = 0;
	
	while (i < acc_num)
	{
		temp = cur->getNext();

		cur = temp;

		i++;
	}

	return cur;
}

#endif