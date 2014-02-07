#include "TestChildScene.h"
#include "utils/EnterFrame.h"

TestChildScene::TestChildScene(void)
{
	CCLog("����");
}


TestChildScene::~TestChildScene(void)
{
}

void TestChildScene::onEnter()
{
	CCLog("onEnter");
	EnterFrame::push(callfunc_selector(TestChildScene::loop));
	CCScene::onEnter();
}

void TestChildScene::loop()
{
	CCLog("child loop");
}

