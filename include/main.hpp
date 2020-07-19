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

void eventHandler(SDL_Event* event, App *app)
{

}

#endif // MAIN