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

	float w1Time;
	std::thread t1([&w1Time, this]() {
		w1Time = work();
		});

	float w2Time;
	std::thread t2([&w2Time, this]() {
		w2Time = work();
		});

	float w5Time;
	std::thread t5([&w5Time, this]() {
		w5Time = work();
		});

	float w6Time;
	std::thread t6([&w6Time, this]() {
		w6Time = work();
		});

	float w7Time;
	std::thread t7([&w7Time, this]() {
		w7Time = work();
		});

	float w8Time;
	std::thread t8([&w8Time, this]() {
		w8Time = work();
		});

	float w9Time;
	std::thread t9([&w9Time, this]() {
		w9Time = work();
		});

	float w10Time;
	std::thread t10([&w10Time, this]() {
		w10Time = work();
		});

	float w3Time = work();
	float w4Time = work();


	t1.join();
	t2.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();

	auto frameEnd = Clock::now();

	auto frameTime = std::chrono::duration<double, std::milli>(frameEnd - frameStart).count();

	std::cout << "work1 time: " << w1Time << " ms\n";
	std::cout << "work2 time: " << w2Time << " ms\n";
	std::cout << "work3 time: " << w3Time << " ms\n";
	std::cout << "work4 time: " << w4Time << " ms\n";
	std::cout << "work5 time: " << w5Time << " ms\n";
	std::cout << "work6 time: " << w6Time << " ms\n";
	std::cout << "work7 time: " << w7Time << " ms\n";
	std::cout << "work8 time: " << w8Time << " ms\n";
	std::cout << "work9 time: " << w9Time << " ms\n";
	std::cout << "work10 time: " << w10Time << " ms\n";
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