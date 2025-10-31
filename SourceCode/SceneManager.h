#pragma once
#include "all.h"

class SceneManager {
public:
    SceneManager();
    ~SceneManager() {}

    void Update(float elapsedTime);
    void Render();
    void Draw();
    void CompositeScreen();
    void DrawScene();
    void DrawLight();
    void DrawGlitch();
    void DrawSandStorm();
    void DrawScroll();
    void DrawUI();
    void DrawGUI();

    void ChangeScene(Scene* scene);       // フェード経由で切り替え
    void ChangeNextScene(Scene* scene);   // 即時切り替え
    void Clear();

    static SceneManager* getInstance();   // シングルトン

private:
    Scene* currentScene;
    Scene* nextScene;
};
