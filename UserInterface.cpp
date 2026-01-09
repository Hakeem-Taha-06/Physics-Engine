#include "UserInterface.h"
#include "globals.h"
#include <iostream>

UserInterface::UserInterface() {
	init();
}

void UserInterface::draw() {
	for (std::unique_ptr<Button>& button: buttons) {
		button->draw();
	}
	DrawText(TextFormat("simulation speed : %i", simSpeed), 200, 200, 40, Color{ 255,255,255,255 });
}

void UserInterface::update(Vector2 mousePos, bool pressed) {
	handleMouseInput(mousePos, pressed);
}

void UserInterface::handleMouseInput(Vector2 mousePos, bool pressed) {
	for (std::unique_ptr<Button>& button : buttons) {
		if (CheckCollisionPointRec(mousePos, button->getRec()) && pressed) {
			button->trigger();
		}
	}
}

void stop() {
	running = !running;
	std::cout << "Stopping simulation..." << std::endl;
}

void speedUp() {
	simSpeed++;
}

void speedDown() {
	simSpeed--;
}


void UserInterface::init() {
	buttons.emplace_back(std::make_unique<Button>(1000, 100, 150, 50, "stop", stop));
	buttons.emplace_back(std::make_unique<Button>(1010, 160, 60, 50, "<<", speedDown));
	buttons.emplace_back(std::make_unique<Button>(1080, 160, 60, 50, ">>", speedUp));
	
}
