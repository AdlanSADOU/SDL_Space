/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Sprite
*/

#include "Sprite.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void Sprite::SetTexture(const char *path, SDL_Renderer *renderer)
{
    this->surface = IMG_Load(path);
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(this->surface);
}

SDL_Texture *Sprite::GetTexture()
{
    return (this->texture);
}