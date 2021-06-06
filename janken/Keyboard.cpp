#include "Dxlib.h"
#include "Keyboard.h"

bool Keyboard::update() 
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);		//今のキーの入力状態を取得
	for (int i = 0; i < KEY_NUM; i++) {
		if (nowKeyStatus[i] != 0) {			//i番のキーが押されていたら
			if (releasingCount[i] > 0) {	//離されカウンタが0より大きければ
				releasingCount[i] = 0;		//0に戻す
			}
			pressingCount[i]++;				//押されカウンタを増やす
		}
		else {
			if (pressingCount[i] > 0) {		//押されカウンタが0より大きければ
				pressingCount[i] = 0;		//0に戻す
			}
			releasingCount[i]++;			//離されカウンタを増やす
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
