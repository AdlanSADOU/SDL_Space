/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Entity
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

void Entity::Create()
{
    this->surface = NULL;
    this->texture = NULL;
    this->src_rect = NULL;
}

void Entity::Update()
{

}

void Entity::Draw(SDL_Renderer *renderer)
{
    SDL_RenderCopyExF(renderer, this->texture, this->src_rect, &this->dest_rect, this->angle, &this->center, this->flip);
}

void Entity::SetPosition(float x, float y)
{
    this->dest_rect.x = x;
    this->dest_rect.y = y;
}

SDL_FRect Entity::GetPosition()
{
    return (dest_rect);
}

void Entity::SetAngle(double angle)
{
    this->angle = angle;
}

double Entity::GetAngle()
{
    return (this->angle);
}

void Entity::SetFlip(SDL_RendererFlip flip_type)
{
    this->flip = flip_type;
}

SDL_RendererFlip Entity::GetFlip()
{
    return (this->flip);
}

void Entity::SetCenter(SDL_FPoint center)
{
    this->center = center;
}

SDL_FPoint Entity::GetCenter()
{
    return (this->center);
}

void Entity::SetSourceRectangle(int x, int y, int width, int height)
{
    (*this->src_rect).x = x;
    (*this->src_rect).y = y;
    (*this->src_rect).w = width;
    (*this->src_rect).h = height;
}

SDL_Rect Entity::GetSourceRectangle()
{
    return ((*this->src_rect));
}

void Entity::SetDestinationRectangle(float x, float y, float width, float height)
{
    this->dest_rect.x = x;
    this->dest_rect.y = y;
    this->dest_rect.w = width;
    this->dest_rect.h = height;
}

SDL_FRect Entity::GetDestinationRectangle()
{
    return (this->dest_rect);
}

void Entity::SetHideProperty(bool hide)
{
    this->hidden = hide;
}

bool Entity::GetHideProperty()
{
    return (this->hidden);
}

void Entity::SetActiveProperty(bool active)
{
    this->active = active;
}

bool Entity::GetActiveProperty()
{
    return (this->active);
}