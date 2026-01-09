#pragma once
#include "iostream"
#include <raylib.h>
#include <raymath.h>

class ColliderComponent
{
public:
	ColliderComponent();
	ColliderComponent(float x, float y);
	virtual ~ColliderComponent() = default;
	virtual bool checkCircleCollisions(ColliderComponent* collider);
	virtual Vector2 getPos();
	virtual void setPos(Vector2 pos);
	virtual float getRadius();
protected:
	Vector2 position;
};

