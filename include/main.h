#if !defined(MAIN)
#define MAIN

#include "Common.h"

#include "FramesLimiter.h"
#include "GameScene.h"
#include "SceneManager.h"

#include "mygui.h"

float deltaTime = 0;
float avgFPS = 0;

void setup(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		*window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
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