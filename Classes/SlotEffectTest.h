#pragma once
#ifndef _SLOT_EFFECT_TEST_
#define _SLOT_EFFECT_TEST_
#include "cocos2d.h"
USING_NS_CC;
class SlotEffectTest :public CCScene
{
public:
	SlotEffectTest();
	~SlotEffectTest();
	//ѡ��ĳ��ѡ��
	void selectSpt();
	//��������ѡ��
	void resetAllSpt();

	CREATE_FUNC(SlotEffectTest);
};
#endif
