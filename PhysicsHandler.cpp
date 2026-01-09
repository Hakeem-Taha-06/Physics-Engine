#include "PhysicsHandler.h"

void PhysicsHandler::update(std::vector<std::unique_ptr<Entity>>& entities) {
	bool isCollided = false;
	
	for (auto& entityA : entities) {
		ColliderComponent* colliderA = entityA->getCollider();
		for (auto& entityB : entities) {
			if (entityA != entityB) {
				ColliderComponent* colliderB = entityB->getCollider();
				isCollided = colliderA->checkCircleCollisions(colliderB);
			}
			if(isCollided){
				Vector2 normal = Vector2Normalize(Vector2Subtract(entityA->getPos(), entityB->getPos()));
				entityA->collide(normal);
			}
		}
	}
};
