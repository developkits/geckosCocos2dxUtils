#include "SlotEffect.h"
SlotEffect::SlotEffect()
{
	this->m_randomIndex = 0;
	this->m_curIndex = 0;
	this->m_maxIndex = 0;
	this->m_loop = 1;
	this->m_delay = 50;
	this->m_gapIndex = 5;
	this->isSlowing = false;
	this->currentCount = 0;
	this->addDelay = 200;
	this->m_target = NULL;
	this->func = NULL;
	this->setAnchorPoint(ccp(0, 0));
}

SlotEffect::~SlotEffect()
{
}

bool SlotEffect::init(int curIndex, int maxIndex, int loop /*= 1*/, float delay /*= 50*/, int gapIndex /*= 5*/, int addDelay /*= 200*/)
{
	this->m_curIndex = curIndex;
	this->m_maxIndex = curIndex;
	this->m_maxIndex = maxIndex;
	this->m_loop = loop;
	this->m_delay = delay;
	this->m_gapIndex = gapIndex;
	this->addDelay = addDelay;
	return true;
}

SlotEffect* SlotEffect::create(int curIndex, int maxIndex, int loop /*= 1*/, float delay /*= 50*/, int gapIndex /*= 5*/, int addDelay /*= 200*/)
{
	SlotEffect* sl = new SlotEffect();
	if (sl && sl->init(curIndex, maxIndex, loop, delay, gapIndex))
	{
		sl->autorelease();
		return sl;
	}
	CC_SAFE_DELETE(sl);
	return NULL;
}

void SlotEffect::start(int targetIndex, bool reverse /*= false*/)
{
	if (targetIndex < 1) targetIndex = 1;
	if (targetIndex > this->m_maxIndex) targetIndex = this->m_maxIndex;
	this->isSlowing = false;
	this->m_targetIndex = targetIndex;
	if (!reverse)
		this->m_slowIndex = this->fixNumber(this->m_targetIndex - this->m_gapIndex, 1, this->m_maxIndex);
	else
		this->m_slowIndex = this->fixNumber(this->m_targetIndex + this->m_gapIndex, 1, this->m_maxIndex);
	this->m_reverse = reverse;
	this->currentCount = 0;
	this->schedule(schedule_selector(SlotEffect::update), this->m_delay / 1000);
}

void SlotEffect::pause()
{
	this->unschedule(schedule_selector(SlotEffect::update));
}

void SlotEffect::update(float dt)
{
	//索引轮回
	if (!this->m_reverse)
	{
		this->m_curIndex++;
		if (this->m_curIndex > this->m_maxIndex)
			this->m_curIndex = 1;
	}
	else
	{
		this->m_curIndex--;
		if (this->m_curIndex < 1)
			this->m_curIndex = this->m_maxIndex;
	}
	//一个循环结束
	if (this->currentCount >= this->m_loop * this->m_maxIndex)
	{
		//是否进入了慢速模式
		if (this->m_curIndex == this->m_slowIndex)
		{
			this->isSlowing = true;
			this->schedule(schedule_selector(SlotEffect::update), (this->m_delay + this->addDelay) / 1000);
		}
	}
	this->m_randomIndex = (int)(CCRANDOM_0_1() * this->m_maxIndex + 1);
	if (this->isSlowing && this->m_curIndex == this->m_targetIndex)
	{
		this->m_randomIndex = this->m_targetIndex;
		this->pause();
	}
	//调用监听回调。
	if (this->m_target && this->func)
	{
		(this->m_target->*this->func)();
	}
	this->currentCount++;
}

float SlotEffect::fixNumber(float num, float min, float range)
{
	(float)num = (int)num % (int)range;
	if (num < min) return num + range;
	return num;
}

int SlotEffect::getCurIndex()
{
	return this->m_curIndex;
}

int SlotEffect::getRandomIndex()
{
	return this->m_randomIndex;
}

void SlotEffect::addEventListener(CCObject* target, SEL_CallFunc func)
{
	this->m_target = target;
	this->func = func;
}
