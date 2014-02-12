#pragma once
#ifndef _TEXTBUTTON_
#define _TEXTBUTTON_
#include "cocos2d.h"
#include "cocos-ext.h"
#include <algorithm>
USING_NS_CC;
/************************************************************************/
/* �ı���ť��������Ϸ�ڳ��ð�ťʹ��                                           */
/************************************************************************/
using namespace std;
using namespace extension;
class TextButton:public CCNodeRGBA
{
public:
	/**
	 * @param	type		��ɫ����		
	 * @param	str			��������	
	 * @param	width		��ť���	
	 */
	TextButton(int type, string str, float width = 0);
	~TextButton(void);
	//��ť
	CCControlButton* coreTarget;
	//���ð�ť��ǩ
	virtual void setTag(int nTag);
private:
	//9����
	CCScale9Sprite* upSpt;
	//�ı�
	CCLabelTTF* label;

	void btnClickHandler(CCObject* pSender, CCControlEvent event);
};
#endif
