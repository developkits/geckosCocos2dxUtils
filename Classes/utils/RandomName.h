#pragma once
#ifndef _RANDOM_NAME_
#define _RANDOM_NAME_
#include "cocos2d.h"
#include "Random.h"
USING_NS_CC;
using namespace tinyxml2;
using namespace std;
class RandomName
{
public:
	RandomName();
	~RandomName();
	/**
	* ��ʼ��������ֱ�
	* @param name	���ñ�����
	*/
	static void init(const char* name);

	/**
	* �����������
	* @param str	��Ҫ��������������ַ���
	*/
	static void getRandomName(string &str);
};
#endif
