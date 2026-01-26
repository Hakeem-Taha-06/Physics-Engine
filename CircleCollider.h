#pragma once
#include "ColliderComponent.h"

class CircleCollider : public ColliderComponent
{
public:
	CircleCollider(float x, float y, float radius);
	bool checkCollisions(ColliderComponent* collider) override;
	float getRadius();
private:
	float radius;
};

