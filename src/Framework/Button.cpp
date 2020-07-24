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

    this->background_surface_idle = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);

    SetColorIdle(255, 0, 0, 255);

    this->texture = SDL_CreateTextureFromSurface(renderer, this->background_surface_idle);
}

Button::Button(SDL_Renderer *renderer, float x, float y, float width, float height)
{
    this->background_rect.x = x;
    this->background_rect.y = y;
    this->background_rect.w = width;
    this->background_rect.h = height;

    this->renderer = renderer;

    this->background_surface_idle = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);
    this->background_surface_hover = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);
    this->background_surface_clicked = SDL_CreateRGBSurface(0, this->background_rect.w, this->background_rect.h, 32, 0, 0, 0, 0);

    SDL_FillRect(this->background_surface_idle, NULL, SDL_MapRGBA(this->background_surface_idle->format, 100, 100, 100, 255));
    SDL_FillRect(this->background_surface_hover, NULL, SDL_MapRGBA(this->background_surface_hover->format, 200, 200, 200, 255));
    SDL_FillRect(this->background_surface_clicked, NULL, SDL_MapRGBA(this->background_surface_clicked->format, 50, 50, 50, 255));

    UpdateTexture(this->background_surface_idle);
}

void Button::Draw()
{
    SDL_RenderCopyF(this->renderer, this->texture, NULL, &this->background_rect);
}

void Button::Update()
{
    UpdateHoverState();
    UpdateClickedState();
    UpdateColorFromState();
}

void Button::UpdateColorFromState()
{
    switch (this->state)
    {
        case HOVER :
            UpdateTexture(background_surface_hover);
            break;
        case CLICKED :
            UpdateTexture(background_surface_clicked);
            break;
        default:
            UpdateTexture(background_surface_idle);
            break;
    }
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

void Button::UpdateTexture(SDL_Surface *surface)
{
    this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
}

void Button::SetTexture(const char *path)
{
    this->background_surface_idle = IMG_Load(path);
    UpdateTexture(background_surface_idle);
}

void Button::SetColorIdle(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_FillRect(this->background_surface_idle, NULL, SDL_MapRGBA(this->background_surface_idle->format, r, g, b, a));
}

void Button::SetColorHover(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_FillRect(this->background_surface_hover, NULL, SDL_MapRGBA(this->background_surface_hover->format, r, g, b, a));
}

void Button::SetColorClicked(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_FillRect(this->background_surface_clicked, NULL, SDL_MapRGBA(this->background_surface_clicked->format, r, g, b, a));
}

void Button::SetState(buttonState state)
{
    this->state = state;
}

void Button::SetRenderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

void Button::SetEvent(SDL_Event *event)/* code */
{
    this->event = event;
}

void Button::UpdateHoverState()
{
    SDL_Point mousePos = {this->event->button.x, this->event->button.y};

    SDL_Rect buttonRect = {static_cast<int>(this->background_rect.x), static_cast<int>(this->background_rect.y), static_cast<int>(this->background_rect.w), static_cast<int>(this->background_rect.h)};

    if (SDL_PointInRect(&mousePos, &buttonRect))
        SetState(HOVER);
    else
        SetState(IDLE);
}

void Button::UpdateClickedState()
{
    SDL_Point mousePos = {this->event->button.x, this->event->button.y};

    SDL_Rect buttonRect = {static_cast<int>(this->background_rect.x), static_cast<int>(this->background_rect.y), static_cast<int>(this->background_rect.w), static_cast<int>(this->background_rect.h)};

    if (this->event->button.state == SDL_PRESSED && SDL_PointInRect(&mousePos, &buttonRect)) {
        SetState(CLICKED);
        if (this->event->button.type == SDL_MOUSEBUTTONUP)
            SetState(IDLE);
    }
}