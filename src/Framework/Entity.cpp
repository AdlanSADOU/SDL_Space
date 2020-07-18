#include "Entity.hpp"

void Entity::Move(Vec2f vector)
{
    this->rect.x += vector.x;
    this->rect.y += vector.y;
}

