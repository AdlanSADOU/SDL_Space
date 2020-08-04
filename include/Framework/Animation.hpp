#if !defined(ANIMATION)
#define ANIMATION

#include "Timer.hpp"
#include "Sprite.hpp"

struct AnimationInfo
{
    SDL_Renderer *renderer;
    char *spriteSheetPath   = "";
    Vec2f position          = {0, 0};
    float playbackSpeed     = 0;
    float frameHeight       = 0;
    float frameWidth        = 0;
};

class Animation
{
public:
    Timer m_timer;
    Sprite m_spriteSheet;
    int m_x = 0;
    int m_y = 0;

private:
    AnimationInfo *m_info = NULL;

public:
    void Create(AnimationInfo *info);
    void Update(float deltaTime, Vec2f position);
    void Draw(SDL_Renderer *renderer, uint8_t debugFlag);
};
#endif // ANIMATION
