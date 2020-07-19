#if !defined(SCENE)
#define SCENE

#include "Common.hpp"
#include "Entity.hpp"

class Scene
{
    public:
        std::vector<Entity *> entities;
        String name;
        SDL_Event *event;

        void            AddEntity(Entity *entity);
        void            RemoveEntityByIndex(int idx);
        void            RemoveEntityByName(char *name);

        Entity          *GetEntityByIndex();
        Entity          *GetEntityByName();

        virtual void    Update(float deltaTime);
        virtual void    Draw(SDL_Renderer *renderer);

        void            SetEvent(SDL_Event *event);
        void            ReadEvent();
};

#endif // SCENE