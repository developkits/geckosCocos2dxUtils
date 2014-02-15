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

#define TYPE_RECT_BLUE  1
#define TYPE_RECT_GRAY  2
#define TYPE_RECT_GREEN  3
#define TYPE_RECT_RED  4
#define TYPE_2CORNER_GREEN  5
#define TYPE_2CORNER_RED  6
#define TYPE_1CORNER_GREEN  7
#define TYPE_1CORNER_RED  8
#define TYPE_2CORNER_GRAY  9
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
	//��ȡ�߿�
	CCSize getContentSize();
	static TextButton* create(int type, string str, float width = 0);
	//�����Ƿ���Ե��
	void setMouseEnabeld(bool flag);
	//�����Ƿ�ťЧ��
	void setEnabled(bool flag);
	//�����ص�
	void addEventListener(CCObject* target, SEL_TEXT_BUTTON_SELECTOR callBackFunc);	
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
	SEL_TEXT_BUTTON_SELECTOR callBackFunc;
	//���ûص���Ŀ��ָ��
	CCObject* target;
};
#endif
