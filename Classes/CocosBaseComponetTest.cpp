#include "CocosBaseComponetTest.h"
#include "cocosBaseComponet/CBFloatTips.h"
#include "utils/Language.h"
#include "component/TextButton.h"
CocosBaseComponetTest::CocosBaseComponetTest()
{
}


CocosBaseComponetTest::~CocosBaseComponetTest()
{
}

void CocosBaseComponetTest::btnClickHandler(CCNode* node)
{
	CBFloatTips::getInstance()->show(Language::get("alert_netClose"));
}

void CocosBaseComponetTest::onLoadResources()
{
	//�Ƿ�ʹ�û��� ���ʹ�û������޷�ִ�е�onLoadResources��onLoadResourcesCompleted ���ǻ�ʹ��ͬһ������
	setCachable(false);
	//�Ƿ��Զ��������� ���������� ÿ����ʹ��ͬһ������
	setAutoRemoveUnusedTexture(true);
}

void CocosBaseComponetTest::onLoadResourcesCompleted()
{

}

void CocosBaseComponetTest::onLoadScene()
{
	Language::init("language.xml");

	TextButton* btn = TextButton::create(TYPE_RECT_BLUE, "CBFloatTips", 200);
	this->addChild(btn);
	btn->setPosition(ccp(200, 200));
	btn->setTag(11);
	btn->addEventListener(this, text_button_selector(CocosBaseComponetTest::btnClickHandler));
}

void CocosBaseComponetTest::onEnterScene()
{

}

void CocosBaseComponetTest::onExitScene()
{

}
