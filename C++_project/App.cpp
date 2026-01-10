#include "App.h"
#include <iostream>

App::App(std::atomic<bool>& running_in)
	:
	running(running_in)
{
}

void heavyWork()
{
	volatile double x = 0;
	for (int i = 0; i < 50'000'000; ++i)
		x += std::sin(i);
}

void App::Go()
{
	float dt = ft.Mark();
	if (i >= 5) {
		running = false;
	}
	//heavyWork();
	std::cout << "number: " << i << "\n";
	if (i > 0) {
		std::cout << "cycle time: " << dt << "\n";
	}
	std::cout << "\n";
	i++;
}
