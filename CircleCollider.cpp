#include "CircleCollider.h"


CircleCollider::CircleCollider(float x, float y,float radius) : ColliderComponent(x, y){
	this->radius = radius;
}

bool CircleCollider::checkCircleCollisions(ColliderComponent* collider) {
	float distance = Vector2Distance(this->position, collider->getPos());
	float minDist = this->radius + collider->getRadius();
	if (distance < minDist) {
		return true;
	}
	return false;
}

float CircleCollider::getRadius() { return radius; }
