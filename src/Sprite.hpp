/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "Entity.hpp"

class Sprite : public Entity {
    public:
        void            SetTexture(const char *path, SDL_Renderer *renderer);
        SDL_Texture     *GetTexture();

    private:
};

#endif /* !SPRITE_HPP_ */
