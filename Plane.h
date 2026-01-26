#pragma once
#include "Entity.h"
#include "LineCollider.h"

class Plane : public Entity
{
public:
	Plane(float centerX , float centerY, float length, float angle, float angularVelocity, Color color);
	void update(float dt) override;
	void draw() override;

private:
	float length;
	float angle;
	float angularVelocity;
};

