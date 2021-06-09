#pragma once

#include "Singleton.h"
#include <array>

class Mouse : public Singleton<Mouse> 
{
	Mouse();
	friend Singleton<Mouse>;
public:
	static const int LEFT_CLICK = 0;
	static const int RIGHT_CLICK = 1;

	bool update();
	int getPressingCount(int keyCode);
	int getReleasingCount(int keyCode);
	int getX() { return x; }
	int getY() { return y; }
private:
	static const int KEY_NUM = 8;
	int x, y;
	std::array<int, KEY_NUM> pressingCount;;
	std::array<int, KEY_NUM> releasingCount;

	bool isAvailableCode(int keyCode);
};