#pragma once
#include "includes.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

static bool Running = true;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

struct Sprite {
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	SDL_FRect rect = SDL_FRect{0, 0, 128, 128};
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	float angle = 0;

	float vel = 100.f;
private:
	int result = 0;

public:
	// !!! Not implemented
	void set_size() {
		
	}

	void set_position(float x, float y) {
		this->rect.x = x;
		this->rect.y = y;
	}

	void draw(SDL_Renderer* renderer) {
		//SDL_BlitSurface(this->surface, NULL, screenSurface, &this->rect);
		//SDL_RenderCopy(renderer, this->texture, NULL, &this->rect);

		this->result = SDL_RenderCopyExF(renderer, this->texture, NULL, &this->rect, this->angle, NULL, this->flip);
		if (result < 0)
			SDL_LogError(0, SDL_GetError());
	}
};

void debug_message(const char* msg, SDL_Window* window)
{
	SDL_ShowSimpleMessageBox(0, "DEBUG", msg, window);
}

SDL_Keycode getPressedKey(SDL_KeyboardEvent key)
{
	return key.keysym.sym;
}

void eventHandler(SDL_Event* event)
{
	switch ((*event).type)
	{
	case SDL_KEYDOWN:
		if (getPressedKey((*event).key) == SDLK_ESCAPE)
			Running = false;
		break;
	case SDL_QUIT:
		Running = false;
	default:
		break;
	}
}

void setup()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
		}
	}
}

Sprite *create_sprite(SDL_Renderer* renderer, const char* filepath, SDL_FRect rect)
{
	Sprite *sprite = (Sprite*)SDL_malloc(sizeof(Sprite));
	sprite->surface = NULL;
	sprite->rect = rect;
	if (!(sprite->surface = IMG_Load(filepath))) {
		debug_message("Cound not find sprite", window);
	}
	if (!(sprite->texture = SDL_CreateTextureFromSurface(renderer, sprite->surface)))
		debug_message("Could not create texture from surface", window);

	return sprite;
}