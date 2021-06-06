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
	DrawFormatString(150, 0, GetColor(255, 255, 255), "%s", "Enter�L�[�Ń��Z�b�g�@1:�O�[ 2:�`���L 3:�p�[");
	if (state == -1)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "�W�����P���E�E�E");
	else if (state == 0)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "�������ŁE�E�E�E");
	else if (state == 1)
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "****����˂�****");
	else
		DrawFormatString(150, 50, GetColor(255, 255, 255), "%s", "***���߂łƂ�***");

	DrawFormatString(150, 130, GetColor(255, 255, 255), "%s", "����F");
	DrawFormatString(150, 310, GetColor(255, 255, 255), "%s", "�����F");

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
	if (!(state == -1 || state == 0))//�܂������͂��A����������Ȃ��Ȃ珈�����Ȃ�
		return;
	//�������͂������
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_1) == 2 || 
		Keyboard::getIns()->getPressingCount(KEY_INPUT_2) == 2 || 
		Keyboard::getIns()->getPressingCount(KEY_INPUT_3) == 2) {
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_1) == 2)//�O�[�Ȃ�
			player = 0;
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_2) == 2)//�`���L�Ȃ�
			player = 1;
		if (Keyboard::getIns()->getPressingCount(KEY_INPUT_3) == 2)//�p�[�Ȃ�
			player = 2;
		com = GetRand(2);//�R���s���[�^�̓���
		calcJanken();
	}
}

void Janken::calcJanken()
{
	if (player != com) {
		if (player == (com + 1) % 3) {
			state = 1;//�������
		}
		else {
			state = 2;//�������
		}
	}
	else {
		state = 0;//���������
	}
}