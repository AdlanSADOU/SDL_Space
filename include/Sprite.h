#if !defined(SPRITE)
#define SPRITE

#include "SDL.h"
#include "SDL_image.h"

#include "vector.h"

class Sprite
{
	// TODO suggestion: maybe generate a unique id for entities
public:
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	SDL_RendererFlip flip = {SDL_FLIP_NONE};
	SDL_FRect rect = SDL_FRect{0, 0, 128, 128};

	float velocity = 0;
	float angle = 0;

private:
	int result = 0;

public:
	void Create(SDL_Renderer *renderer, const char *filepath, SDL_FRect rect);
	void Draw(SDL_Renderer *renderer, Uint8 debugFlag);
	void SetPositionF(float x, float y);
	void SetPosition(int x, int y);
  
};

#endif // SPRITE
