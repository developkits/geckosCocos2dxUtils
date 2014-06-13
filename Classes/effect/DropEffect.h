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

	//************************************
	// Description:����
	// Parameter: float floorPosY	�װ�λ��
	// Parameter: float fps			֡Ƶ
	// Returns:   DropEffect*		
	//************************************
	static DropEffect* create(float floorPosY = 0, float fps = .01f);

	//��ʼ��
	bool init(float floorPosY, float fps);
	//************************************
	// Description:��ʾ����Ч��
	// Parameter: const char*		��Դ��ַ
	// Parameter: int count			������Ʒ������
	// Parameter: float x			x����
	// Parameter: float y			y����
	// Parameter: float gravity		����
	// Parameter: float elasticity	����
	// Parameter: float minVx		��С�����ٶ�
	// Parameter: float maxVx		�������ٶ�
	// Parameter: float minVy		��С�����ٶ�
	// Parameter: float maxVy		�������ٶ�
	// Returns:   void
	//************************************
	void drop(const char* pszFileName, 
				int count = 5, 
				float x = 0,
				float y = 0,
				float gravity = .9, 
				float elasticity = .4, 
				float minVx = -5, float maxVx = 5, 
				float minVy = 4, float maxVy = 10);
	//ѭ��
	void loop(float dt);
private:
	//������Ʒ�б�
	CCArray* itemList;
	//֡Ƶ
	float fps;
	//��������
	float floorPosY;
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
	static DropItem* create(const char* pszFileName, float gravity, float elasticity, float floorPosY);

	//************************************
	// Description:��ʼ��
	// Parameter: int gravity		����
	// Parameter: int elasticity	����
	// Returns:   bool	
	//************************************
	bool init(float gravity , float elasticity, float floorPosY);
	//�����ٶ�
	float vx;
	//�����ٶ�
	float vy;
	//����
	float gravity;
	//����
	float elasticity;
	//����߶�
	float floorPosY;
	//���·���
	void update();
};
#endif
