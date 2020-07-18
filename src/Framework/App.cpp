#include "App.hpp"

void App::Setup(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		LogError("SDL initialisation", SDL_GetError(), __FILE__, __LINE__);
		return;
	}
	else {
		*window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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