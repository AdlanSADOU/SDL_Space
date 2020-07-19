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

	void Initialize(SDL_Renderer *renderer)
	{
		this->name = "GameScene";
		renderer = renderer;
		playerRect = {SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84};
		playerShip.Create("assets/ship.png", renderer, playerRect);
		playerShip.velocity = 500;

		button = Button(renderer, 50, 200, 50, 20);
	}

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer *renderer) override;
};

void GameScene::Update(float deltaTime)
{
	playerShip.HandleMovement(deltaTime);
}

void GameScene::Draw(SDL_Renderer *renderer)
{
	playerShip.Draw(renderer, 1);
	button.Draw(renderer);

}
#endif // GAME_SCENE
