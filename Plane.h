#pragma once
#include "Entity.h"
#include "LineCollider.h"

class Plane : public Entity
{
public:
	Plane(float centerX , float centerY, float length, float angle, Color color);
	void update(long long dt) override;
	void draw() override;

private:
	float length;
	float angle;
};

