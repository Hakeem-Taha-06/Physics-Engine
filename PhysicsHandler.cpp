#include "PhysicsHandler.h"

void PhysicsHandler::update(std::vector<std::unique_ptr<Entity>>& entities, long long dt) {
	
	for (auto& entityA : entities) {
		bool isCollided = false;
		ColliderComponent* colliderA = entityA->getCollider();
		for (auto& entityB : entities) {
			if (entityA != entityB) {
				ColliderComponent* colliderB = entityB->getCollider();
				isCollided = colliderA->checkCollisions(colliderB);
			}
			if(isCollided){
				entityA->collide(entityB.get());
			}
		}
	}
};
