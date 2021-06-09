#include "DxLib.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"
#include "Mouse.h"

TitleScene::TitleScene(IOnSceneChangeListener* impl) : AbstractScene(impl), textCounter(0), flashCounter(0), flashFlag(false)
{
	PlaySoundFile("dat/title.mp3", DX_PLAYTYPE_LOOP);
}

void TitleScene::update()
{
	if ((Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) == 2 ||
		Mouse::getIns()->getPressingCount(Mouse::LEFT_CLICK) == 2) &&
		!flashFlag) {
		flashFlag = true;
		PlaySoundFile("dat/titleSE.mp3", DX_PLAYTYPE_BACK);
	}
		
	
	if (flashFlag) {
		if (flashCounter >= 0 && flashCounter < BRIGHT_NUM)
			SetDrawBright(flashCounter, flashCounter, flashCounter);
		else if (flashCounter >= BRIGHT_NUM && flashCounter < INTERVAL)
			SetDrawBright(255, 255, 255);
		else if (flashCounter >= INTERVAL && flashCounter < INTERVAL + BRIGHT_NUM)
			SetDrawBright(255 - (flashCounter - BRIGHT_NUM), 255 - (flashCounter - BRIGHT_NUM), 255 - (flashCounter - BRIGHT_NUM));
		else {
			SetDrawBright(255, 255, 255);
			const bool stackClear = true;
			implSceneChanged->onSceneChanged(eScene::Game, stackClear);
			return;
		}
		flashCounter += FLASH_SPEED;
	}

	textCounter++;
}

void TitleScene::draw() const
{
	DrawString(200, 100, "Ç∂Ç·ÇÒÇØÇÒÉQÅ[ÉÄ", GetColor(255, 255, 255));

	if (textCounter % 48 < 24) {
		DrawString(200, 300, "PRESS SPACE TO START", GetColor(255, 255, 255));
	}

	if (flashFlag) {
		DrawBox(0, 0, Define::WIN_W, Define::WIN_H, GetColor(255, 255, 255), TRUE);
	}
}