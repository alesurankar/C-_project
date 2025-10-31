#pragma once
#include <random>

class NumGuess {
public:
	NumGuess();
	void Decide();
	bool Test(int input);
	int GetNum();
private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> rand;
	int num;
};