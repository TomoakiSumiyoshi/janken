#include "AbstractScene.h"

AbstractScene::AbstractScene(IOnSceneChangeListener* impl) : implSceneChanged(impl) 
{
}