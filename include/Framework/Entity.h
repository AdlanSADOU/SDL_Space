#if !defined(ENTITY)
#define ENTITY

#include "Common.h"
#include "Sprite.h"

class Scene;

class Entity : public Sprite
{
public:
	std::string name;
	// void Create(Scene *scene, char *name) {
	// 	this->name = name;
	// }

	// DEPRECATED
 	float velocity = 0;
	void Move(Vec2f vector);
};

#endif // ENTITY