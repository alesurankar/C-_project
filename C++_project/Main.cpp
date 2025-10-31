#include "MyClass.h"
#include "Calculator.h"
#include "NumGuess.h"
#include <iostream>

int main() {
	NumGuess num;
	num.Decide();
	bool correct = false;
	while (!correct)
	{
		std::cout << "Guess a number from 0 - 10\n";

		int x;
		std::cin >> x;

		std::cout << "you guessed: " << x << "\n";

		correct = num.Test(x);
		if (!correct)
		{
			std::cout << "guessed wrong number\n";
			if (x < num.GetNum())
			{
				std::cout << "to low\n";
			}
			else {
				std::cout << "to high\n";
			}
		}
		else 
		{
			std::cout << "nice, guessed correct number\n";
		}
	}
	return 0;
}