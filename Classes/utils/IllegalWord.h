#pragma once
#ifndef _ILLEGAL_WORD_
#define _ILLEGAL_WORD_
#include "cocos2d.h"
#include "StringUtil.h"
USING_NS_CC;
using namespace std;
using namespace tinyxml2;
class IllegalWord
{
public:
	IllegalWord();
	~IllegalWord();
	/**
	* ��ʼ���ؼ�������
	* @param name	��������
	*/
	static void init(string name = "cfg/illegalWords.xml");

	/**
	* ��������
	* @param target	��Ҫ���˵�����
	* @return		���˺������
	*/
	static void filter(string &target);

	/**
	* �Ƿ�ؼ���
	* @param target	��Ҫ���˵�����
	* @return		�Ƿ��йؼ���
	*/
	static bool hasKeyWord(string &target);
};
#endif
