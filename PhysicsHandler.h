#pragma once
#include "CircleCollider.h"
#include "Entity.h"
#include <vector>

class PhysicsHandler

{
public:
	void update(std::vector<std::unique_ptr<Entity>>& entities, long long dt);
};

