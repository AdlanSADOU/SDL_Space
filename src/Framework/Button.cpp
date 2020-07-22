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

#include <iostream>

Button::Button()
{

}

Button::Button(SDL_Renderer *renderer)
{
    this->background_rect.x = 200;
    this->background_rect.y = 200;
    this->background_rect.w = 100;
    this->background_rect.h = 50;

    this->background_surface = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);

    SDL_FillRect(this->background_surface, NULL, SDL_MapRGBA(this->background_surface->format, 100, 100, 100, 255));
    this->texture = SDL_CreateTextureFromSurface(renderer, this->background_surface);
}

Button::Button(SDL_Renderer *renderer, float x, float y, float width, float height)
{
    this->background_rect.x = x;
    this->background_rect.y = y;
    this->background_rect.w = width;
    this->background_rect.h = height;

    this->renderer = renderer;

    this->background_surface = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);

    SDL_FillRect(this->background_surface, NULL, SDL_MapRGBA(this->background_surface->format, 100, 100, 100, 255));

    UpdateTexture();
}

void Button::Draw()
{
    SDL_RenderCopyF(this->renderer, this->texture, NULL, &this->background_rect);
}

void Button::Update()
{
    UpdateHoverState();
}

void Button::SetPosition(float x, float y)
{
    this->background_rect.x = x;
    this->background_rect.y = y;
}

SDL_FRect Button::GetPosition()
{
    return (background_rect);
}

void Button::UpdateTexture()
{
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->background_surface);
}

void Button::SetTexture(const char *path)
{
    this->background_surface = IMG_Load(path);
    UpdateTexture();
}

void Button::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_FillRect(this->background_surface, NULL, SDL_MapRGBA(this->background_surface->format, r, g, b, a));
    UpdateTexture();
}

void Button::SetRenderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

void Button::SetEvent(SDL_Event *event)
{
    this->event = event;
}

void Button::UpdateHoverState()
{
    SDL_Point mousePos = {this->event->button.x, this->event->button.y};

    SDL_Rect buttonRect = {this->background_rect.x, this->background_rect.y, this->background_rect.w, this->background_rect.h};

    if (this->event->button.clicks && SDL_PointInRect(&mousePos, &buttonRect)) {
        this->SetColor(0, 0, 255, 255);
        if (this->event->button.type == SDL_MOUSEBUTTONUP)
            this->SetColor(255, 0, 0, 255);
    }
    else

        this->SetColor(255, 0, 0, 255);
}