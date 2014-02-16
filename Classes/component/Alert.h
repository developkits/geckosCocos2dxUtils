#pragma once
#ifndef _ALERT_
#define _ALERT_
#include "cocos2d.h"
#include "TextButton.h"
USING_NS_CC;
//���尴ť�Ļص���������
typedef void (CCObject::*SEL_ALERT_SELECTOR)();
#define alert_selector(_SELECTOR) (SEL_ALERT_SELECTOR)(&_SELECTOR)
class Alert:public CCNodeRGBA
{
public:
	Alert(char* content, bool showCancel = false, bool touchHide = true, CCNode* eventTarget = NULL, SEL_ALERT_SELECTOR confirmHandler = NULL, SEL_ALERT_SELECTOR cancelHandler = NULL);
	~Alert(void);
	//��ʼ������
	static void initTexture(CCTexture2D* texture);
	static void initTexture(const char* name);
	static Alert* create( char* content, bool showCancel = false, bool touchHide = true, CCNode* eventTarget = NULL, SEL_ALERT_SELECTOR confirmHandler = NULL, SEL_ALERT_SELECTOR cancelHandler = NULL);
	static void initParent(CCNode* parent);
	/**
	 * ��ʾ������
	 * @param	content				��������		
	 * @param	showCancel			�Ƿ���ʾ�رհ�ť		
	 * @param	touchHide			�Ƿ���ȷ����رս���	
	 * @param	eventTarget			�¼�����Ŀ��ָ��	
	 * @param	confirmHandler		ȷ���ص�����	
	 * @param	cancelHandler		ȡ���ص�����	
	 */
	static void show(char* content, bool showCancel = false, bool touchHide = true, CCNode* eventTarget = NULL, SEL_ALERT_SELECTOR confirmHandler = NULL, SEL_ALERT_SELECTOR cancelHandler = NULL);
	//�رպ�ȷ����ť
	TextButton* confirmBtn;
	TextButton* cancelBtn;
	//�ı�
	CCLabelTTF* pLabel;
	//�������
	CCScrollView* scrollView;
private:
	CCSprite* bg;
	bool showCancel;
	bool touchHide;
	//�������
	void hide();
	//�¼�Ŀ��
	CCNode* eventTarget;
	//�ⲿ�ص�������
	SEL_ALERT_SELECTOR confirmHandler;
	SEL_ALERT_SELECTOR cancelHandler;
	//�ڲ��������
	void confirmBtnClickHandler(CCNode* target);
	void cancelBtnClickHandler(CCNode* target);
	void initUI();
};
#endif
