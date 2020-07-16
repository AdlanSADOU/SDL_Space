#include "main.h"

class Test : public Entity
{
public:
	std::string name = "none";
	void testfunc() {
		ImGui::Text(name.c_str());
		printf(name.c_str());
	}
	
};

int main(int argc, char *args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer *renderer = NULL;

	setup(&window, &screenSurface, &renderer);

	Test test;
	Test test2;

	test.name = "first";
	test2.name = "second";

	std::vector<Entity *> entities;
	entities.push_back(static_cast<Entity *>(&test));
	entities.push_back(static_cast<Entity *>(&test2));
	
	Entity playerShip;
	SDL_FRect playerRect = {SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84};
	playerShip.Create(renderer, "assets/ship.png", playerRect);
	playerShip.velocity = 500;

	FramesLimiter FPS;
	FPS.SetFramerate(59);
	FPS.FramesTimerStart();
	
	while (Running) {

		FPS.UpdateCapTimer();
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			eventHandler(&event);
		}

		HandlePlayerMovement(&playerShip, deltaTime);
		FPS.Start(&deltaTime);
		DebugGuiStart(deltaTime, FPS.GetFPS());

		static_cast<Test *>(entities[0])->testfunc();
		static_cast<Test *>(entities[1])->testfunc();

		SDL_SetRenderDrawColor(renderer, 10, 0, 0, 10);
		SDL_RenderClear(renderer);
		DebugGuiEnd();

		playerShip.Draw(renderer, 1);

		SDL_RenderPresent(renderer);

		FPS.End();
	}

	DebugGuiDestroy();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}