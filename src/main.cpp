#include "main.hpp"

int main(int argc, char *argv[])
{
	App app;

	app.Setup(&app.window, &app.renderer);
	DebugGuiInit(app.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	GameScene gameScene;
	gameScene.Initialize(app.renderer);

	app.sceneManager.AddScene(&gameScene, "GameScene");
	app.sceneManager.SetActiveScene(app.sceneManager.GetSceneByName("GameScene"));

	FramesLimiter FPS;
	FPS.SetFramerate(59);
	FPS.FramesTimerStart();

	while (app.Running) {

		FPS.UpdateCapTimer();
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			eventHandler(&event, &app);
		}

		FPS.Start(&app.deltaTime);
		DebugGuiStart(app.deltaTime, FPS.GetFPS());

		SDL_SetRenderDrawColor(app.renderer, 10, 0, 0, 10);
		SDL_RenderClear(app.renderer);
		DebugGuiEnd();

		app.sceneManager.UpdateActiveScene(app.deltaTime);
		app.sceneManager.DrawActiveScene(app.renderer);

		SDL_RenderPresent(app.renderer);

		FPS.End();
	}

	DebugGuiDestroy();
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();

	return 0;
}