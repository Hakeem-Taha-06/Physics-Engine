#pragma once
#include "ColliderComponent.h"

enum EntityType {
	BallType,
	PlaneType
};

class Entity
{
public:
	
	Entity(float x,float y, float velocityX, float velocityY, float mass, Color color);
	virtual ~Entity() = default;
	virtual void collide(Entity* entity);
	virtual void update(float dt);
	virtual void draw();

	float getX();
	float getY();
	float getVelocityX();
	float getVelocityY();
	float getMass();
	Vector2 getPos();
	Vector2 getVelocity();
	ColliderComponent* getCollider();
	enum EntityType getType();

	void setVelocity(Vector2 newVelocity);
protected:

	virtual void handleWallCollisions();
	virtual void applySpeed(float dt);
	virtual void applyGravity(float dt);
	Vector2 position;
	Vector2 velocity;
	Color color;
	float mass;
	enum EntityType type;
	std::unique_ptr<ColliderComponent> collider;
};

