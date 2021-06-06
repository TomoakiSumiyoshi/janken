#pragma once

#include "eScene.h"

class IOnSceneChangeListener
{
public:
	IOnSceneChangeListener() = default;
	virtual ~IOnSceneChangeListener() = default;
	virtual void onSceneChanged(const eScene scene, const bool stackClear) = 0;
};
