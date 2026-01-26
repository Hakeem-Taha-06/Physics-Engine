#include "LineCollider.h"

LineCollider::LineCollider(float x, float y, float length, float angle) : ColliderComponent(x, y){
	this->length = length;
	this->angle = angle;
	this->type = Line;
}

