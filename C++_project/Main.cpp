#include "MyClass.h"
#include "Calculator.h"
#include "NumGuess.h"
#include <iostream>
#include <vector>

int main() {
	std::string task;
	std::vector<std::string> tasks;
	while (true)
	{

		std::cout << "add an task\n";
		std::cin >> task;

		std::cout << "added task: " << task << "\n";


		tasks.emplace_back(task);

		for (const std::string& tsk : tasks)
		{
			std::cout << "tasks: " << tsk << "\n";
		}
	}
	return 0;
}