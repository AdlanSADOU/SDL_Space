#if !defined(TIMER)
#define TIMER

#include "SDL.h"

struct Timer {
	void start() {
		mStarted = true;
		mPaused = false;

		mStartTicks = SDL_GetTicks();
		mPausedTicks = 0;
	}

	void stop() {
		mStarted = false;
		mPaused = false;
		mStartTicks = 0;
		mPausedTicks = 0;
	}

	void reset() {
		
	}

	void pause() {
		if (mStarted && mPaused) {
			mPaused = true;
			mPausedTicks = SDL_GetTicks() - mStartTicks;
			mStartTicks = 0;
		}
	}

	void resume() {
		if (mStarted && mPaused) {
			mPaused = false;
			mStartTicks = SDL_GetTicks() - mPausedTicks;
			mPausedTicks = 0;
		}
	}

	Uint32 getElapsedTime() {
		Uint32 time = 0;

		if (mStarted) {
			if (mPaused) {
				time = mPausedTicks;
			}
			else {
				time = SDL_GetTicks() - mStartTicks;
			}
		}
		return time;
	}

	void update() {
		deltaTime = this->getElapsedTime() * 0.001f;
	}

	bool isStarted() { return mStarted; };
	bool isPaused() { return mPaused; };
	float deltaTime = 0;
private:
	Uint32 mStartTicks = 0;
	Uint32 mPausedTicks = 0;

	bool mPaused = false;
	bool mStarted = false;
};

#endif // Timer