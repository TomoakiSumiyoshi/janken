#include "DxLib.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"

TitleScene::TitleScene(IOnSceneChangeListener* impl) : AbstractScene(impl), counter(0) 
{
	PlaySoundFile("dat/title.mp3", DX_PLAYTYPE_LOOP);
}

void TitleScene::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) == 1) {
		const bool stackClear = false;
		implSceneChanged->onSceneChanged(eScene::Game, stackClear);
		return;
	}
	counter++;
}

void TitleScene::draw() const
{
	DrawString(200, 100, "Ç∂Ç·ÇÒÇØÇÒÉQÅ[ÉÄ", GetColor(255, 255, 255));

	if (counter % 90 <= 45) {
		DrawString(200, 300, "PRESS SPACE TO START", GetColor(255, 255, 255));
	}
}