#include "main.h"

void LogError(char *where, char *error, char *FILE, int LINE)
{
    SDL_LogError(0, " %s %s line: %d : %s\n", where, FILE, LINE, error);
}

int main(int argc, char *args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer *renderer = NULL;
	SceneManager sceneManager;

	setup(&window, &screenSurface, &renderer);

	GameScene gameScene;
	gameScene.Initialize(renderer);
	sceneManager.SetActiveScene(&gameScene);

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

		sceneManager.UpdateActiveScene(deltaTime);
		sceneManager.DrawActiveScene(renderer);

		SDL_RenderPresent(renderer);

		FPS.End();
	}

	DebugGuiDestroy();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}