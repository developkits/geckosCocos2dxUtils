#pragma once
#ifndef _ENTER_FRAME_INIT_
#define _ENTER_FRAME_INIT_
#include "cocos2d.h"
USING_NS_CC;
class EnterFrame
{
public:
	EnterFrame(void);
	~EnterFrame(void);
	//��ʼ��
	//container		�ⲿ����
	//fps			֡Ƶ
	static void init(CCNode* container, float fps=60.0);
	//��ʼ����
	static void start();
	//ֹͣ����
	static void stop();
	//���뷽��
	static void push(SEL_CallFunc callfunc);
	//ɾ��ָ������
	static void pop(SEL_CallFunc callfunc);
	//����б�
	static void clear();
	
	//FUNCADDR��ָ������һ��������ָ�룬�ú����ķ���ֵΪvoid���ͣ�������һ��int�͵�
	//typedef void (*FUNCADDR)(int) 
};

class Node:public CCNode
{
public:
	//ѭ��
	void loop(float dt);
};
#endif