#if !defined(SENE_MANAGER)
#define SENE_MANAGER

#include "Common.hpp"
#include "Scene.hpp"

struct Scenes
{
    std::vector<Scene *> Scenes;
    std::vector<String> Names;
};

class SceneManager
{
    // std::map<Scene *, String> Scenes;
    Scenes scenes;
    Scene *activeScene = nullptr;
    Scene *backgroundScene = nullptr;

public:
    void AddScene(Scene *scene, String name);
    void SetActiveScene(Scene *activeScene);
    void SetBackgroundScene(Scene *backgroundScene);
    void RemoveSceneByName(const char *name);
    void RemoveSceneByIndex(int idx);

    Scene *GetSceneByName(const char *name);
    Scene *GetSceneByIndex(int idx);

    Scene *GetActiveScene();
    const char *GetActiveSceneName();
    int GetActiveSceneIndex();

    Scene *GetBackgroundScene();
    const char *GetBackgroundSceneName();
    int GetBackgroundSceneIndex();

    void UpdateActiveScene(float deltaTime);
    void DrawActiveScene(SDL_Renderer *renderer);
};

#endif // SENE_MANAGER
