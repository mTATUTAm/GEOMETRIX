#include "all.h"

void SceneTitle::Initialize() {
    titleSprite = sprite_load(L"Data/Texture/title.png");
}

void SceneTitle::Finalize() {
	delete titleSprite;
    music::stop();

}

void SceneTitle::Update(float elapsedTime) {
    SceneManager::getInstance()->ChangeScene(new SceneGame());
}

void SceneTitle::Render() {
	// �^�C�g���X�v���C�g��`��
    sprite_render
        (titleSprite,
     0.0f, 0.0f, 1.0f, 1.0f,
     0.0f, 0.0f, 1280.0f, 720.0f,
     0.0f, 0.0f, 0.0f,
     1.0f, 1.0f, 1.0f, 1.0f,
			false);
}