#if !defined(COMMON)
#define COMMON

#include <cstdlib>
#include <string>
#include <vector>
#include <map>

#include <stdio.h>

#include "SDL.h"
#include "SDL_image.h"

#include "imgui/imgui.h"

typedef std::string String;

const Uint32 SCREEN_WIDTH = 800;
const Uint32 SCREEN_HEIGHT = 600;
const Uint32 SCREEN_FPS = 60;
const Uint32 SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

static bool Running = true;

#endif // COMMON
