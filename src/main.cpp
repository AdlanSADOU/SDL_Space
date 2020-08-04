#include "main.hpp"

#include <cmath>

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
            app.SetEvent(&event);
            app.ReadEvent();
        }

        FPS.Start(&app.deltaTime);
        DebugGuiStart(app.deltaTime, FPS.GetFPS());

        SDL_SetRenderDrawColor(app.renderer, 10, 0, 0, 10);
        SDL_RenderClear(app.renderer);
        DebugGuiEnd();

        app.sceneManager.UpdateActiveScene(app.deltaTime);
        app.sceneManager.DrawActiveScene(app.renderer);

        SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

        int radius = 70;
        int orig_x = 400;
        int orig_y = 200;

        for (int x = -radius; x < radius ; x++) {
            int hh = (int)std::sqrt(radius - x * x);
            int rx = orig_x + x;
            int ph = orig_y + hh;

            for (int y = orig_y - hh; y < ph; y++)
                SDL_RenderDrawPoint(gameScene.renderer, rx, y);
        }
        radius = 25;
        SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
        for (int x = -radius; x < radius ; x++) {
            int hh = (int)std::sqrt(radius - x * x);
            int rx = orig_x + x;
            int ph = orig_y + hh;

            for (int y = orig_y - hh; y < ph; y++)
                SDL_RenderDrawPoint(gameScene.renderer, rx, y);
        }

        SDL_RenderPresent(app.renderer);

        FPS.End();
    }

    DebugGuiDestroy();
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();

    return 0;
}