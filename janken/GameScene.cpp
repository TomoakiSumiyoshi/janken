#include "DxLib.h"
#include "GameScene.h"
#include "Keyboard.h"

using namespace std;

GameScene::GameScene(IOnSceneChangeListener* impl) : AbstractScene(impl)
{
	janken = make_shared<Janken>();
	PlaySoundFile("dat/game.mp3", DX_PLAYTYPE_LOOP);
}

void GameScene::update()
{
	janken->update();
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_BACK) == 1) {
		const bool stackClear = true;
		implSceneChanged->onSceneChanged(eScene::Title, stackClear);
		return;
	}
}

void GameScene::draw() const
{
	janken -> draw();
}