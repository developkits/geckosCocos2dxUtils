#pragma once
#ifndef _LANGUAGE_INIT_
#define _LANGUAGE_INIT_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class Language
{
public:
	Language(void);
	~Language(void);
	/**
	 * ����xml����`
	 * @param name	��������
	 */
	static void init(string name);
	/**
	 * ��ȡ����������
	 * @param name			�ڵ���
	 * @param vector		��Ҫ####�滻������ŵ�vector
	 */
	static const char* get(string name, vector<string> *v=NULL);
};
#endif

