#pragma once
#ifndef _TEXTURE_TAB_BAR_
#define _TEXTURE_TAB_BAR_
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
using namespace extension;
/************************************************************************/
/* �����ǩ																*/
/************************************************************************/
//����tabBar�Ļص���������
typedef void (CCObject::*SEL_TAR_BAR_SELECTOR)(int);
#define tar_bar_selector(_SELECTOR) (SEL_TAR_BAR_SELECTOR)(&_SELECTOR)
class TabBar:public CCNodeRGBA
{
public:
	/**
	 * @param	textureList		�����б�		
	 * @param	gap				��ť���	
	 */
	TabBar(CCArray* textureList, int gap=0, SEL_TAR_BAR_SELECTOR callBackFunc=NULL);
	~TabBar(void);

	static TabBar* create(CCArray* textureList, int gap=0, SEL_TAR_BAR_SELECTOR callBackFunc=NULL);
private:
	//���
	int gap;
	CCArray* textureList;
	//�ص�����
	SEL_TAR_BAR_SELECTOR callBackFunc;
	void initUI();
	//����ѡ��ť
	void setSelectedIndex(int index);
	void btnClickHandler(CCObject* pSender, CCControlEvent event);
};
#endif
