/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Entity.hpp"

class Button : public Entity {
    public:
                    Button();
                    Button(SDL_Renderer *renderer);
                    Button(SDL_Renderer *renderer, float x, float y, float width, float height);
        void        Update();
        void        Draw();
        void        SetPosition(float x, float y);
        SDL_FRect   GetPosition();
        void        SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void        SetTexture(const char *path);
        void        SetRenderer(SDL_Renderer *renderer);
        void        SetEvent(SDL_Event *event);
        void        UpdateTexture();
        void        UpdateHoverState();

    private:
        SDL_Surface     *background_surface;
        SDL_FRect       background_rect;
        SDL_Texture     *texture;
        SDL_Renderer    *renderer;

        SDL_Event       *event;

};

#endif /* !BUTTON_HPP_ */
