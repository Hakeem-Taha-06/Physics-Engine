#include "Timer.h"

Timer::Timer() {

}

float Timer::tick() {
	clock::time_point now = clock::now();
	std::chrono::duration<float> dt = now - last;
	last = now;
	
	return std::min(dt.count(), 0.1f);
}