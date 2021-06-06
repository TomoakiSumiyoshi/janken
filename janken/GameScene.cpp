#include "DxLib.h"
#include "GameScene.h"

using namespace std;

GameScene::GameScene(IOnSceneChangeListener* impl) : AbstractScene(impl)
{
	janken = make_shared<Janken>();
}

void GameScene::update()
{
	janken->update();
}

void GameScene::draw() const
{
	janken -> draw();
}