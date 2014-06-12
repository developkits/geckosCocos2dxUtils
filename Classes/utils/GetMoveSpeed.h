#pragma once
#ifndef _GET_MOUSE_SPEED_
#define _GET_MOUSE_SPEED_
#include "cocos2d.h"
USING_NS_CC;
class GetMoveSpeed
{
public:
	GetMoveSpeed();
	~GetMoveSpeed();

	//************************************
	// Description: ��ʼ�����λ��
	// Parameter: float x	x����
	// Parameter: float y	y����
	// Returns:   void
	//************************************
	static void initPos(float x, float y);
	
	//************************************
	// Description:��ȡ�����ٶ�
	// Parameter: float x	��ǰ������xλ��
	// Parameter: float y	��ǰ������yλ��
	// Returns:   float		��ǰ�������ٶ�
	//************************************
	static float getSpeed(float x, float y);
};
#endif