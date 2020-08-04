#include "App.hpp"

void App::Setup()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_LogError(0, "SDL_Init initialisation : %s %d : %s", __FILE__, __LINE__, SDL_GetError());
		return;
	}
	else {
		window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			SDL_LogError(0, "Window initialisation : %s %d : %s", __FILE__, __LINE__, SDL_GetError());
			return;
		}
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		SDL_LogError(0, "Renderer initialisation : %s %d : %s", __FILE__, __LINE__, SDL_GetError());
		SDL_assert(renderer);
		return;
	}
}

void App::SetEvent(SDL_Event *event)
{
	this->event = event;
	sceneManager.SetEvent(event);
}

void App::ReadEvent()
{
	switch ((*event).type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.sym == SDLK_ESCAPE)
			Running = false;
		break;
	case SDL_QUIT:
		Running = false;
	default:
		break;
	}

	sceneManager.ReadEvent();
}