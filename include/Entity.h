#pragma once
#include "includes.h"

class Entity
{
	// TODO suggestion: maybe generate a unique id for entities
public:
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	SDL_FRect rect = SDL_FRect{ 0, 0, 128, 128 };
	SDL_RendererFlip flip = { SDL_FLIP_NONE };
	float angle = 0;
	int result = 0;
	float velocity = 0;

	Entity(SDL_Renderer* renderer, const char* filepath, SDL_FRect rect) {
		this->rect = rect;
		if (!(this->surface = IMG_Load(filepath))) {
			SDL_LogError(0, "Could not load: %s\n%s", filepath, SDL_GetError());
		}
		else {
			if (!(this->texture = SDL_CreateTextureFromSurface(renderer, this->surface))) {
				SDL_LogError(0, "Unnable to create texture from surface: %s", SDL_GetError());
			}
		}
	}
	
	void Draw(SDL_Renderer* renderer, Uint8 debugFlag) {
		this->result = SDL_RenderCopyExF(renderer, this->texture, NULL, &this->rect, this->angle, NULL, this->flip);
		if (result < 0)
			SDL_LogError(0, SDL_GetError());
		if (debugFlag) {
			SDL_SetRenderDrawColor(renderer, 180, 20, 20, 255);
			SDL_RenderDrawRectF(renderer, &this->rect);
		}
	}

	void SetPositionF(float x, float y) {
		this->rect.x = x;
		this->rect.y = y;
	}

	void SetPosition(int x, int y) {
		this->rect.x = (int)x;
		this->rect.y = (int)y;
	}

	void Move(Vec2f vector) {
		this->rect.x += vector.x;
		this->rect.y += vector.y;
	}
};

