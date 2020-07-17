#if !defined(GAME_SCENE)
#define GAME_SCENE

#include "Common.h"
#include "Scene.h"

class GameScene : public Scene
{
public:
    Entity playerShip;
	SDL_FRect playerRect;

	void Initialize(SDL_Renderer *renderer)
	{
		this->name = "GameScene";
		playerRect = {SCREEN_WIDTH * 0.5f - 128 / 2, SCREEN_HEIGHT * 0.7, 84, 84};
		playerShip.Create(renderer, "assets/ship.png", playerRect);
		playerShip.velocity = 500;
	}

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer *renderer) override;
};

	void HandlePlayerMovement(Entity *player, float deltaTime)
	{
		const Uint8 *keystate;
		keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_RIGHT])
		{
			player->Move(Vec2f{(player->velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_LEFT])
		{
			player->Move(Vec2f{(-player->velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_UP])
		{
			player->Move(Vec2f{0, (-player->velocity * deltaTime)});
		}
		if (keystate[SDL_SCANCODE_DOWN])
		{
			player->Move(Vec2f{0, (player->velocity * deltaTime)});
		}
	}

void GameScene::Update(float deltaTime)
{
	HandlePlayerMovement(&playerShip, deltaTime);
}

void GameScene::Draw(SDL_Renderer *renderer)
{
	Scene::Draw(renderer);
	playerShip.Draw(renderer, 1);
}
#endif // GAME_SCENE
