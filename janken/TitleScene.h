#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
public:
	TitleScene(IOnSceneChangeListener* impl);
	virtual ~TitleScene() = default;
	void update() override;
	void draw() const override;
private:
	static const int INTERVAL = 300;
	static const int BRIGHT_NUM = 256;
	static const int FLASH_SPEED = 8;
	unsigned int textCounter;
	unsigned int flashCounter;
	bool flashFlag;
};