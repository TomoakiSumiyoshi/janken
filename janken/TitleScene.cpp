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
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) == 1) {
		const bool stackClear = false;
		implSceneChanged->onSceneChanged(eScene::Game, stackClear);
		return;
	}
}

void TitleScene::draw() const
{
	DrawString(320, 100, "Ç∂Ç·ÇÒÇØÇÒÉQÅ[ÉÄ", GetColor(255, 255, 255));

	DrawString(320, 300, "PRESS SPACE TO START", GetColor(255, 255, 255));
}