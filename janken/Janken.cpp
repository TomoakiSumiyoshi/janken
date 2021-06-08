#include "DxLib.h"
#include "Janken.h"
#include "Keyboard.h"

Janken::Janken()
{
	initialize();
	image[0] = LoadGraph("dat/0.PNG");
	image[1] = LoadGraph("dat/1.PNG");
	image[2] = LoadGraph("dat/2.PNG");
}

bool Janken::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_ESCAPE) == 2)
		initialize();

	inputJanken();
	return true;
}

void Janken::draw() const
{
	DrawFormatString(150, 0, GetColor(255, 255, 255), "%s", "Enterキーで決定　Escキーでリセット");
	if (state == -1)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "ジャンケン・・・");
	else if (state == 0)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "あいこで・・・・");
	else if (state == 1)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "****ざんねん****");
	else
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "***おめでとう***");

	DrawFormatString(150, 130, GetColor(255, 255, 255), "%s", "相手：");
	DrawFormatString(150, 360, GetColor(255, 255, 255), "%s", "自分：");

	if (0 <= com && com <= 2)
		DrawGraph(320, 100, image[com], TRUE);
	else
		DrawGraph(320, 100, image[GetRand(2)], TRUE);

	if ((0 <= player && player <= 2) && state != 0)
		DrawGraph(200 + 120 * player, 280, image[player], TRUE);
	else {
		for (int i = 0; i <= 2; i++) {
			if (i == select)
				DrawGraph(200 + 120 * i, 280, image[i], TRUE);
			else
				DrawGraph(200 + 120 * i, 330, image[i], TRUE);
		}
	}
}

void Janken::initialize()
{
	player = -1;
	com = -1;
	state = -1;
	select = 0;
}


void Janken::inputJanken()
{
	if (!(state == -1 || state == 0))//まだ未入力か、あいこじゃないなら処理しない
		return;
	//何か入力があれば
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_RIGHT) == 2 ||
		Keyboard::getIns()->getPressingCount(KEY_INPUT_LEFT) == 2 ||
		Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN) == 2) {
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_RIGHT) == 2) {
			select = (select + 1) % 3;
		}
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_LEFT) == 2) {
			select = (select + 2) % 3;
		}
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN) == 2) {
			player = select;
			com = GetRand(2);//コンピュータの入力
			calcJanken();
		}
	}
}

void Janken::calcJanken()
{
	if (player != com) {
		if (player == (com + 1) % 3)
			state = 1;//負け状態
		else
			state = 2;//勝ち状態
	}
	else
		state = 0;//あいこ状態
}