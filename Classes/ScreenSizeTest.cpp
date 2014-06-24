#include "ScreenSizeTest.h"
#include "utils/ScreenUtil.h"
#include "utils/StringUtil.h"
#include "utils/Random.h"
USING_NS_CC;

ScreenSizeTest::ScreenSizeTest(void)
{
	Random::initRandomSeed();
	CCLOG("1randomFloat=%f", Random::randomFloat(-2.4f, 6.6f));
	CCLOG("2randomFloat=%f", Random::randomFloat(-2.4f, 6.6f));
	//�ı�	
	CCSprite* bg = CCSprite::create("bg.jpg");
	bg->setAnchorPoint(ccp(.5f, .5f));
	this->addChild(bg);
	bg->setPosition(ScreenUtil::getCenter());

	CCLOG("getScreenWidth%f", ScreenUtil::getScreenWidth());
	CCLOG("getScreenHeight%f", ScreenUtil::getScreenHeight());

	CCLabelTTF* label = CCLabelTTF::create("hello world", "����", 30);
	this->addChild(label);
	label->setPosition(ccp(ScreenUtil::getLeft() + label->getContentSize().width / 2, ScreenUtil::getTop() - label->getContentSize().height / 2));

	CCLOG("isSymbolWord %i", StringUtil::isSymbolWord("\n"));
	CCLOG("isAlphabetWord %i", StringUtil::isAlphabetWord("aaa"));
	CCLOG("isNumberWord %i", StringUtil::isNumberWord("158"));

	int pos = StringUtil::indexOf("��˹��", "˹");
	CCLOG("pos: %d", pos);

	string str = "��˹˹��";
	StringUtil::replace(str, "˹˹", "****");
	CCLOG("str: %s", str.c_str());

	string str1 = "����";
	string str2 = "��";
	size_t pos2 = str1.find(str2);
	CCLOG("pos: %d", pos2);
}


ScreenSizeTest::~ScreenSizeTest(void)
{
}
