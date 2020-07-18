#if !defined(SCENE)
#define SCENE

#include "Common.hpp"
#include "Entity.hpp"

class Scene
{
    std::vector<Entity *> entities;
public:
    String name;

public:
    void AddEntity(Entity *entity);
    void RemoveEntityByIndex(int idx);
    void RemoveEntityByName(char *name);

    Entity *GetEntityByIndex();
    Entity *GetEntityByName();
    
    virtual void Update(float deltaTime) {};
    virtual void Draw(SDL_Renderer *renderer) {};
};

#endif // SCENE
