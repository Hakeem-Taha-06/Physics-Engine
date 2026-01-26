#include "Entity.h"
#include "globals.h"
#include <iostream>


Entity::Entity(float x, float y, float velocityX, float velocityY, float mass, Color color) : collider(nullptr) {
    this->position = { x, y };
    this->velocity = {velocityX, velocityY};
    this->mass = mass;
    this->color = color;
}

void Entity::update(long long dt) {
    
}

void Entity::applySpeed() {
    position.x += velocity.x;
    position.y += velocity.y;
}

void Entity::applyGravity() {
    velocity.y += 1;
}

void Entity::handleWallCollisions() {
 
}

void Entity::collide(Vector2 normal) {
    Vector2 newVelocity = Vector2Subtract(
        velocity,
        Vector2Scale(normal, 2*Vector2DotProduct(velocity, normal)));
    velocity = Vector2Scale(newVelocity, 0.9);
}

void Entity::draw() {
	DrawCircle(position.x, position.y, 30, Color{ 255, 255, 255, 255 });
    //Debug velocity line visualization
    Vector2 lineEnd = Vector2Add(position, Vector2Scale(velocity, 5));
    DrawLineEx(position, lineEnd, 15, Color{ 255, 0, 0, 128 });
    /*Vector2 v1 = Vector2Add(lineEnd, Vector2Subtract(lineEnd, position));
    Vector2 v2 = Vector2Subtract(v1, lineEnd);
    Vector2 v3 = Vector2Rotate(Vector2Subtract(v1, lineEnd), 90);;
    DrawTriangle(v1, v2, v3, Color{ 255, 0, 0, 128 });*/
}

float Entity::getX() { return position.x; }
float Entity::getY() { return position.y; }
float Entity::getVelocityX() { return velocity.x; }
float Entity::getVelocityY() { return velocity.y; }
Vector2 Entity::getPos() { return position; }
Vector2 Entity::getVelocity() { return velocity; }
ColliderComponent* Entity::getCollider() { return collider.get(); }