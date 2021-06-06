#pragma once

#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnSceneChangeListener.h"
#include "Fps.h"

class Looper final : public IOnSceneChangeListener
{
private:
	std::stack<std::shared_ptr<AbstractScene>> sceneStack;	//シーンのスタック
	Fps fps;
public:
	Looper();
	~Looper() = default;
	bool loop() ;
	void onSceneChanged(const eScene scene, const bool stackClear) override;
};
