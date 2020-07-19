#if !defined(GAME_SCENE)
#define GAME_SCENE

#include "Common.hpp"
#include "Scene.hpp"
#include "Button.hpp"

#include "Player.hpp"

class GameScene : public Scene {
	public:
		Player playerShip;
		SDL_FRect playerRect;
		SDL_Renderer *renderer;
		Button button;

				GameScene();
		void 	Initialize(SDL_Renderer *renderer);
		void 	Update(float deltaTime) override;
		void 	Draw(SDL_Renderer *renderer) override;

		void	SetEvent(SDL_Event *event);
		void	ReadEvent();
};

#endif // GAME_SCENE
