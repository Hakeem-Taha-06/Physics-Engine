#include "CircleCollider.h"

CircleCollider::CircleCollider(float x, float y,float radius) : ColliderComponent(x, y){
	this->radius = radius;
	this->type = Circle;
}

bool CircleCollider::checkCollisions(ColliderComponent* collider) {
	
	switch (collider->getType()) {
		case Circle:
		{
			float distance = Vector2Distance(this->position, collider->getPos());
			float minDist = this->radius + collider->getRadius();
			if (distance < minDist) {
				return true;
			}
			break;
		}
		case Line:
			return false;
			break;
	}
	
	return false;
}

float CircleCollider::getRadius() { return radius; }
