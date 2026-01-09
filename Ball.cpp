#include "Ball.h"

Ball::Ball(float x, float y, float velocityX, float velocityY, float mass, float radius) : Entity(x, y, velocityX, velocityY, mass){
    this->radius = radius;
    collider = std::make_unique<CircleCollider>(x, y, radius);
}

void Ball::draw() {
    DrawCircle(position.x, position.y, radius, Color{ 255, 255, 255, 255 });
    //Debug velocity line visualization
    Vector2 lineEnd = Vector2Add(position, Vector2Scale(velocity, 5));
    DrawLineEx(position, lineEnd, 15, Color{ 255, 0, 0, 128 });
}

void Ball::handleWallCollisions() {
    if (position.x + radius >= screenWidth)
    {
        velocity.x = -(velocity.x) * 0.9;
        position.x = screenWidth - radius;
    }
    if (position.x - radius <= 0)
    {
        velocity.x = -(velocity.x) * 0.9;
        position.x = radius;
    }

    if (position.y + radius >= screenHeight)
    {
        velocity.y = -(velocity.y) * 0.9;
        position.y = screenHeight - radius;
    }
    if (position.y - radius <= 0)
    {
        velocity.y = -(velocity.y) * 0.9;
        position.y = radius;
    }
}

float Ball::getRadius() { return radius; }