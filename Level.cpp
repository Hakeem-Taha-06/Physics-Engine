#include "Level.h"
#include "Ball.h"
#include "Plane.h"
#include <string.h>

Level::Level(std::string levelName) {
	if (levelName.empty()) {
		this->entities.emplace_back(std::make_unique<Ball>(100, 100, 6, 6, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(200, 100, 6, -12, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(screenWidth-100, 100, -8, 5, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(screenWidth-200, 100, -8, -18, 1, 30, WHITE));
		this->entities.emplace_back(std::make_unique<Plane>(300, 400, 600, 45, WHITE));
	}
	else {
		std::cout << "level loaded from 'levels\\" << levelName << "'" << std::endl;
	}
}

void Level::update(long long dt) {
	
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
