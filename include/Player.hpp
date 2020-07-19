#if !defined(PLAYER)
#define PLAYER

#include "Common.hpp"

#include "Sprite.hpp"

class Player : public Entity {
protected:
	Sprite sprite;

public:
	float velocity;

public:
	void Create(const char *filepath, SDL_Renderer *renderer, SDL_FRect rect) {
		sprite.Create(filepath, renderer, rect);
	}

	void Draw(SDL_Renderer *renderer, Uint8 debugFlag) {
        if (!this->GetHideProperty()) {
            sprite.SetHideProperty(this->GetHideProperty());
		    sprite.Draw(renderer, debugFlag);
        }
	}

	void HandleMovement(float deltaTime) {
		const Uint8 *keystate;
		keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_RIGHT]) {
			sprite.Move(Vec2f{(this->velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_LEFT]) {
			sprite.Move(Vec2f{(-this->velocity * deltaTime), 0});
		}
		if (keystate[SDL_SCANCODE_UP]) {
			sprite.Move(Vec2f{0, (-this->velocity * deltaTime)});
		}
		if (keystate[SDL_SCANCODE_DOWN]) {
			sprite.Move(Vec2f{0, (this->velocity * deltaTime)});
		}
	}
};

#endif // PLAYER