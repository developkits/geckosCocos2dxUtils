#pragma once
#ifndef _FLOAT_TIPS_
#define _FLOAT_TIPS_
#include "cocos2d.h"
USING_NS_CC;
class FloatTip:public CCNodeRGBA
{
public:
	FloatTip();
	~FloatTip();
	static FloatTip* create();
	//������������
	void setText(const char* str);
	//�����ļ�����·������ͼƬ
	void createWithImage(const char *pszFileName);
	//����������ͼƬ
	void createWithTexture(CCTexture2D *pTexture);
private:
	//����ͼƬ
	CCSprite* bg;
	//�ı���
	CCLabelTTF* contentTf;
	//�����ı���
	void createContentText();
};

class FloatTips
{
public:
	FloatTips(void);
	~FloatTips(void);

	/**
	 * ��ʼ�������ø�����
	 */
	static void init(CCNode* parent, CCPoint p=ccp(320, 760), CCTexture2D *pTexture=NULL);

	/**
	 * ��ʾƯ������
	 * @param	content	����
	 */
	static void show(const char* content);

	/**
	 * ��ȡһ��Ư����ʾ
	 */
	static FloatTip* getAFloatTip();

	/**
	 * ��ճ�
	 */
	static void clear();

	//����������ص�
	void actionCompleteCallBackFunc(CCNode* ft);
};
#endif
