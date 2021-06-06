#pragma once

#include "IOnSceneChangeListener.h"

class AbstractScene
{
protected:
	IOnSceneChangeListener* implSceneChanged;
public:
	AbstractScene(IOnSceneChangeListener* impl);
	virtual ~AbstractScene() = default;
	virtual void update() = 0;
	virtual void draw() const = 0;
};
