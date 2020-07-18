#if !defined(MAIN)
#define MAIN

#include "Common.hpp"

#include "FramesLimiter.hpp"
#include "GameScene.hpp"
#include "SceneManager.hpp"

#include "mygui.hpp"

float deltaTime = 0;
float avgFPS = 0;

void setup(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		LogError("SDL initialisation", SDL_GetError(), __FILE__, __LINE__);
		return;
	}
	else {
		*window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*window == NULL) {
			LogError("Window initialisation", SDL_GetError(), __FILE__, __LINE__);
			return;
		}
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		LogError("Renderer initialisation", SDL_GetError(), __FILE__, __LINE__);
		SDL_assert(renderer);
		return;
	}
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

#endif // MAIN