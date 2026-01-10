#include "App.h"
#include <iostream>


using Clock = std::chrono::high_resolution_clock;

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
	auto frameStart = Clock::now();

	if (i >= 5) {
		running = false;
	}
	std::cout << "number: " << i << "\n";

	float w2Time;
	float w4Time;
	std::thread t1([&w2Time, this]() {
		w2Time = work();
		});
	std::thread t2([&w4Time, this]() {
		w4Time = work();
		});
	float w1Time = work();
	float w3Time = work();

	t1.join();
	t2.join();

	auto frameEnd = Clock::now();

	auto frameTime = std::chrono::duration<double, std::milli>(frameEnd - frameStart).count();

	std::cout << "work1 time: " << w1Time << " ms\n";
	std::cout << "work2 time: " << w2Time << " ms\n";
	std::cout << "work2 time: " << w3Time << " ms\n";
	std::cout << "work2 time: " << w4Time << " ms\n";
	std::cout << "total cycle time: " << frameTime << " ms\n\n";

	std::cout << "\n";
	i++;
}

float App::work()
{
	auto start = Clock::now();
	heavyWork();
	auto end = Clock::now();

	return std::chrono::duration<float, std::milli>(end - start).count();
}