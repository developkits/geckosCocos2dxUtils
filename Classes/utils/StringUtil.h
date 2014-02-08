#pragma once
#ifndef _STRING_UTIL_INIT_
#define _STRING_UTIL_INIT_
#include <iostream>
using namespace std;
class StringUtil
{
public:
	StringUtil(void);
	~StringUtil(void);

	/**
     * ���ظ��ַ��Ƿ�Ϊ�հ��ַ�
     * @param    str
     * @return  ���ظ��ַ��Ƿ�Ϊ�հ��ַ�
     */
	static bool isWhiteSpace(string* str);

	 /**
     * ȥ���ַ�����˵Ŀհ��ַ�
     * @param    target		Ŀ���ַ���
     */
	static void lTrim(string* target);

	/**
     * ȥ���ַ����Ҷ˵Ŀհ��ַ�
     * @param    target		Ŀ���ַ���
     */
	static void rTrim(string* target);

	/**
     * ����һ��ȥ��2�οհ��ַ����ַ���
     * @param    target		Ŀ���ַ���
     */
	static void trim(string* target);
};
#endif
