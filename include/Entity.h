#pragma once
#include "Sprite.h"

class Entity : public Sprite
{
public:
	// TODO suggestion: maybe generate a unique id for entities

 	float velocity = 0;
	void Move(Vec2f vector);
};
