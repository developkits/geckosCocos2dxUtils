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
//���尴ť�Ļص���������
typedef void (CCObject::*SEL_TEXT_BUTTON_SELECTOR)(CCNode*);
#define text_button_selector(_SELECTOR) (SEL_TEXT_BUTTON_SELECTOR)(&_SELECTOR)
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
	static TextButton* create(int type, string str, float width = 0);
	//�����Ƿ���Ե��
	void setMouseEnabeld(bool flag);
	//�����Ƿ�ťЧ��
	void setEnabled(bool flag);
	//�����ص�
	void addEventListener(SEL_TEXT_BUTTON_SELECTOR callBackFunc);
private:
	//��ť
	CCControlButton* coreTarget;
	//9����
	CCScale9Sprite* upSpt;
	//�ı�
	CCLabelTTF* label;
	//�ڲ��������
	void btnClickHandler(CCObject* pSender, CCControlEvent event);
	//�ⲿ�ص�������
	SEL_TEXT_BUTTON_SELECTOR btnCallBackFunc;
};
#endif
