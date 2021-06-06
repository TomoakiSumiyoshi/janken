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
	sceneStack.top()->update();		//�X�^�b�N�̃g�b�v�̃V�[�����X�V
	sceneStack.top()->draw();		//�X�^�b�N�̃g�b�v�̃V�[����`��
	fps.draw();
	fps.wait();
	return true;
}

void Looper::onSceneChanged(const eScene scene, const bool stackClear) 
{
	if (stackClear) { //�X�^�b�N�N���A�Ȃ�
		while (!sceneStack.empty()) {//�X�^�b�N��S����ɂ���
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
		ERR("����͂��̂Ȃ��V�[�����Ă΂�܂����B");
		break;
	}
}