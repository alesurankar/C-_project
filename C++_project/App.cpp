#include "App.h"
#include <iostream>


using Clock = std::chrono::high_resolution_clock;

App::App(std::atomic<bool>& running_in)
	:
	running(running_in)
{}

void heavyWork()
{
	volatile double x = 0;
	for (int i = 0; i < 20'000'000; ++i)
		x += std::sin(i);
}

void App::Go()
{
	auto frameStart = Clock::now();

	if (i >= 5) {
		running = false;
		unsigned int nCores = std::thread::hardware_concurrency();
		std::cout << "CPU cores: " << nCores << "\n";
		
	}
	std::cout << "number: " << i << "\n";

	for (int i = 0; i < threadsNum; i++) {
		threads.emplace_back([this]() {
			float time = work();
			std::lock_guard<std::mutex> lock(mtx);
			results.emplace_back(time);
			});
	}

	float w1Time = work();
	float w2Time = work();

	for (auto& t : threads) {
		t.join();
	}

	auto frameEnd = Clock::now();

	auto frameTime = std::chrono::duration<double, std::milli>(frameEnd - frameStart).count();


	std::cout << "work1: " << w1Time << " ms\n";
	std::cout << "work2: " << w2Time << " ms\n";
	for (int i = 0; i < results.size(); i++) {
		std::cout << "work" << i + 3 << ": " << results[i] << " ms\n";
	}

	std::cout << "total cycle time: " << frameTime << " ms\n\n";
	float allTimes = 0;
	for (auto& t : times) {
		allTimes += t;
	}
	std::cout << "total work time: " << allTimes << "\n";

	std::cout << "\n";
	threads.clear();
	results.clear();
	i++;
}

float App::work()
{
	auto start = Clock::now();
	heavyWork();
	auto endWork = Clock::now();

	auto time = std::chrono::duration<float, std::milli>(endWork - start).count();
	writeTime(time);
	auto end = Clock::now();
	return std::chrono::duration<float, std::milli>(end - start).count();
}

void App::writeTime(float time)
{
	std::lock_guard<std::mutex> lock(mtx);
	times.emplace_back(time);
}