#if !defined(MYGUI)
#define MYGUI

#include "imgui.h"
#include "imgui/imgui_sdl.h"
#include "SDL.h"

void DebugGuiInit(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void DebugGuiStart(float deltaTime, float avgFPS);
void DebugGuiEnd();
void DebugGuiDestroy();

void DebugGuiOverlay(bool* p_open, float deltaTime, float avgFPS);
#endif // MYGUI