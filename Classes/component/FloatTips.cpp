#include "FloatTips.h"
USING_NS_CC;
static CCNode* mParent;
static CCArray* ftPool;
static CCPoint startPos;
static CCTexture2D* shareTexture2D;
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
	//CCLOG("�صĴ�С%i", ftPool->count());
	if(ftPool->count() == 0)
	{
		//�������û�ж������½�����
		ft = FloatTip::create();
		ft->retain();
		//�жϹ��������Ƿ����
		if(!shareTexture2D) ft->createWithImage("ftips_bg.png");
		else ft->createWithTexture(shareTexture2D);
		//��spriteִ����ɫ�仯��ʱ����spriteҲ����ִ�е�����仯
		ft->setCascadeOpacityEnabled(true);
	}
	else
	{
		ft = (FloatTip *)ftPool->lastObject();
		//����͸����
		ft->setOpacity(0xFF);
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
	ft->removeFromParentAndCleanup(true);
	ftPool->addObject(ft);
}

void FloatTips::init( CCNode* parent, CCPoint p/*=ccp(320, 760)*/, CCTexture2D *pTexture/*=NULL*/ )
{
	startPos = p;
	mParent = parent;
	shareTexture2D = pTexture;
	if(!ftPool)
	{
		ftPool = CCArray::create();
		ftPool->retain();
	}
}

void FloatTips::clear()
{
	if(ftPool)
	{
		CCObject* ft;
		int count = ftPool->count();
		for (int i = 0; i < count; i++)
		{
			ft = ftPool->objectAtIndex(i);
			//˭retain˭�͸���release
			ft->release();
			CCLOG("retainCount %i", ft->retainCount());
		}
		ftPool->removeAllObjects();
	}
}

FloatTip::FloatTip()
{
	
}

FloatTip::~FloatTip()
{
	CCLOG("remove FloatTip");
	if(this->bg) this->bg->removeFromParent();
	if(this->contentTf) this->contentTf->removeFromParent();
}

void FloatTip::setText(const char* str)
{
	this->contentTf->setString(str);
}

void FloatTip::createWithImage( const char *pszFileName )
{
	this->bg = CCSprite::create(pszFileName);
	this->bg->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->bg);
	this->createContentText();
}

void FloatTip::createWithTexture( CCTexture2D *pTexture )
{
	this->bg = CCSprite::createWithTexture(pTexture);
	this->bg->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->bg);
	this->createContentText();
}

void FloatTip::createContentText()
{
	this->contentTf = CCLabelTTF::create("", "Arial", 40);
	this->contentTf->setAnchorPoint(ccp(.5, .5));
	this->addChild(this->contentTf);
}

FloatTip* FloatTip::create()
{
	FloatTip* floatTip = new FloatTip();
	if (floatTip && floatTip->init())
	{
		floatTip->autorelease();
		return floatTip;
	}
	CC_SAFE_DELETE(floatTip);
	return NULL;
}
