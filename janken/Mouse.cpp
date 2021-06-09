#include "DxLib.h"
#include "Mouse.h"

Mouse::Mouse() : pressingCount(), releasingCount(), x(), y()
{
}

bool Mouse::update()
{
	int nowButtonState = GetMouseInput();
	GetMousePoint(&x, &y);
	for (int i = 0;  i < KEY_NUM; i++) {
		if ((nowButtonState >> i) &1){
			if (releasingCount[i] > 0) {
				releasingCount[i] = 0;
			}
			pressingCount[i]++;
		}
		else {
			if (pressingCount[i] > 0) {
				pressingCount[i] = 0;
			}
			releasingCount[i]++;
		}
	}
	return true;
}

int Mouse::getPressingCount(int keyCode) 
{
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return pressingCount[keyCode];
}

int Mouse::getReleasingCount(int keyCode) 
{
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return releasingCount[keyCode];
}

bool Mouse::isAvailableCode(int keyCode)
{
	if (!(keyCode >= 0 && keyCode < KEY_NUM)) {
		return false;
	}
	return true;
}