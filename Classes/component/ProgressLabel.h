#pragma once
#ifndef _TEXT_EFFECT_
#define _TEXT_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
class ProgressLabel :public CCLabelTTF
{
public:
	ProgressLabel();
	~ProgressLabel();
	
	//************************************
	// Description:����
	// Parameter: const char * fontName	����
	// Parameter: float fontSize		��С
	// Returns:   ProgressLabel*
	//************************************
	static ProgressLabel* create(const char *fontName, float fontSize);
	
	//************************************
	// Description: ��ʾ����������ʾЧ��
	// Parameter: const char * str		��������
	// Parameter: int delay				��ʾ��������룩
	// Returns:   void
	//************************************
	void show(const char* str, float delay = 10);
	
	//************************************
	// Description: ��ͣ��ָ�
	// Returns:   void
	//************************************
	void togglePause();
private:
	//���
	int m_delay;
	//�Ƿ���ͣ
	bool isPause;
	//��Ҫ��ʾ���ַ���
	const char* m_str;
	//��ʱ���ص�
	void timerHandler(float dt);
	//�ַ���λ������
	int wordCount;
};
#endif
