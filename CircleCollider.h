#pragma once
#include "ColliderComponent.h"

class CircleCollider : public ColliderComponent
{
public:
	CircleCollider(float x, float y, float radius);
	bool checkCircleCollisions(ColliderComponent* collider) override;
	float getRadius();
private:
	float radius;
};

