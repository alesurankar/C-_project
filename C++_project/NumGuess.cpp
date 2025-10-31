#include "NumGuess.h"

NumGuess::NumGuess()
	:
	rng(rd()),
	rand(0, 10)
{}

void NumGuess::Decide()
{
	num = rand(rng);
}

bool NumGuess::Test(int input)
{
	if (input == num)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
