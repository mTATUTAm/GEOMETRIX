#pragma once
#include "all.h"

class SceneTitle : public Scene {
	public:
	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update(float elapsedTime) override;
	virtual void Render() override;

private:
	Sprite* titleSprite;
};