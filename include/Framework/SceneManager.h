#if !defined(SENE_MANAGER)
#define SENE_MANAGER

#include "Common.h"
#include "Scene.h"

class SceneManager
{
    std::map<Scene *, String> Scenes;
    Scene *activeScene;
    Scene *backgroundScene;
    
public:
    void AddScene(Scene *scene, String name);
    void RemoveSceneByIndex(int idx);
    void RemoveSceneByName(char *name);
    void SetActiveScene(Scene *activeScene);
    void SetBackgroundScene(Scene *backgroundScene);

    Scene *GetSceneByName(char *name);
    Scene *GetSceneByIndex(int idx);
    Scene *GetActiveScene();
    Scene *GetBackgroundScene();

    char *GetActiveSceneIndex();
    int GetActiveSceneName();

    char *GetBackgroundSceneIndex();
    int GetBackgroundSceneName();
};

#endif // SENE_MANAGER
