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
        void        Update() override;
        void        Draw(SDL_Renderer *renderer) override;
        void        SetButton(SDL_Renderer *renderer, float x, float y, float width, float height);
        void        SetPosition(float x, float y) override;
        SDL_FRect   GetPosition();
        void        SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void        SetTexture(SDL_Renderer *renderer);

    private:
        SDL_Surface     *background_surface;
        SDL_FRect       background_rect;


};

#endif /* !BUTTON_HPP_ */
