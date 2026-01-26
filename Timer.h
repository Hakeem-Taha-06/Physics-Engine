#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	float tick();
private:
	using clock = std::chrono::steady_clock;
	clock::time_point last;
};

