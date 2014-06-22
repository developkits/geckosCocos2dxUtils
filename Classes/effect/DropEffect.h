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
	// Parameter: const char* pszFileName	��Դ��ַ
	// Parameter: float floorPosY			�װ�λ��
	// Parameter: float fps					֡Ƶ
	// Returns:   DropEffect*		
	//************************************
	static DropEffect* create(const char* pszFileName, float floorPosY = 0, float fps = .01f);

	//��ʼ��
	bool init(const char* pszFileName, float floorPosY, float fps);
	//************************************
	// Description:��ʾ����Ч��
	// Parameter: int count				������Ʒ������
	// Parameter: float x				x����
	// Parameter: float y				y����
	// Parameter: float gravity			����
	// Parameter: float elasticity		����
	// Parameter: float friction		Ħ��ϵ����0-1��ϵ��Խ��Ħ����ԽС
	// Parameter: float minDropHeight	��С����߶�
	// Parameter: float maxDropHeight	�������߶�
	// Parameter: float minVx			��С�����ٶ�
	// Parameter: float maxVx			�������ٶ�
	// Parameter: float minVy			��С�����ٶ�
	// Parameter: float maxVy			�������ٶ�
	// Returns:   void
	//************************************
	void drop(int count = 5,
			float x = 0,
			float y = 0,
			float gravity = .9,
			float elasticity = .4,
			float friction = 1,
			float minDropHeight = 0,
			float maxDropHeight = 0,
			float minVx = -5, float maxVx = 5,
			float minVy = 4, float maxVy = 10);
	//ѭ��
	void loop(float dt);
private:
	//������������Ľڵ�
	CCSpriteBatchNode* batchNode;
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
	// Parameter: CCTexture2D* texture			������Ʒ������
	// Parameter: float gravity					����
	// Parameter: float elasticity				����
	// Parameter: float friction				Ħ����
	// Parameter: float floorPosY				�װ�λ��
	// Parameter: float minDropHeight			��С����߶�
	// Parameter: float maxDropHeight			�������߶�
	// Returns:   DropItem*
	//************************************
	static DropItem* create(CCTexture2D* texture,
							float gravity, 
							float elasticity, 
							float friction,
							float minDropHeight, 
							float maxDropHeight);

	//************************************
	// Description:��ʼ��
	// Parameter: int gravity				����
	// Parameter: int elasticity			����
	// Parameter: float friction			Ħ����
	// Parameter: float floorPosY			�װ�λ��
	// Parameter: float minDropHeight		��С����߶�
	// Parameter: float maxDropHeight		�������߶�
	// Returns:   bool	
	//************************************
	bool init(float gravity, float elasticity, float friction, float minDropHeight, float maxDropHeight);
	//���·���
	void update();
	//���õװ�λ��
	void setFloorPos(float pos);
	//�����ٶ�
	float vx;
	//�����ٶ�
	float vy;
private:
	//����
	float gravity;
	//����
	float elasticity;
	//Ħ����
	float friction;
	//����߶�
	float floorPosY;
	//��С����߶�
	float minDropHeight;
	//�������߶�
	float maxDropHeight;

	CCLabelTTF* text;
};
#endif
