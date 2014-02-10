#pragma once
#ifndef _FLOAT_TIPS_
#define _FLOAT_TIPS_
#include "cocos2d.h"
USING_NS_CC;
class FloatTips
{
public:
	FloatTips(void);
	~FloatTips(void);

	/**
	 * ��ʼ�������ø�����
	 */
	static void init(CCNode* parent);

	/**
	 * ��ʾƯ������
	 * @param	content	����
	 */
	static void show(const char* content);

	/**
	 * ��ȡһ��Ư����ʾ
	 */
	static FloatTip* getAFloatTip();

};

class FloatTip:public CCSprite
{
public:
	FloatTip();
	~FloatTip();
	void setText(const char* str);
private:
	//����ͼƬ
	CCSprite* bg;
	//�ı���
	CCLabelTTF* contentTf;
};
#endif
