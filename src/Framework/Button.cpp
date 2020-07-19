/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Button
*/

#include "Button.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

void Button::Draw(SDL_Renderer *renderer)
{
    SDL_RenderCopyF(renderer, this->texture, NULL, &this->background_rect);
}

void Button::Update()
{

}

Button::Button(SDL_Renderer *renderer, float x, float y, float width, float height)
{
    this->background_rect.x = x;
    this->background_rect.y = y;
    this->background_rect.w = width;
    this->background_rect.h = height;

    this->background_surface = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);

    SDL_FillRect(this->background_surface, NULL, SDL_MapRGBA(this->background_surface->format, 100, 100, 100, 255));
    this->texture = SDL_CreateTextureFromSurface(renderer, this->background_surface);
}

void Button::SetPosition(float x, float y)
{
    this->background_rect.x = x;
    this->background_rect.y = y;
}

void Button::SetTexture(SDL_Renderer *renderer, const char *path)
{
    this->background_surface = IMG_Load(path);
    this->texture = SDL_CreateTextureFromSurface(renderer, this->background_surface);
}

SDL_FRect Button::GetPosition()
{
    return (background_rect);
}

void Button::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_FillRect(this->background_surface, NULL, SDL_MapRGBA(this->background_surface->format, r, g, b, a));
}