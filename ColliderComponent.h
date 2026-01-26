#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>


enum ColliderType {
	Circle,
	Line
};

class ColliderComponent
{
public:
	ColliderComponent();
	ColliderComponent(float x, float y);
	virtual ~ColliderComponent() = default;
	virtual bool checkCollisions(ColliderComponent* collider);
	virtual Vector2 getPos();
	virtual void setPos(Vector2 pos);
	virtual float getRadius();
	enum ColliderType getType();
protected:
	Vector2 position;
	enum ColliderType type;
};

