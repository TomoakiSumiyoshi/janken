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
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN) == 2) {
		initialize();
	}
	inputJanken();
	return true;
}

void Janken::draw() const
{
	DrawFormatString(150, 0, GetColor(255, 255, 255), "%s", "Enterキーでリセット　1:グー 2:チョキ 3:パー");
	if (state == -1)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "ジャンケン・・・");
	else if (state == 0)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "あいこで・・・・");
	else if (state == 1)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "****ざんねん****");
	else
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "***おめでとう***");

	DrawFormatString(150, 130, GetColor(255, 255, 255), "%s", "相手：");
	DrawFormatString(150, 310, GetColor(255, 255, 255), "%s", "自分：");

	if (0 <= com && com <= 2)
		DrawGraph(320, 100, image[com], TRUE);
	if (0 <= player && player <= 2)
		DrawGraph(320, 280, image[player], TRUE);
}

void Janken::initialize()
{
	player = -1;
	com = -1;
	state = -1;
}

void Janken::inputJanken()
{
	if (!(state == -1 || state == 0))//まだ未入力か、あいこじゃないなら処理しない
		return;
	//何か入力があれば
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_1) == 2 || 
		Keyboard::getIns()->getPressingCount(KEY_INPUT_2) == 2 || 
		Keyboard::getIns()->getPressingCount(KEY_INPUT_3) == 2) {
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_1) == 2)//グーなら
			player = 0;
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_2) == 2)//チョキなら
			player = 1;
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_3) == 2)//パーなら
			player = 2;
		com = GetRand(2);//コンピュータの入力
		calcJanken();
	}
}

void Janken::calcJanken()
{
	if (player != com) {
		if (player == (com + 1) % 3) {
			state = 1;//負け状態
		}
		else {
			state = 2;//勝ち状態
		}
	}
	else {
		state = 0;//あいこ状態
	}
}