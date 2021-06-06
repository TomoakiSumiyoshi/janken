#include "Looper.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Error.h"
#include "Macro.h"
#include "Keyboard.h"

using namespace std;

Looper::Looper()
{
	sceneStack.push(make_shared<TitleScene>(this));
}

bool Looper::loop() 
{
	Keyboard::getIns()->update();
	sceneStack.top()->update();		//スタックのトップのシーンを更新
	sceneStack.top()->draw();		//スタックのトップのシーンを描画
	fps.draw();
	fps.wait();
	return true;
}

void Looper::onSceneChanged(const eScene scene, const bool stackClear) 
{
	if (stackClear) { //スタッククリアなら
		while (!sceneStack.empty()) {//スタックを全部空にする
			sceneStack.pop();
		}
	}
	switch (scene) {
	case eScene::Title:
		sceneStack.push(make_shared<TitleScene>(this));
		break;
	case eScene::Game:
		sceneStack.push(make_shared<GameScene>(this));
		break;
	default:
		ERR("あるはずのないシーンが呼ばれました。");
		break;
	}
}