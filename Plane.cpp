#include "Plane.h"
#include "globals.h"

Plane::Plane(float centerX, float centerY,
			float length, float angle, float angularVelocity, Color color) : Entity(centerX, centerY, 0, 0, 0, color){
	this->length = length;
	this->angle = angle;
	this->angularVelocity = angularVelocity;
	this->type = PlaneType;
	this->collider = std::make_unique<LineCollider>(centerX, centerY, length, angle);
}

void Plane::update(float dt) {
	angle += angularVelocity*dt;
}

void Plane::draw() {
	float startX = position.x - (length/2)*std::cos(angle * DEG2RAD);
	float startY = position.y + (length/2)*std::sin(angle * DEG2RAD);
	float endX = position.x + (length/2)*std::cos(angle * DEG2RAD);
	float endY = position.y - (length/2)*std::sin(angle * DEG2RAD);
	Vector2 startPos = Vector2{ startX, startY };
	Vector2 endPos = Vector2{ endX, endY };
	DrawLineEx(startPos, endPos, 10, color);

	//debug circle at center and endPos
	DrawCircleV(position, 5, Color{ 255, 0, 0, 124 });
	DrawCircleV(endPos - Vector2Normalize(endPos - position)*5, 5, Color{255, 0, 0, 124});
}