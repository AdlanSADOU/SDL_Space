#if !defined(SCENE)
#define SCENE

#include "Common.h"
#include "Entity.h"

class Scene
{
    std::vector<Entity *> entities;

public:
    void AddEntity(Entity *entity);
    void RemoveEntityByIndex(int idx);
    void RemoveEntityByName(char *name);

    Entity *GetEntityByIndex();
    Entity *GetEntityByName();
    
};

#endif // SCENE
