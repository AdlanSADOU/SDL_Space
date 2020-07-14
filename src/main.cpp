#include "main.h"

int main(int argc, char *args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer *renderer = NULL;

	setup(&window, &screenSurface, &renderer);

	Entity playerShip;
	playerShip.Create(renderer, "assets/ship.png", SDL_FRect{SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84});
	playerShip.velocity = 500;

	bool *p_open = NULL;

	FramesLimiter FPS;
	FPS.SetFramerate(10);
	FPS.FramesTimerStart();
	
	while (Running)
	{
		FPS.UpdateCapTimer();
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			eventHandler(&event);
		}

		HandlePlayerMovement(&playerShip, deltaTime);

		FPS.Start(&deltaTime);

		ImGui::NewFrame();
		ShowExampleAppSimpleOverlay(p_open, deltaTime, FPS.GetFPS());

		SDL_SetRenderDrawColor(renderer, 10, 0, 0, 10);
		SDL_RenderClear(renderer);

		ImGui::Render();
		ImGuiSDL::Render(ImGui::GetDrawData());

		playerShip.Draw(renderer, 1);

		SDL_RenderPresent(renderer);

		FPS.End();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}