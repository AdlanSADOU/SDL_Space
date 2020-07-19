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
		void 				Create(const char *path, SDL_Renderer *renderer, SDL_FRect rect);
		virtual void 		Update(float deltaTime);
		virtual void   		Draw(SDL_Renderer *renderer, Uint8 debugFlag);

        void            	SetTexture(const char *path, SDL_Renderer *renderer);
        SDL_Texture     	*GetTexture();

		void 				Move(Vec2f vec);
		void 				SetPosition(float x, float y);
		SDL_FRect			GetPosition();

		void				SetAngle(double angle);
		double 				GetAngle();

		void				SetFlip(SDL_RendererFlip flip_type);
		SDL_RendererFlip 	GetFlip();

		void				SetCenter(SDL_FPoint center);
		SDL_FPoint 			GetCenter();

		void 				SetSourceRectangle(int x, int y, int width, int height);
		SDL_Rect			GetSourceRectangle();

		void 				SetDestinationRectangle(float x, float y, float width, float height);
		//Same function as GetPosition()
		SDL_FRect 			GetDestinationRectangle();

	public:
		SDL_Surface 		*surface = NULL;
		SDL_Texture 		*texture = NULL;
		
		SDL_Rect			src_rect;
		SDL_FRect			rect;
		
		double 				angle = 0;
		SDL_FPoint 			center;
		SDL_RendererFlip flip = {SDL_FLIP_NONE};

		bool 				is_hidden = 0;
};

#endif /* !SPRITE_HPP_ */
