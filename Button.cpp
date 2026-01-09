#include "Button.h"
#include <stdio.h>

Button::Button(float x, float y, float width, float height, const char* text) {
	this->rec = {x, y, width, height};
	this->text = text;
	this->func = nullptr;
}

Button::Button(float x, float y, float width, float height, const char* text, std::function<void()> func) {
	this->rec = { x, y, width, height };
	this->text = text;
	this->func = func;
}

void Button::setFunc(std::function<void()> func) {
	this->func = func;
}

void Button::trigger() {
	if (this->func != nullptr) {
		this->func();
		isTriggered = !isTriggered;
	}
}

void Button::draw() {
	DrawRectangleRec(rec, Color{ 255, 255, 255, 255 });
	float textPosX = rec.x + rec.width / 4;
	float textPosY = rec.y + rec.height / 4;
	DrawText(TextFormat("%s", text), textPosX, textPosY, 30, Color{ 0, 0, 0, 255 });
}

Rectangle Button::getRec() { return rec; }