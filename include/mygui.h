#pragma once
#include "imgui.h"
#include "imgui/imgui_sdl.h"
#include "SDL.h"

void DebugGuiOverlay(bool* p_open, float deltaTime, float avgFPS);
void DebugGuiStart(float deltaTime, float avgFPS);
void DebugGuiEnd();