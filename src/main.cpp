#include "utils.h"
#include "Entity.h"
#include "timer.h"

int main(int argc, char* args[])
{
	setup();

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	Sprite* background = create_sprite(renderer, "assets/background.jpg", SDL_FRect{0,0, SCREEN_WIDTH, SCREEN_HEIGHT});
	
	Entity *playerShip = new Entity(renderer, "assets/ship.png", SDL_FRect{ SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84 });
	playerShip->velocity = 500;

	Timer fps;
	Timer capTimer;

	fps.start();
	int frames = 0;

	while (Running) {
		capTimer.start();
		SDL_Event event;
		const Uint8* keystate;

		while (SDL_PollEvent(&event)) {
			eventHandler(&event);
		}

		float avgFPS = frames / (fps.getElapsedTime() / 1000.0f);
		if (avgFPS > 2000000)
			avgFPS = 0;
		float deltaTime = (1 / avgFPS);
		SDL_Log("dt: %f\nFPS: %f", deltaTime, avgFPS);

		keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_RIGHT]) {
			playerShip->Move(Vec2f{ (playerShip->velocity * deltaTime), 0 });
		}
		if (keystate[SDL_SCANCODE_LEFT]) {
			playerShip->Move(Vec2f{ (-playerShip->velocity * deltaTime), 0 });
		}
		if (keystate[SDL_SCANCODE_UP]) {
			playerShip->Move(Vec2f{ 0, (-playerShip->velocity * deltaTime)});
		}
		if (keystate[SDL_SCANCODE_DOWN]) {
			playerShip->Move(Vec2f{ 0, (playerShip->velocity * deltaTime) });
		}

		SDL_RenderClear(renderer);

		background->draw(renderer);
		playerShip->Draw(renderer, 1);
		
		SDL_RenderPresent(renderer);

		frames++;
		int frameTicks = capTimer.getElapsedTime();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);	
	}

	SDL_free(background);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}