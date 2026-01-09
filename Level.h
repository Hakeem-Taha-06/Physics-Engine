#pragma once
#include "UserInterface.h"
#include "PhysicsHandler.h"
#include <iostream>
#include <vector>

class Level
{
public:
	Level(std::string levelName);
	void update();
	void draw();
private:
	std::vector<std::unique_ptr<Entity>> entities;
	PhysicsHandler physics;
};

