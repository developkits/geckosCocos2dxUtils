#pragma once
#ifndef _DROP_EFFECT_
#define _DROP_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
class DropEffect :public CCNode
{
public:
	DropEffect();
	~DropEffect();
	CREATE_FUNC(DropEffect);
	//************************************
	// Description:��ʾ����Ч��
	// Parameter: const char*		��Դ��ַ
	// Parameter: int count			������Ʒ������
	// Parameter: float gravity		����
	// Parameter: float elasticity	����
	// Parameter: float minVx		��С�����ٶ�
	// Parameter: float maxVx		�������ٶ�
	// Parameter: float minVy		��С�����ٶ�
	// Parameter: float maxVy		�������ٶ�
	// Returns:   void
	//************************************
	void drop(const char* pszFileName, 
				int count, float gravity = 1, 
				float elasticity = .9, float minVx = -5, 
				float maxVx = 5, float minVy = 10, float maxVy = 20);
	//ѭ��
	void loop(float dt);
private:
	//������Ʒ�б�
	CCArray* itemList;
};

//������Ʒ
class DropItem :public CCSprite
{
public:
	DropItem();
	~DropItem();

	
	//************************************
	// Description:����������Ʒ
	// Parameter: const char * pszFileName	������Ʒ����Դ
	// Parameter: float gravity				����
	// Parameter: float elasticity			����
	// Returns:   DropItem*
	//************************************
	static DropItem* create(const char* pszFileName, float gravity = 1, float elasticity = .9);

	//************************************
	// Description:��ʼ��
	// Parameter: int gravity
	// Parameter: int elasticity
	// Returns:   bool
	//************************************
	bool init(float gravity = 1, float elasticity = .9);
	//�����ٶ�
	float vx;
	//�����ٶ�
	float vy;
	//����
	float gravity;
	//����
	float elasticity;
	//���·���
	void update();
};
#endif
