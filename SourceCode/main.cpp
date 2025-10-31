#include "all.h"

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    GameLib::init(L"Garden of Ray", 1280, 720, true, 60.0);
    Timer::getInstance()->initialize();

    SceneManager* sceneMgr = SceneManager::getInstance();
    sceneMgr->ChangeNextScene(new SceneTitle()); // Å‰‚Íƒ^ƒCƒgƒ‹‚©‚ç

    while (GameLib::gameLoop()) {
        Timer::getInstance()->update();
        float delta = Timer::getInstance()->getDeltaTime();

        sceneMgr->Update(delta);

        sceneMgr->Render();
        sceneMgr->Draw();
        sceneMgr->DrawUI();
        sceneMgr->DrawGUI();

        GameLib::present(1, 0);
    }

    sceneMgr->Clear();
    GameLib::uninit();
    return 0;
}