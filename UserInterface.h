#pragma once
#include "Button.h"
#include <vector>

class UserInterface
{
public:
	UserInterface();
	void draw();
	void update(Vector2 mousePos, bool pressed);
	
private:
	void init();
	void handleMouseInput(Vector2 mousePos, bool pressed);
	std::vector<std::unique_ptr<Button>> buttons;
};

