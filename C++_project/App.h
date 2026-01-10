#pragma once
#include <atomic>
#include "FrameTimer.h"

class App 
{
public:
	App(std::atomic<bool>& running_in);
	void Go();
private:
	int i = 0;
	std::atomic<bool>& running;
	FrameTimer ft;
};