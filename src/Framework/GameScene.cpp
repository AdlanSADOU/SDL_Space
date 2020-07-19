#include "GameScene.hpp"

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
	ReadEvent();
	this->playerShip.HandleMovement(deltaTime);
	this->button.SetEvent(this->event);
	this->button.Update();
}

void GameScene::Draw(SDL_Renderer *renderer)
{
	this->playerShip.Draw(renderer, 1);
	this->button.Draw();
}

void GameScene::SetEvent(SDL_Event *event)
{
	this->event = event;
	button.SetEvent(event);
}

void GameScene::ReadEvent()
{

}