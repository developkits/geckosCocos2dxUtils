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

	/**
     * �������ַ�ǰ���� "0"
     * 
     * <pre> 
     * 
     * CClog( StringFormat::zfill('1') );
     * // 01
     * 
     * CClog( StringFormat::zfill('16', 5) );
     * // 00016
     * 
     * CClog( StringFormat::zfill('-3', 3) );
     * // -03
     * 
     * </pre>
     * 
     * @param str Ҫ���д�����ַ���
     * @param width ������ַ����ĳ��ȣ�
     *              ���str.length >= width���������κδ���ֱ�ӷ���ԭʼ��str��
     */
	static void zfill(string* str, unsigned int width = 2);
};
#endif
