#if !defined(APP)
#define APP

#include "Common.hpp"
#include "SceneManager.hpp"

class App
{
public:
	SDL_Window* window = NULL;
	SDL_Renderer *renderer = NULL;
	SceneManager sceneManager;
	SDL_Event event;

	float deltaTime = 0;
	float avgFPS = 0;

	void Setup(SDL_Window **window, SDL_Renderer **renderer);
};

#endif // APP
