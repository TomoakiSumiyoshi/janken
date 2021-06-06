#include "Dxlib.h"
#include "SystemMain.h"
#include "Looper.h"
#include "Define.h"

bool SystemMain::initialize() const
{
	SetAlwaysRunFlag(TRUE);										//�E�B���h�E���m���A�N�e�B�u�ł����s
	SetWindowSizeChangeEnableFlag(TRUE);						//�E�B���h�E�T�C�Y�����R�ɕύX�ł���悤�ɂ���
	SetOutApplicationLogValidFlag(FALSE);						//���O���o�͂��Ȃ�
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);	//�t���X�N���[�����ɏc������ێ�����
	SetWindowText("����񂯂�");								//�E�B���h�E�^�C�g��������
	ChangeWindowMode(TRUE);										//�E�B���h�E���[�h�ɕύX
	//SetWindowSizeExtendRate(1.0);								//�E�B���h�E�T�C�Y��ύX���������͂����ɔ{�����w�肷��
	const int COLOR_BIT = 32;									//�F��bit���@�ʏ��32 �y������ꍇ16
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);		//�Q�[���̉𑜓x��ݒ肷��
	SetWindowInitPosition(0, 0);								//�E�B���h�E�̏����ʒu��ݒ肷��
	if (DxLib_Init()) {											//DX���C�u��������������
		return false;											//�ُ�I�������瑦���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);								//����ʏ�����ݒ肷��
	return true;
}

void SystemMain::finalize() const
{
	DxLib_End();
}

void SystemMain::main() const
{
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {	//�����珇�ɗ���ʂ�\��ʂɔ��f,���b�Z�[�W����,��ʃN���A
		if (!looper.loop()) {
			break;
		}
	}
}