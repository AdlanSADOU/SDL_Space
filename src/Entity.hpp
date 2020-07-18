/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <../include/vector.h>

class Entity {
	public:
		virtual void 		Create();
		virtual void 		Update();
		virtual void   		Draw(SDL_Renderer *renderer);

		virtual void 		SetPosition(float x, float y);
		virtual SDL_FRect	GetPosition();

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

		void 				SetHideProperty(bool hide);
		bool				GetHideProperty();

		void				SetActiveProperty(bool active);
		bool 				GetActiveProperty();

	protected:
		SDL_Surface 		*surface;
		SDL_Texture 		*texture;

		SDL_Rect 			*src_rect;
		SDL_FRect			dest_rect;

		double 				angle;
		SDL_FPoint 			center;
		SDL_RendererFlip	flip;

		bool 				hidden;
		bool 				active;

	private:

};

#endif /* !ENTITY_HPP_ */
