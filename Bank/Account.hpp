#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Account 
{
	// YOU MAY MODIFY ANYTHING HERE

	protected:
		Account* next;
		int acc_number;
		string acc_name;
		float balance;
		float interest;
		

	public:

		virtual void update() {};
		virtual void transaction(float trans) {};											//2 functions for accounts
		virtual void setNext(Account* _n) {};

		string getName() { return acc_name; }
		void setName(string x) { acc_name = x; }
		
		int getAccNum() { return acc_number; }
		void setAccNum(int x) { acc_number = x; }

		float getBalance() { return balance; }
		void setBalance(float x) { balance = x; }
		
		Account* getNext() { return next; }
		

		Account(int acc_n, string acc_na, float bal, float inter) 
		{
			acc_number = acc_n; 
			acc_name = acc_na;
			balance = bal; 
			interest = inter;
			next = NULL;
			next = 0;
		}// Constructor
};

#endif