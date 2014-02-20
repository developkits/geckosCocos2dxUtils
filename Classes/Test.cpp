#include "Test.h"
#include "utils/EnterFrame.h"
#include "TestChildScene.h"
#include "utils/Random.h"
#include "utils/StringUtil.h"
#include "utils/TimeFormat.h"
#include "utils/Language.h"
#include "component/FloatTips.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>   
#include <algorithm>  
#include "cocos-ext.h"
#include "component/TextButton.h"
#include "component/Alert.h"
#include "utils/MathUtil.h"
using namespace extension;
using namespace std;
using std::vector;
Test::Test(void)
{
	
}

Test::~Test(void)
{
}

bool Test::init()
{
	CCLOG("r=%f", Random::randomFloat(-2.4f, 6.6f));
	std::string s = " ";
	CCLOG("rfind = %i\n", s.rfind("\t"));
	CCLOG("is WhiteSpace: %i\n", StringUtil::isWhiteSpace(s));

	std::string str = "  111111  ";
	//str.replace(0, 2, "");
	StringUtil::trim(&str);
	CCLOG("1 str%s", str.c_str());
	StringUtil::zfill(&str, 9);
	CCLOG("zfill%s", str.c_str());
	str = "1234";
	StringUtil::reverse(&str);
	CCLOG("reverse= %s", str.c_str());
	StringUtil::cutOff(&str, 1, 1);
	CCLOG("cutOff= %s", str.c_str());

	string email = "kanontang@gmail.com";
	StringUtil::trim(&email);
	CCLOG("email= %s", email.c_str());
	bool isEmail = StringUtil::isEmail(&email);
	CCLOG("%d", isEmail);
	//CCLOG("bool", StringUtil::isEmail(&email));
	//CCLOG("email= %s", email.c_str());
	vector<string> v;
	StringUtil::split(v, "00:06:11", ":");
	for (unsigned int i = 0; i < v.size(); i++)
	{
		CCLOG("v[i]%s", v[i].c_str());
	}

	string time;
	TimeFormat::secondToTime(&time, 7735);
	CCLOG("secondToTime= %s", time.c_str());

	TimeFormat::timeToSecond(&time, "00:60:00");
	CCLOG("timeToSecond= %s", time.c_str());

	Language::init("language.xml");

	v.clear();
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	//�ָ�####������######## �ָ�3������45
	CCLOG("test= %s", Language::get("test", &v));

	/*EnterFrame::init(this);
	EnterFrame::push(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun2));
	EnterFrame::push(callfunc_selector(Test::runFun));

	EnterFrame::pop(callfunc_selector(Test::runFun2));
	EnterFrame::pop(callfunc_selector(Test::runFun));
	EnterFrame::push(callfunc_selector(Test::runFun));*/

	/*const char* cc = Language::get("union_btn_view");
	
	sprintf((char*)cc, "%i", 2);*/

	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("ftips_bg.png");  

	FloatTips::init(this, ccp(320, 760), texture);
	
	vector<float> vect;
	MathUtil::threeSidesMathAngle(vect, 3, 4, 5);

	CCLOG("vect %f %f %f", vect[0], vect[1], vect[2]);
	
	CCSprite* a1 = CCSprite::create("node.png");
	a1->setPosition(ccp(65, 145));
	this->addChild(a1);

	CCSprite* a2 = CCSprite::create("node.png");
	a2->setPosition(ccp(177, 63));
	this->addChild(a2);

	CCSprite* a3 = CCSprite::create("node.png");
	a3->setPosition(ccp(223, 219));
	this->addChild(a3);

	CCPoint p = MathUtil::triangleCentroid(a1->getPosition(), a2->getPosition(), a3->getPosition());
	CCSprite* a4 = CCSprite::create("node.png");
	a4->setPosition(p);
	this->addChild(a4);

	float d = MathUtil::arithmeticSequenceIndex(21, 1);
	CCLOG("d %f", d);

	this->initTarBarList();

	this->btn = TextButton::create(TYPE_RECT_BLUE, Language::get("eatWhiteBtn"), 300);
	this->addChild(this->btn);
	this->btn->setPosition(ccp(200, 600));
	this->btn->setTag(11);
	this->btn->addEventListener(this, text_button_selector(Test::btnClickHandler));
	this->btn->setEnabled(false);
	//this->btn->setOpacity(0);
	//this->btn->setMouseEnabeld(false);

	this->btn2 = TextButton::create(5, "button", 0);
	this->addChild(this->btn2);
	this->btn2->setPosition(ccp(300, 500));
	this->btn2->setTag(22);
	/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�ڣ��򴥷�һ�� */  
	this->btn2->addEventListener(this, text_button_selector(Test::btn2ClickHandler));

	TestChildScene* cs = TestChildScene::create();
	this->addChild(cs);

	Alert::initParent(this);

	CCLOG("toScoreString %s", StringUtil::toScoreString(1124566681).c_str());

	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	return true;
}

void Test::btnClickHandler(CCNode* node)
{
	Alert::show((char* )Language::get("bind_alert"), false, true, this,
					alert_selector(Test::alertConfirmClickHandler), 
					alert_selector(Test::alertCancelClickHandler));
	/*CCControlButton* btn = (CCControlButton*) pSender;
	CCLOG("click btn%i", btn->getTag());*/
	//node->removeFromParent();
	//CCLOG("retainCount btn%i", this->btn->retainCount());
	//this->btn->release();
	//this->tarBar->removeFromParent();
	vector<string> v;
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	FloatTips::show(Language::get("test", &v));
	
	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}


bool Test::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	//CCLOG("retainCount btn%i", this->btn->retainCount());
	//this->tarBar->removeFromParent();
	CCLOG("randomFloat r=%f", Random::randomFloat(-2.4f, 6.6f));
	CCLOG("randomInt r =%i", Random::randomInt(-6, 6));
	CCLOG("randrange r =%i", Random::randrange(1, 10, 2));
	CCLOG("boolean=%i", Random::boolean(.2f));
	//EnterFrame::clear();

	vector<string> v;
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	
	FloatTips::show(Language::get("test", &v));

	return true;
}

void Test::runFun()
{
	CCLOG("run1");
}

void Test::runFun2()
{
	CCLOG("run2");
}

void Test::onEnter()
{
	CCScene::onEnter();
}

void Test::btn2ClickHandler(CCNode* node)
{
	//CCLOG("click2");
	//FloatTips::clear();
	//this->tarBar->removeFromParent();
	Alert::show((char* )Language::get("eatWhiteBtn"), true, true, this,
		alert_selector(Test::alertConfirmClickHandler), 
		alert_selector(Test::alertCancelClickHandler));
}

void Test::initTarBarList()
{
	this->tarBarList = CCArray::create();
	this->tarBarList->retain();

	CCString* ccstr = CCString::create("images/tabBar/item/weapon.png");
	CCArray* ary = CCArray::create();
	ary->addObject(ccstr);
	ccstr = CCString::create("images/tabBar/item/weaponSelected.png");
	ary->addObject(ccstr);
	tarBarList->addObject(ary);

	ccstr = CCString::create("images/tabBar/item/clothing.png");
	ary = CCArray::create();
	ary->addObject(ccstr);
	ccstr = CCString::create("images/tabBar/item/clothingSelected.png");
	ary->addObject(ccstr);
	tarBarList->addObject(ary);

	ccstr = CCString::create("images/tabBar/item/accessories.png");
	ary = CCArray::create();
	ary->addObject(ccstr);
	ccstr = CCString::create("images/tabBar/item/accessoriesSelected.png");
	ary->addObject(ccstr);
	tarBarList->addObject(ary);

	ccstr = CCString::create("images/tabBar/item/sell.png");
	ary = CCArray::create();
	ary->addObject(ccstr);
	ccstr = CCString::create("images/tabBar/item/sellSelected.png");
	ary->addObject(ccstr);
	tarBarList->addObject(ary);

	ccstr = CCString::create("images/tabBar/item/exchange.png");
	ary = CCArray::create();
	ary->addObject(ccstr);
	ccstr = CCString::create("images/tabBar/item/exchangeSelected.png");
	ary->addObject(ccstr);
	tarBarList->addObject(ary);    

	this->tarBar = TabBar::create(tarBarList, -35);
	this->addChild(this->tarBar);
	//this->tarBar->setOpacity(0);
	this->tarBar->setPosition(ccp(10, 500));
	this->tarBar->addEventListener(this, tar_bar_selector(Test::tarBarClickHandler));
}

void Test::tarBarClickHandler(int selectedIndex )
{
	CCLOG("selectedIndex %i", selectedIndex);
}

void Test::alertConfirmClickHandler()
{
	CCLOG("alertConfirmClickHandler");
}

void Test::alertCancelClickHandler()
{
	CCLOG("alertCancelClickHandler");
}
