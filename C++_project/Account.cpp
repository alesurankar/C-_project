#include "Account.h"

Account::Account()
	:
	balance(0)
{}

void Account::Balance()
{
	std::cout << "Your balance is: " << balance << "\n";
}

void Account::Deposit(int deposit)
{
	balance += deposit;
}

void Account::Withdrawl(int withdrawl)
{
	if (balance >= withdrawl)
	{
		balance -= withdrawl;
	}
	else {
		std::cout << "balance to low\n";
	}
}
