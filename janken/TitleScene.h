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
	unsigned int counter;
};