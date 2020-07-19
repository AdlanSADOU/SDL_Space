/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Entity
*/

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

bool Entity::GetHideProperty()
{
    return (this->is_hidden);
}

void Entity::SetActiveProperty(bool is_active)
{
    this->is_active = is_active;
}

bool Entity::GetActiveProperty()
{
    return (this->is_active);
}

void Entity::SetHideProperty(bool hide)
{
    this->is_hidden = hide;
}