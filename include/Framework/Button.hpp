/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Entity.hpp"

typedef enum buttonState {
    IDLE,
    HOVER,
    CLICKED
} ;

class Button : public Entity {
    public:
                    Button();
                    Button(SDL_Renderer *renderer);
                    Button(SDL_Renderer *renderer, float x, float y, float width, float height);

        void        Update();
        void        Draw();

        void        SetPosition(float x, float y);
        SDL_FRect   GetPosition();

        void        SetColorIdle(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void        SetColorHover(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void        SetColorClicked(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void        SetTexture(const char *path);
        void        SetRenderer(SDL_Renderer *renderer);
        void        SetEvent(SDL_Event *event);
        void        SetState(buttonState state);

        void        UpdateTexture(SDL_Surface *surface);
        void        UpdateHoverState();
        void        UpdateClickedState();
        void        UpdateColorFromState();

    private:
        SDL_Surface     *background_surface_idle;
        SDL_Surface     *background_surface_hover;
        SDL_Surface     *background_surface_clicked;
        SDL_FRect       background_rect;
        SDL_Texture     *texture;
        SDL_Renderer    *renderer;
        buttonState     state;


        SDL_Event       *event;

};

#endif /* !BUTTON_HPP_ */
