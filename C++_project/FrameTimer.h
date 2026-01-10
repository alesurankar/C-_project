#pragma once
#include <chrono>


class FrameTimer
{
public:
	FrameTimer() {
		last = std::chrono::steady_clock::now();
	}
	float Mark() {
		std::chrono::steady_clock::time_point old = last;
		last = std::chrono::steady_clock::now();
		const std::chrono::duration<float>frameTime = last - old;
		return frameTime.count();
	}
public:
	std::chrono::steady_clock::time_point last;
};