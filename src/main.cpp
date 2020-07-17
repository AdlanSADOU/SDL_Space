#include "main.h"

#include "GameScene.h"
#include "SceneManager.h"

int main(int argc, char *args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer *renderer = NULL;
	SceneManager *sceneManager = NULL;
	
	setup(&window, &screenSurface, &renderer);

	GameScene gameScene;
	gameScene.Initialize(renderer);

	FramesLimiter FPS;
	FPS.SetFramerate(59);
	FPS.FramesTimerStart();
	
	while (Running) {

		FPS.UpdateCapTimer();
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			eventHandler(&event);
		}

		FPS.Start(&deltaTime);
		DebugGuiStart(deltaTime, FPS.GetFPS());

		SDL_SetRenderDrawColor(renderer, 10, 0, 0, 10);
		SDL_RenderClear(renderer);
		DebugGuiEnd();

		gameScene.Update(deltaTime);
		gameScene.Draw(renderer);

		SDL_RenderPresent(renderer);

		FPS.End();
	}

	DebugGuiDestroy();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}