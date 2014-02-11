#include "FloatTips.h"
USING_NS_CC;
static CCNode* mParent;
static CCArray* ftPool;
static CCPoint startPos;
FloatTips::FloatTips(void)
{
}

FloatTips::~FloatTips(void)
{
}

void FloatTips::show(const char* content)
{
	if(!mParent) return;
	FloatTip* ft = FloatTips::getAFloatTip();
	ft->setPosition(startPos);
	ft->setText(content);
	mParent->addChild(ft);
}

FloatTip* FloatTips::getAFloatTip()
{
	FloatTip* ft;
	CCLOG("�صĴ�С%i", ftPool->count());
	if(ftPool->count() == 0)
	{
		CCLOG("new");
		//�������û�ж������½�����
		ft = new FloatTip();
		//��spriteִ����ɫ�仯��ʱ����spriteҲ����ִ�е�����仯
		ft->setCascadeOpacityEnabled(true);
	}
	else
	{
		CCLOG("pool");
		ft = (FloatTip *)ftPool->lastObject();
		//����͸����
		ft->setOpacity(0xFF);
		ft->stopAllActions();
		ftPool->removeLastObject();
	}

	CCMoveTo* moveTo = CCMoveTo::create(.2f, ccp(startPos.x, startPos.y + 20));
	CCDelayTime* delayTime = CCDelayTime::create(1.0f);
	CCMoveTo* moveTo2 = CCMoveTo::create(.3f, ccp(startPos.x, startPos.y + 40));
	CCFadeOut* fadeOut = CCFadeOut::create(.3f);
	CCSpawn* spawn = CCSpawn::create(moveTo2, fadeOut, NULL);
	CCSequence* sequence = CCSequence::create(moveTo, delayTime, spawn, NULL);

	//�����ص�������
	CCCallFuncN * callBackFunc = CCCallFuncN::create(ft, callfuncN_selector(FloatTips::actionCompleteCallBackFunc));
	CCFiniteTimeAction * seq = CCSequence::create(sequence, callBackFunc, NULL);

	ft->runAction(seq);
	return ft;
}

void FloatTips::actionCompleteCallBackFunc(CCNode* ft)
{
	ft->removeFromParent();
	ftPool->addObject(ft);
}

void FloatTips::init( CCNode* parent, CCPoint p/*=ccp(320, 760)*/ )
{
	startPos = p;
	mParent = parent;
	if(!ftPool)
	{
		ftPool = CCArray::create();
		ftPool->retain();
	}
}

void FloatTips::clear()
{
	if(ftPool)
		ftPool->removeAllObjects();
}


FloatTip::FloatTip()
{
	this->bg = CCSprite::create("ftips_bg.png");
	this->bg->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->bg);

	this->contentTf = CCLabelTTF::create("", "Arial", 40);
	this->contentTf->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->contentTf);
}

FloatTip::~FloatTip()
{
	this->bg->removeFromParent();
	CC_SAFE_RELEASE(this->bg);

	this->contentTf->removeFromParent();
	CC_SAFE_RELEASE(this->contentTf);
}

void FloatTip::setText(const char* str)
{
	this->contentTf->setString(str);
}