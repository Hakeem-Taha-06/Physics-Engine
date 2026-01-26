#pragma once
#include "ColliderComponent.h"

class Entity
{
public:
	
	Entity(float x,float y, float velocityX, float velocityY, float mass, Color color);
	virtual ~Entity() = default;
	float getX();
	float getY();
	float getVelocityX();
	float getVelocityY();
	Vector2 getPos();
	Vector2 getVelocity();
	ColliderComponent* getCollider();
	virtual void collide(Vector2 normal);
	virtual void update(float dt);
	virtual void draw();
protected:

	virtual void handleWallCollisions();
	virtual void applySpeed(float dt);
	virtual void applyGravity(float dt);
	Vector2 position;
	Vector2 velocity;
	Color color;
	float mass;
	std::unique_ptr<ColliderComponent> collider;
};

