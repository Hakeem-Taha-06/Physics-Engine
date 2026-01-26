#include "Ball.h"

Ball::Ball(float x, float y, 
            float velocityX, float velocityY, 
            float mass, float radius, 
            Color color) : Entity(x, y, velocityX, velocityY, mass, color){

    this->radius = radius;
    collider = std::make_unique<CircleCollider>(x, y, radius);
}

void Ball::update(float dt) {
    applyGravity(dt);
    applySpeed(dt);
    handleWallCollisions();
    this->getCollider()->setPos(position);
}

void Ball::draw() {
    DrawCircle(position.x, position.y, radius, color);
    //Debug velocity line visualization
    Vector2 lineEnd = Vector2Add(position, Vector2Scale(velocity, 0.02));
    DrawLineEx(position, lineEnd, 15, Color{ 255, 0, 0, 128 });
}

//should be in the physics handler
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