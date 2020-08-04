#if !defined(ANIMATION)
#define ANIMATION

#include "Timer.hpp"

struct AnimationInfo
{
    char *spriteSheetPath   = "";
    float playbackSpeed     = 0;
    float frameHeight       = 0;
    float frameWidth        = 0;
};

class Animation {

private:
    Timer timer;

public:
    void Create();
    void Update(float deltaTime);
};

void Animation::Create()
{

}

void Animation::Update(float deltaTime)
{

}

#endif // ANIMATION
