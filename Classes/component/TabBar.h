#pragma once
#ifndef _TEXTURE_TAB_BAR_
#define _TEXTURE_TAB_BAR_
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
using namespace extension;
class TabBar:public CCNodeRGBA
{
public:
	/**
	 * @param	textureList		�����б�		
	 * @param	gap				��ť���	
	 */
	TabBar(CCArray* textureList, int gap=0);
	~TabBar(void);

	static TabBar* create(CCArray* textureList, int gap=0);
private:
	//���
	int gap;
	CCArray* textureList;
	void initUI();
	//����ѡ��ť
	void setSelectedIndex(int index);
	void btnClickHandler(CCObject* pSender, CCControlEvent event);
};
#endif
