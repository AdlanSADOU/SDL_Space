#if !defined(MACRO)
#define MACRO

#include "timer.h"

class FramesLimiter
{
private:
    Timer fps;
	Timer capTimer;
	int frames = 0;

    Uint32 screenFPS = 60;
    Uint32 SCREEN_TICKS_PER_FRAME = 1000 / screenFPS;

public:

    float avgFPS = 0;

    void SetFramerate(Uint32 framerate);
    float GetFPS();

    void FramesTimerStart();
    void UpdateCapTimer();
    void Start(float *deltaTime);
    void End();

};

void FramesLimiter::SetFramerate(Uint32 framerate)
{
    screenFPS = framerate;
    SCREEN_TICKS_PER_FRAME = 1000 / screenFPS;
}

float FramesLimiter::GetFPS()
{
    return avgFPS;
}

void FramesLimiter::FramesTimerStart()
{
	fps.start();
}

void FramesLimiter::UpdateCapTimer()
{
    capTimer.start();
}

void FramesLimiter::Start(float *deltaTime)
{
    avgFPS = frames / (fps.getElapsedTime() / 1000.0f);
		if (avgFPS > 2000000)
			avgFPS = 0;
		*deltaTime = (1 / avgFPS);
}

void FramesLimiter::End()
{
    frames++;
		Uint32 frameTicks = capTimer.getElapsedTime();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
}

#endif // MACRO
