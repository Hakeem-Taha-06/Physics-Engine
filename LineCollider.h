#pragma once
#include "ColliderComponent.h"

class LineCollider : public ColliderComponent
{
public:
	LineCollider(float centerX, float centerY, float length, float angle);
private:
	float length;
	float angle;
};

