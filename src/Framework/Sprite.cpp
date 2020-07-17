#include "Sprite.h"

void Sprite::Create(SDL_Renderer *renderer, const char *filepath, SDL_FRect rect)
{
    if (!renderer || !filepath) {
        SDL_LogError(0, "ERROR: %s\n%s at line: %d ", SDL_GetError(), __FILE__, __LINE__);
    }
    this->rect = rect;
    if (!(this->surface = IMG_Load(filepath))) {
        SDL_LogError(0, "Could not load: %s\n%s", filepath, SDL_GetError());
    }
    else {
        if (!(this->texture = SDL_CreateTextureFromSurface(renderer, this->surface))) {
            SDL_LogError(0, "Unnable to create texture from surface: %s", SDL_GetError());
        }
    }
}

void Sprite::Draw(SDL_Renderer *renderer, Uint8 debugFlag)
{
    this->result = SDL_RenderCopyExF(renderer, this->texture, NULL, &this->rect, this->angle, NULL, this->flip);
    if (result < 0)
        SDL_LogError(0, "ERROR: %s\n", SDL_GetError());
    if (debugFlag) {
        SDL_SetRenderDrawColor(renderer, 180, 20, 20, 255);
        SDL_RenderDrawRectF(renderer, &this->rect);
    }
}

void Sprite::SetPositionF(float x, float y)
{
    this->rect.x = x;
    this->rect.y = y;
}

void Sprite::SetPosition(int x, int y)
{
    this->rect.x = (int)x;
    this->rect.y = (int)y;
}

// void Sprite::Move(Vec2f vector)
// {
//     this->rect.x += vector.x;
//     this->rect.y += vector.y;
// }