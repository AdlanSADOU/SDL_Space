#pragma once

#include <cstdlib>
#include <vector>
#include <string>

#include "includes.h"
#include "Entity.h"
#include "FramesLimiter.h"

#include "mygui.h"

const Uint32 SCREEN_WIDTH = 800;
const Uint32 SCREEN_HEIGHT = 600;
const Uint32 SCREEN_FPS = 60;
const Uint32 SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

static bool Running = true;

float deltaTime = 0;
float avgFPS = 0;

void setup(SDL_Window **window, SDL_Surface **screenSurface, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		*window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
		if (*window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

	ImGui::CreateContext();
	ImGuiSDL::Initialize(*renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

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

void HandlePlayerMovement(Entity *player, float deltaTime)
{
		const Uint8 *keystate;
		keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_RIGHT])
		{
			player->Move(Vec2f{(player->velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_LEFT])
		{
			player->Move(Vec2f{(-player->velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_UP])
		{
			player->Move(Vec2f{0, (-player->velocity * deltaTime)});
		}
		if (keystate[SDL_SCANCODE_DOWN])
		{
			player->Move(Vec2f{0, (player->velocity * deltaTime)});
		}
}