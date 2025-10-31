#pragma once
#include <iostream>

class Account {
public:
	Account();
	void Balance();
	void Deposit(int deposit);
	void Withdrawl(int withdrawl);
private:
	int balance;
};