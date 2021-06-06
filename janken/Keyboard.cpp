#include "Dxlib.h"
#include "Keyboard.h"

bool Keyboard::update() 
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);		//���̃L�[�̓��͏�Ԃ��擾
	for (int i = 0; i < KEY_NUM; i++) {
		if (nowKeyStatus[i] != 0) {			//i�Ԃ̃L�[��������Ă�����
			if (releasingCount[i] > 0) {	//������J�E���^��0���傫�����
				releasingCount[i] = 0;		//0�ɖ߂�
			}
			pressingCount[i]++;				//������J�E���^�𑝂₷
		}
		else {
			if (pressingCount[i] > 0) {		//������J�E���^��0���傫�����
				pressingCount[i] = 0;		//0�ɖ߂�
			}
			releasingCount[i]++;			//������J�E���^�𑝂₷
		}
	}
	return true;

}

int Keyboard::getPressingCount(int keyCode)
{
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return pressingCount[keyCode];
}

int Keyboard::getReleasingCount(int keyCode)
{
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return releasingCount[keyCode];
}

bool Keyboard::isAvailableCode(int keyCode)
{
	if (!(keyCode >= 0 && keyCode < KEY_NUM)) {
		return false;
	}
	return true;
}
