#pragma once
#include "functional"
#include "iostream"
#include "raylib.h"
class Button
{
public:
	Button(float x, float y, float width, float height, const char* text);
	Button(float x, float y, float width, float height, const char* text, std::function<void()> func);
	void setFunc(std::function<void()> func);
	void draw();
	void trigger();
	Rectangle getRec();
private:
	std::function<void()> func;
	Rectangle rec;
	const char* text;
	bool isTriggered = false;
};

