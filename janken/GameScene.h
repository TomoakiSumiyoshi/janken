#pragma once

#include "AbstractScene.h"
#include <memory>
#include "Janken.h"

class GameScene : public AbstractScene
{
public:
	GameScene(IOnSceneChangeListener* impl);
	virtual ~GameScene() = default;
	void update() override;
	void draw() const override;
private:
	std::shared_ptr<Janken> janken;
};
