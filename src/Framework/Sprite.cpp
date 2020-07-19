/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Sprite
*/

#include "Sprite.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include "vector.hpp"

void Sprite::Create(const char *path, SDL_Renderer *renderer, SDL_FRect rect)
{
    this->rect = rect;

    if (!renderer || !path) {
        SDL_LogError(0, "ERROR: %s\n%s at line: %d ", SDL_GetError(), __FILE__, __LINE__);
        return;
    }

    if (!(this->surface = IMG_Load(path))) {
        SDL_LogError(0, "Could not load: %s\n%s", path, SDL_GetError());
        return;
    }

    if (!(this->texture = SDL_CreateTextureFromSurface(renderer, this->surface))) {
        SDL_LogError(0, "Unnable to create texture from surface: %s", SDL_GetError());
        return;
    }
}

void Sprite::Update(float deltaTime)
{

}

void Sprite::SetTexture(const char *path, SDL_Renderer *renderer)
{
   if (!(this->surface = IMG_Load(path))) {
        SDL_LogError(0, "Could not load: %s\n%s", path, SDL_GetError());
    }

    if (!(this->texture = SDL_CreateTextureFromSurface(renderer, this->surface))) {
        SDL_LogError(0, "Unnable to create texture from surface: %s", SDL_GetError());
    }
    
    SDL_FreeSurface(this->surface);
}

SDL_Texture *Sprite::GetTexture()
{
    return (this->texture);
}

void Sprite::Draw(SDL_Renderer *renderer, Uint8 debugFlag)
{
    // SDL_RenderCopyExF(renderer, this->texture, nullptr, &this->rect, this->angle, &this->center, this->flip);
if (!this->is_hidden) {
        int result = SDL_RenderCopyExF(renderer, this->texture, NULL, &this->rect, this->angle, NULL, this->flip);
        if (result < 0)
            SDL_LogError(0, "ERROR: %s\n", SDL_GetError());
        if (debugFlag) {
            SDL_SetRenderDrawColor(renderer, 180, 20, 20, 255);
            SDL_RenderDrawRectF(renderer, &this->rect);
        }
    }
}

void Sprite::SetPosition(float x, float y)
{
    this->rect.x = x;
    this->rect.y = y;
}

void Sprite::Move(Vec2f vec)
{
    this->rect.x += vec.x;
    this->rect.y += vec.y;
}

SDL_FRect Sprite::GetPosition()
{
    return (rect);
}

void Sprite::SetAngle(double angle)
{
    this->angle = angle;
}

double Sprite::GetAngle()
{
    return (this->angle);
}

void Sprite::SetFlip(SDL_RendererFlip flip_type)
{
    this->flip = flip_type;
}

SDL_RendererFlip Sprite::GetFlip()
{
    return (this->flip);
}

void Sprite::SetCenter(SDL_FPoint center)
{
    this->center = center;
}

SDL_FPoint Sprite::GetCenter()
{
    return (this->center);
}

void Sprite::SetSourceRectangle(int x, int y, int width, int height)
{
    (this->src_rect).x = x;
    (this->src_rect).y = y;
    (this->src_rect).w = width;
    (this->src_rect).h = height;
}

SDL_Rect Sprite::GetSourceRectangle()
{
    return ((this->src_rect));
}

void Sprite::SetDestinationRectangle(float x, float y, float width, float height)
{
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = width;
    this->rect.h = height;
}

SDL_FRect Sprite::GetDestinationRectangle()
{
    return (this->rect);
}
