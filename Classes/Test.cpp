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
	
	this->btn = TextButton::create(1, Language::get("union_btn_view"), 0);
	this->btn->retain();
	this->addChild(btn);
	btn->setPosition(ccp(200, 500));
	btn->setTag(11);
	btn->coreTarget->addTargetWithActionForControlEvents(this, cccontrol_selector(Test::btnClickHandler), CCControlEventTouchUpInside);  
	this->btn->setEnabled(false);

	this->btn2 = TextButton::create(5, "button", 0);
	this->btn2->retain();
	this->addChild(this->btn2);
	this->btn2->setPosition(ccp(300, 700));
	this->btn2->setTag(22);
	/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�ڣ��򴥷�һ�� */  
	this->btn2->coreTarget->addTargetWithActionForControlEvents(this, cccontrol_selector(Test::btn2ClickHandler), CCControlEventTouchUpInside);  

	TestChildScene* cs = TestChildScene::create();
	this->addChild(cs);

	CCString* ccstr = CCString::create("images/tabBar/item/weapon.png");
	CCArray* ary = CCArray::create();
	ary->retain();
	ary->addObject(ccstr);

	this->tarBar = TabBar::create(ary, 0);
	this->tarBar->retain();
	this->addChild(this->tarBar);
	this->tarBar->setPosition(ccp(100, 500));
	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	return true;
}

void Test::btnClickHandler( CCObject* pSender, CCControlEvent event )
{
	/*CCControlButton* btn = (CCControlButton*) pSender;
	CCLOG("click btn%i", btn->getTag());*/

	this->btn->removeFromParent();
	CCLOG("retainCount btn%i", this->btn->retainCount());
	this->btn->release();
	
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
	
	CCLOG("randomFloat r=%f", Random::randomFloat(-2.4f, 6.6f));
	CCLOG("randomInt r =%i", Random::randomInt(-6, 6));
	CCLOG("randrange r =%i", Random::randrange(1, 10, 2));
	CCLOG("boolean=%i", Random::boolean(.2f));
	EnterFrame::clear();

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

void Test::btn2ClickHandler( CCObject* pSender, CCControlEvent event )
{
	CCLOG("click2");
	FloatTips::clear();
}
