#if !defined(MAIN)
#define MAIN

#include "App.hpp"
#include "FramesLimiter.hpp"
#include "mygui.hpp"

#include "GameScene.hpp"

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