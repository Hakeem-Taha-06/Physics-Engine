#include "Level.h"
#include "Ball.h"
#include "Plane.h"
#include <string.h>

Level::Level(std::string levelName) {
	if (levelName.empty()) {
		this->entities.emplace_back(std::make_unique<Ball>(100, 100, 600, 600, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(200, 100, 600, -1200, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(screenWidth-100, 100, -800, 500, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(screenWidth-200, 100, -800, -1800, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Plane>(300, 400, 600, 45, 200, WHITE));
	}
	else {
		std::cout << "level loaded from 'levels\\" << levelName << "'" << std::endl;
	}
}

void Level::update(float dt) {
	
	for(auto& entity : entities){
		entity->update(dt);
	}
	physics.update(entities, dt);
}

void Level::draw() {
	for (auto& entity : entities) {
		entity->draw();
	}
}
