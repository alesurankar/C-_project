#include "MyClass.h"
#include "Calculator.h"
#include "NumGuess.h"
#include "Account.h"
#include <iostream>
#include <vector>

int main() {
	Account ac;
	char choice;
	int quantity;
	while (true)
	{
		std::cout << "(b)alance, (d)eposit, (w)ithdrawl\n";
		std::cin >> choice;
		switch (choice)
		{
		case 'b':
			ac.Balance();
			break;
		case 'd':
			std::cout << "how much you want to deposit?\n";
			std::cin >> quantity;
			ac.Deposit(quantity);
			break;
		case 'w':
			std::cout << "how much do you want to withdrawl?\n";
			std::cin >> quantity;
			ac.Withdrawl(quantity);
			break;
		default:
			std::cout << "choose again\n";
		}
	}

	return 0;
}