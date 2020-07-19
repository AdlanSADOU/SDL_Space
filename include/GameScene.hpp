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
};

GameScene::GameScene()
{

}

void GameScene::Initialize(SDL_Renderer *renderer)
{
	this->name = "GameScene";
	this->renderer = renderer;
	this->playerRect = {SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84};
	this->playerShip.Create("assets/ship.png", renderer, playerRect);
	this->playerShip.velocity = 500;

	this->button = Button(renderer, 50, 200, 50, 20);
	this->button.SetColor(240, 0, 0, 255);
}

void GameScene::Update(float deltaTime)
{
	this->playerShip.HandleMovement(deltaTime);
}

void GameScene::Draw(SDL_Renderer *renderer)
{
	this->playerShip.Draw(renderer, 1);
	this->button.Draw();

}
#endif // GAME_SCENE
