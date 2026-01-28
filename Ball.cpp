#include "Ball.h"

Ball::Ball(float x, float y, 
            float velocityX, float velocityY, 
            float mass, float radius, 
            Color color) : Entity(x, y, velocityX, velocityY, mass, color){

    this->radius = radius;
    this->type = BallType;
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
    DrawText(TextFormat("(%f, %f)", velocity.x, velocity.y), position.x, position.y, 20, WHITE);
}

void Ball::collide(Entity* entity) {
    switch (entity->getCollider()->getType()) {
    case Circle:
        std::cout << "_________________________________________" << std::endl;
        std::cout << "BALL1: " << radius << std::endl;
        std::cout << "BALL2: " << entity->getCollider()->getRadius() << std::endl;
        
        Vector2 n = Vector2Subtract(entity->getPos(), position);
        Vector2 un = Vector2Normalize(n);
        Vector2 ut{ -un.y, un.x };

        std::cout << "NORMAL: " << "(" << un.x << ", " << un.y << ")" << std::endl;

        Vector2 v1 = velocity;
        Vector2 v2 = entity->getVelocity();
        float m1 = mass;
        float m2 = entity->getMass();

        std::cout << "Starting v1: " << "(" << v1.x << ", " << v1.y << ")" << std::endl;
        std::cout << "Starting v2: " << "(" << v2.x << ", " << v2.y << ")" << std::endl;

        float v1n = Vector2DotProduct(v1, un);
        float v1t = Vector2DotProduct(v1, ut);
        float v2n = Vector2DotProduct(v2, un);
        float v2t = Vector2DotProduct(v2, ut);

        float final_v1t = v1t;
        float final_v2t = v2t;

        float final_v1n = (v1n * (m1 - m2) + 2 * m2 * v2n) / (m1 + m2);
        float final_v2n = (v2n * (m2 - m1) + 2 * m1 * v1n) / (m1 + m2);

        Vector2 final_v1 = Vector2Add(Vector2Scale(un, final_v1n),
                                      Vector2Scale(ut, final_v1t));
        Vector2 final_v2 = Vector2Add(Vector2Scale(un, final_v2n),
                                      Vector2Scale(ut, final_v2t));

        
        std::cout << "Final v1: " << "(" << final_v1.x << ", " << final_v1.y << ")" << std::endl;
        std::cout << "Final v2: " << "(" << final_v2.x << ", " << final_v2.y << ")" << std::endl;
        std::cout << "_________________________________________" << std::endl;
        
        setPos(Vector2Subtract(entity->getPos(), Vector2Scale(un, getRadius() + entity->getCollider()->getRadius())));
        setVelocity(final_v1);
        entity->setVelocity(final_v2);
    }
    
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