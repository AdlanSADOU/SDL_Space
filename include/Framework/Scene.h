#if !defined(SCENE)
#define SCENE

#include "Common.h"
#include "Entity.h"

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
    virtual void Draw(SDL_Renderer *renderer) { 
        SDL_LogError(0, "lol this actually works !");
    };
};

#endif // SCENE
