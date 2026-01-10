#pragma once
#include <atomic>
#include "FrameTimer.h"
#include <thread>

class App 
{
public:
	App(std::atomic<bool>& running_in);
	void Go();
	float work();
private:
	int i = 0;
	std::atomic<bool>& running;
};