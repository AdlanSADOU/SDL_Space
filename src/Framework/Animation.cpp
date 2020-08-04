#include "Animation.hpp"

void Animation::Create(AnimationInfo *info)
{
    int x = info->position.x;
    int y = info->position.y;
    m_info = info;
    m_spriteSheet.Create(info->spriteSheetPath, info->renderer, x, y);
}

#include "stdio.h"
void Animation::Update(float deltaTime, Vec2f position)
{
	m_timer.update();
    // printf("time: %d\n", m_timer.getElapsedTime());
}

Uint32 temp;
void Animation::Draw(SDL_Renderer *renderer, uint8_t debugFlag)
{
    Uint32 time = SDL_GetTicks() - temp;
    if (time > 33) {
        temp = SDL_GetTicks();
        printf("x: %d, Width: %f\n", m_x, m_spriteSheet.GetWidth());
        if (m_x/2 >= m_spriteSheet.GetWidth()) m_x = 0;
        if (m_y/2 >= m_spriteSheet.GetHeight()) m_y = 0;

        m_spriteSheet.SetSourceRectangle(m_x+= 2, m_y+=1, m_info->frameWidth, m_info->frameHeight);
    }
    m_spriteSheet.Draw(renderer, 1);
}
