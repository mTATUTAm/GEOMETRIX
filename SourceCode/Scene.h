#pragma once
#include "all.h"

class Scene {
public:
    virtual ~Scene() {}

    virtual void Initialize() = 0;
    virtual void Finalize() = 0;
    virtual void Update(float elapsedTime) = 0;
    virtual void Render() = 0;

    // optional (�K�v�ɉ����ăI�[�o�[���C�h)
    virtual void Draw() {}
    virtual void CompositeScreen() {}
    virtual void DrawScene() {}
    virtual void DrawLight() {}
    virtual void DrawGlitch() {}
    virtual void DrawSandStorm() {}
    virtual void DrawScroll() {}
    virtual void DrawUI() {}
    virtual void DrawGUI() {}
};