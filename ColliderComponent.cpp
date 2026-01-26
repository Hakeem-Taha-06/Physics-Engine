#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(){
	this->position = { 0,0 };
}

ColliderComponent::ColliderComponent(float x, float y) {
	this->position = { x, y };
}

bool ColliderComponent::checkCollisions(ColliderComponent* collider) { return false; };

Vector2 ColliderComponent::getPos() { return position; }

void ColliderComponent::setPos(Vector2 pos) { this->position = pos; }

float ColliderComponent::getRadius() { return 0.0f; }

enum ColliderType ColliderComponent::getType() { return this->type; }
