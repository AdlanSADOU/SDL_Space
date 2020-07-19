/*
** EPITECH PROJECT, 2020
** SDL_Space
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SDL.h>
#include <SDL_image.h>

#include <vector.hpp>

class Entity {
	public:

		void SetHideProperty(bool hide);
		bool GetHideProperty();

		void SetActiveProperty(bool active);
		bool GetActiveProperty();

	protected:
		bool is_hidden = 0;
		bool is_active = 1;
};

#endif /* !ENTITY_HPP_ */
