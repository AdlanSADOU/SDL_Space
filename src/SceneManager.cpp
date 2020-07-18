#include "SceneManager.hpp"

void SceneManager::AddScene(Scene *scene, String name)
{
    this->scenes.Scenes.push_back(scene);
    this->scenes.Names.push_back(name);
}

void SceneManager::SetActiveScene(Scene *scene)
{
    if (!scene) {
        LogError("in SetActiveScene() :", "scene is nullptr", __FILE__, __LINE__);
        return;
    }
    this->activeScene = scene;
}

void SceneManager::SetBackgroundScene(Scene *scene)
{
    if (!scene) {
        LogError("in SetBackgroundScene() :", "scene is nullptr", __FILE__, __LINE__);
        return;
    }
    this->backgroundScene = scene;
}

void SceneManager::RemoveSceneByName(char* name)
{
    if (!name) {
        LogError("in RemoveSceneByName() :", "name is nullptr", __FILE__, __LINE__);
        return;
    }

    for (int i = 0; scenes.Names.size(); i++) {
        if (scenes.Names[i].compare(name) == 0) {
            scenes.Names[i] = nullptr;
            scenes.Scenes[i] = nullptr;
            break;
        }
    }
    this->scenes.Scenes.shrink_to_fit();
    this->scenes.Names.shrink_to_fit();
}

void SceneManager::RemoveSceneByIndex(int idx)
{
    this->scenes.Scenes.at(idx) = nullptr;
    this->scenes.Names.at(idx) = nullptr;

    this->scenes.Scenes.shrink_to_fit();
    this->scenes.Names.shrink_to_fit();
}

Scene *SceneManager::GetSceneByName(char *name)
{
    if (!name) {
        LogError("in GetSceneByName() :", "name is nullptr", __FILE__, __LINE__);
        return nullptr;
    }

    for (int i = 0; scenes.Names.size(); i++) {
        if (scenes.Names[i].compare(name) == 0) {
            return scenes.Scenes[i];
        }
    }
    return nullptr;
}

Scene *SceneManager::GetSceneByIndex(int idx)
{
        if (scenes.Scenes[idx]) {
            return scenes.Scenes[idx];
        }
    return nullptr;
}

Scene *SceneManager::GetActiveScene()
{
    if (this->activeScene) {
        return this->activeScene;
    }
    return nullptr;
}

const char *SceneManager::GetActiveSceneName()
{
    if (this->activeScene && this->activeScene->name.c_str()) {
        return this->activeScene->name.c_str();
    }
    return nullptr;
}

int SceneManager::GetActiveSceneIndex()
{
    for (int i = 0; scenes.Scenes.size(); i++) {
        if (scenes.Scenes[i] == this->activeScene) {
            return i;
        }
    }
    return -1;
}

Scene *SceneManager::GetBackgroundScene()
{
    if (this->backgroundScene) {
        return this->backgroundScene;
    }
    return nullptr;
}

const char *SceneManager::GetBackgroundSceneName()
{
    if (this->backgroundScene && this->backgroundScene->name.c_str()) {
        return this->backgroundScene->name.c_str();
    }
    return nullptr;
}

int SceneManager::GetBackgroundSceneIndex()
{
    for (int i = 0; scenes.Scenes.size(); i++) {
        if (scenes.Scenes[i] == this->backgroundScene) {
            return i;
        }
    }
    return -1;
}

void SceneManager::UpdateActiveScene(float deltaTime)
{
    if (this->activeScene) {
        this->activeScene->Update(deltaTime);
    }
}

void SceneManager::DrawActiveScene(SDL_Renderer *renderer)
{
    if (this->activeScene) {
    this->activeScene->Draw(renderer);
    }
}