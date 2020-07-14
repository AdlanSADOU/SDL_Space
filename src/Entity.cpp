#include "Entity.h"

void Entity::Move(Vec2f vector)
{
    this->rect.x += vector.x;
    this->rect.y += vector.y;
}

