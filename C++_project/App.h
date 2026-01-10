#pragma once
#include <atomic>
#include "FrameTimer.h"
#include <thread>
#include <vector>
#include <mutex>

class App 
{
public:
	App(std::atomic<bool>& running_in);
	void Go();
	float work();
	void writeTime(float time);
private:
	int i = 0;
	int threadsNum = 10;
	std::atomic<bool>& running;
	std::vector<float> times;
	std::vector<std::thread> threads;
	std::vector<float> results;
	std::mutex mtx;
};