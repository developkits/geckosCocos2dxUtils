#pragma once
#ifndef _ALERT_
#define _ALERT_
#include "cocos2d.h"
#include "TextButton.h"
USING_NS_CC;
//���尴ť�Ļص���������
typedef void (CCObject::*SEL_ALERT_SELECTOR)(CCNode*);
#define alert_selector(_SELECTOR) (SEL_ALERT_SELECTOR)(&_SELECTOR)
class Alert:public CCNodeRGBA
{
public:
	Alert(bool showCancel = false, bool touchHide = true, SEL_ALERT_SELECTOR callBackFunc = NULL);
	~Alert(void);
	//��ʼ������
	static void initTexture(CCTexture2D* texture);
	static void initTexture(const char* name);
	static Alert* create(bool showCancel = false, bool touchHide = true, SEL_ALERT_SELECTOR callBackFunc = NULL);
	static void initParent(CCNode* parent);
	/**
	 * ��ʾ������
	 * @param	content				��������		
	 * @param	showCancel			�Ƿ���ʾ�رհ�ť		
	 * @param	touchHide			�Ƿ���ȷ����رս���	
	 * @param	callBackFunc		�ص�����	
	 */
	static void show(char* content, bool showCancel = false, bool touchHide = true, SEL_ALERT_SELECTOR callBackFunc = NULL);
private:
	TextButton* confirmBtn;
	TextButton* cancelBtn;
	CCSprite* bg;
	bool showCancel;
	bool touchHide;
	//�ⲿ�ص�������
	SEL_ALERT_SELECTOR callBackFunc;
	void initUI();
};
#endif
