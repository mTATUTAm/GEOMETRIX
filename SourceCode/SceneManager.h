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

    void ChangeScene(Scene* scene);       // �t�F�[�h�o�R�Ő؂�ւ�
    void ChangeNextScene(Scene* scene);   // �����؂�ւ�
    void Clear();

    static SceneManager* getInstance();   // �V���O���g��

private:
    Scene* currentScene;
    Scene* nextScene;
};
