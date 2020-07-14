#include "main.h"
#include "Entity.h"
#include "timer.h"

#include "mygui.h"

int main(int argc, char *args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer *renderer = NULL;

	setup(&window, &screenSurface, &renderer);

	Entity playerShip;
	playerShip.Create(renderer, "assets/ship.png", SDL_FRect{SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84});
	playerShip.velocity = 500;

	Timer fps;
	Timer capTimer;
	bool *p_open = NULL;

	fps.start();
	int frames = 0;

	while (Running)
	{
		capTimer.start();
		SDL_Event event;
		const Uint8 *keystate;

		while (SDL_PollEvent(&event))
		{
			eventHandler(&event);
		}

		avgFPS = frames / (fps.getElapsedTime() / 1000.0f);
		if (avgFPS > 2000000)
			avgFPS = 0;
		deltaTime = (1 / avgFPS);

		keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_RIGHT])
		{
			playerShip.Move(Vec2f{(playerShip.velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_LEFT])
		{
			playerShip.Move(Vec2f{(-playerShip.velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_UP])
		{
			playerShip.Move(Vec2f{0, (-playerShip.velocity * deltaTime)});
		}
		if (keystate[SDL_SCANCODE_DOWN])
		{
			playerShip.Move(Vec2f{0, (playerShip.velocity * deltaTime)});
		}

		ImGui::NewFrame();
		ShowExampleAppSimpleOverlay(p_open, avgFPS, deltaTime);

		SDL_SetRenderDrawColor(renderer, 10, 0, 0, 10);
		SDL_RenderClear(renderer);

		ImGui::Render();
		ImGuiSDL::Render(ImGui::GetDrawData());

		playerShip.Draw(renderer, 1);

		SDL_RenderPresent(renderer);

		frames++;
		Uint32 frameTicks = capTimer.getElapsedTime();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}