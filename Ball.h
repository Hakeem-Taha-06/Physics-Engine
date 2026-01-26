#pragma once
#include "Entity.h"
#include "CircleCollider.h"
#include "globals.h"

class Ball : public Entity
{
public:
	Ball(float x, float y, float velocityX, float velocityY, float mass, float radius, Color color);
	void draw() override;
	void update(float dt) override;
	void handleWallCollisions() override;
	float getRadius();
private:
	float radius;
};

