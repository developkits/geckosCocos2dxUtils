#pragma once
#ifndef _BLACK_HOLE_EFFECT_
#define _BLACK_HOLE_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
//����ڶ��ص�
typedef void (CCObject::*SEL_IN_HOLE_SELECTOR)(CCObject*);
#define in_hole_selector(_SELECTOR) (SEL_IN_HOLE_SELECTOR)(&_SELECTOR)
//�ڶ�˥����Ϣ�ص�
typedef void (CCObject::*SEL_ATTENUATION_SELECTOR)(CCObject*);
#define attenuation_selector(_SELECTOR) (SEL_ATTENUATION_SELECTOR)(&_SELECTOR)
//������Ϣ�ص�
typedef void (CCObject::*SEL_OVER_SELECTOR)(CCObject*);
#define over_selector(_SELECTOR) (SEL_OVER_SELECTOR)(&_SELECTOR)
class BlackHoleEffect:public CCNode
{
public:
	BlackHoleEffect();
	~BlackHoleEffect();

	//************************************
	// Description:�����ڶ�
	// Parameter: float g			����
	// Parameter: float range		Ӱ�췶Χ
	// Parameter: float angleSpeed	���ٶ�
	// Parameter: int time			����ʱ��
	// Parameter: int fps			֡Ƶ
	// Returns:   BlackHoleEffect*	�ڶ�	
	//************************************
	static BlackHoleEffect* create(float g = 10.0f, float range = 400.0f, 
								   float angleSpeed = 5.0f, int time = 2000, 
								   int fps = 60);

	//************************************
	// Description:�����ڶ�
	// Parameter: float g			����
	// Parameter: float range		Ӱ�췶Χ
	// Parameter: float angleSpeed	��תʱ�Ľ��ٶ�
	// Parameter: int time			����ʱ��
	// Parameter: int fps			֡Ƶ
	// Returns:   BlackHoleEffect*	�ڶ�	
	//************************************
	bool init(float g = 10.0f, float range = 400.0f,
			  float angleSpeed = 5.0f, int time = 2000,
			  int fps = 60);

	//************************************
	// Description:��Ӻڶ�
	// Parameter: float holePosX	�ڶ�λ��x
	// Parameter: float holePosY	�ڶ�λ��y
	// Returns:   void
	//************************************
	void addHole(float holePosX, float holePosY);

	//************************************
	// Description:��������б�
	// Parameter: CCArray * ary
	// Returns:   void
	//************************************
	void addSubstanceList(CCArray* ary);

	//************************************
	// Description:�������
	// Parameter: float x1	��1��x����
	// Parameter: float y1	��1��y����
	// Parameter: float x2	��2��x����
	// Parameter: float y2	��2��y����
	// Returns:   float		����
	//************************************
	float mathDistance(float x1, float y1, float x2, float y2);

	//����
	void update();

	//��ӽ���ڶ�����
	void setInHoleSelector(CCObject* target, SEL_IN_HOLE_SELECTOR inHoleComplete);

	//��Ӻڶ�˥����Ϣ����
	void setAttenuationSelector(CCObject* target, SEL_ATTENUATION_SELECTOR attenuationComplete);

	//��ӽ�����Ϣ����
	void setOverSelector(CCObject* target, SEL_OVER_SELECTOR overComplete);
private:
	//����
	float g;
	//Ӱ�췶Χ
	float range;
	//��תʱ�Ľ��ٶ�
	float angleSpeed;
	//����ʱ��
	int time;
	//֡Ƶ
	int fps;
	//�ڶ�λ��
	float holePosX;
	float holePosY;
	//�Ƿ����ڶ�
	bool isStart;
	//�Ƿ����
	bool isOver;
	//��̾���
	int minDis;
	//����ʱ�䣨֡��
	int timeFrame;
	//�����󻺶�ʱ�䣨���룩
	int overTime;
	//�����󻺶�ʱ�䣨֡��
	int overTimeFrame;
	//�����б��ű�����������
	CCArray* subList;
	//Ħ����
	float f;
	//����ڶ��ص�����
	SEL_IN_HOLE_SELECTOR inHoleCompleteFun;
	//�ڶ�˥���ص�����
	SEL_ATTENUATION_SELECTOR attenuationCompleteFun;
	//������Ϣ�ص�����
	SEL_OVER_SELECTOR overCompleteFun;
	//�ص�������Ŀ��
	CCObject* target;
};
#endif
