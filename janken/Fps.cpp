#include "DxLib.h"
#include "Fps.h"

const static int LIST_LEN_MAX = 120;	//�ő�120�t���[���őҋ@�������v�Z����(2�ȏ�ɂ���)
const static int FPS = 60;				//FPS
const static int UPINTVL = 60;			//60�t���[���Ɉ�x�X�V����

Fps::Fps() : counter(0), fps(0) 
{
}

void Fps::wait()
{
	counter++;
	Sleep(getWaitTime());	//�҂ׂ����Ԃ��擾���đ҂B
	regist();
	if (counter == UPINTVL) {	//�X�V�^�C�~���O��1�񕽋ϒl���X�V����
		updateAverage();
		counter = 0;
	}
}

void Fps::draw() const
{
	if (fps == 0) {
		return;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%04.1ffps", fps);
}

void Fps::regist()
{
	timeList.push_back(GetNowCount());
	if (timeList.size() > LIST_LEN_MAX) {
		timeList.pop_front();
	}
}

unsigned int Fps::getWaitTime() const
{
	int len = (int)timeList.size();
	if (len == 0) {
		return 0;
	}
	int shouldTookTime = (int)(1000 / 60.f * (len));			//�v�Z�ォ����ׂ�����
	int actuallyTookTime = GetNowCount() - timeList.front();	//���ۂɂ�����������
	int waitTime = shouldTookTime - actuallyTookTime;			//�҂ׂ�����
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned int)waitTime;
}

void Fps::updateAverage()
{
	int len = (int)timeList.size();
	if (len < LIST_LEN_MAX) {	//�܂����ς��v�Z���郌�x���ɂ܂ł��܂��Ă��Ȃ���Όv�Z���Ȃ�
		return;
	}
	int tookTime = timeList.back() - timeList.front();	//LIST_LEN_MAX�t���[���ɂ�����������
	float average = (float)tookTime / (len - 1);		//���ς����
	if (average == 0) {
		return;
	}
	fps = roundf((1000 / average) * 10) / 10;			//������2�ʂŎl�̌ܓ�����
}
