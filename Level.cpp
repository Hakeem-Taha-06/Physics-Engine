#include "Level.h"
#include "Ball.h"
#include "Plane.h"
#include <string.h>

Level::Level(std::string levelName) {
	if (levelName.empty()) {
		this->entities.emplace_back(std::make_unique<Ball>(100, 100, 600, 600, 10, 10, WHITE));
		this->entities.emplace_back(std::make_unique<Ball>(200, 100, 600, -1200, 20, 20, RED));
		this->entities.emplace_back(std::make_unique<Ball>(screenWidth-100, 100, -800, 500, 60, 60, BLUE));
		this->entities.emplace_back(std::make_unique<Ball>(screenWidth-400, 100, -800, -1800, 100, 100, BLACK));
		this->entities.emplace_back(std::make_unique<Plane>(300, 400, 600, 45, 200, WHITE));
	}
	else {
		std::cout << "level loaded from 'levels\\" << levelName << "'" << std::endl;
	}
}

void Level::update(float dt) {
	
	physics.update(entities, dt);
	for(auto& entity : entities){
		entity->update(dt);
	}
	
}

void Level::draw() {
	for (auto& entity : entities) {
		entity->draw();
	}
}
