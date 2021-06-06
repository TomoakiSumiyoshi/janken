#include "DxLib.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"

TitleScene::TitleScene(IOnSceneChangeListener* impl) : AbstractScene(impl)
{
}

void TitleScene::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_E) == 1) {
		const bool stackClear = false;
		implSceneChanged->onSceneChanged(eScene::Game, stackClear);
		return;
	}
}

void TitleScene::draw() const
{
	DrawString(100, 100, "ƒ^ƒCƒgƒ‹‰æ–Ê", GetColor(255, 255, 255));
}