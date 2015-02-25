#include "BlackHoleEffectTest.h"
#include "effect\BlackHoleEffect.h"


BlackHoleEffectTest::BlackHoleEffectTest()
{
	this->ary = CCArray::create();
	this->ary->retain();

	this->objList = CCArray::create();
	this->objList->retain();

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	scheduleUpdate();

	this->addObj();
}

BlackHoleEffectTest::~BlackHoleEffectTest()
{
}

bool BlackHoleEffectTest::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCParticleSystemQuad* blackHoleParticle = CCParticleSystemQuad::create("blackHoleEffect.plist");
	blackHoleParticle->setPosition(touch->getLocation());
	blackHoleParticle->setAutoRemoveOnFinish(true);
	this->addChild(blackHoleParticle);

	BlackHoleEffect* bh = BlackHoleEffect::create();
	bh->setInHoleSelector(this, in_hole_selector(BlackHoleEffectTest::inHoleComplete));
	bh->setAttenuationSelector(this, attenuation_selector(BlackHoleEffectTest::attenuationComplete));
	bh->setOverSelector(this, over_selector(BlackHoleEffectTest::overComplete));
	bh->setUserObject(blackHoleParticle);
	bh->addSubstanceList(this->objList);
	bh->addHole(touch->getLocation().x, touch->getLocation().y);
	this->ary->addObject(bh);

	return true;
}

void BlackHoleEffectTest::update(float dt)
{
	int count = this->ary->count();
	for (int i = count - 1; i >= 0; --i)
	{
		BlackHoleEffect* bh = (BlackHoleEffect* )this->ary->objectAtIndex(i);
		bh->update();
	}
}

void BlackHoleEffectTest::inHoleComplete(CCObject* obj)
{
	CCNode* node = (CCNode*)obj;
	node->removeFromParent();
}

void BlackHoleEffectTest::attenuationComplete(CCObject* obj)
{
	//������Խ��ڶ�����ʾЧ��������С��
	BlackHoleEffect* blackHole = (BlackHoleEffect*)obj;
	CCParticleSystemQuad* blackHoleParticle = (CCParticleSystemQuad*)blackHole->getUserObject();
	CCScaleTo* st = CCScaleTo::create(2, 0);
	blackHoleParticle->runAction(st);
}

void BlackHoleEffectTest::overComplete(CCObject* obj)
{
	//�ڶ���ȫ��ʧ�����Խ��ڶ���ʾ����ɾ��
	BlackHoleEffect* blackHole = (BlackHoleEffect* )obj;
	CCParticleSystemQuad* blackHoleParticle = (CCParticleSystemQuad*)blackHole->getUserObject();
	blackHoleParticle->removeFromParent();
	int length = this->ary->count();
	for (int i = length - 1; i >= 0; i--)
	{
		BlackHoleEffect* bh = (BlackHoleEffect* )this->ary->objectAtIndex(i);
		if (bh == blackHole)
		{
			this->ary->removeObjectAtIndex(i);
			break;
		}
	}
}

void BlackHoleEffectTest::addObj()
{
	int num = (int)(randnum(100, 300));
	for (int i = 1; i <= num; ++i)
	{
		CCSprite* spt = CCSprite::create("normal_body.png");
		spt->setPositionX(randnum(0, 960));
		spt->setPositionY(randnum(0, 540));
		spt->setRotation(randnum(0, 360));
		this->objList->addObject(spt);
		this->addChild(spt);
	}
}

float BlackHoleEffectTest::randnum(float a, float b)
{
	return CCRANDOM_0_1() * (b - a) + a;
}
