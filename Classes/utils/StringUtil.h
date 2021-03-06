#pragma once
#ifndef _STRING_UTIL_INIT_
#define _STRING_UTIL_INIT_
#include <iostream>
#include <algorithm>
#include <vector>
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
	static bool isWhiteSpace(string str);

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
     * @param str Ҫ���д������ַ���
     * @param width �������ַ����ĳ��ȣ�
     *              ���str.length >= width���������κδ���ֱ�ӷ���ԭʼ��str��
     */
	static void zfill(string* str, unsigned int width = 2);

	/**
	 * ��ת�ַ���
	 * @param	str �ַ���
	 */
	static void reverse(string* str);

	/**
	 * �ض�ĳ���ַ���
	 * @param	str		Ŀ���ַ���
	 * @param	start	��Ҫ�ضϵ���ʼ����
	 * @param	len		�ضϳ���
	 * @param	order	˳��true���ַ���ͷ����ʼ���㣬false���ַ���β�Ϳ�ʼ���㡣
	 */
	static void cutOff(string* str, unsigned int start, unsigned int len, bool order=true);

	 /**
     * �ָ��ַ���
	 * @param   result		�ָ���vector
	 * @param   str			���ָ���ַ���
	 * @param   delim		�ָ��
     */
	static void split(vector<string> &result, string str, string delim);

	/**
	* �������ʻ�
	* @param   score		����
	* @return  ���ʻ���ķ���
	*/
	static string toScoreString(long long score);

	/**
	* �����ַ��Ƿ��Ƿ���
	* @param   str		�ַ���
	* @return  �Ƿ��Ƿ����ַ�
	*/
	static bool isSymbolWord(const char* str);

	/**
	* �����ַ��Ƿ�����ĸ
	* @param   str		�ַ���
	* @return  �Ƿ�����ĸ�ַ�
	*/
	static bool isAlphabetWord(const char* str);

	/**
	* �����ַ��Ƿ�������
	* @param   str		�ַ���
	* @return  �Ƿ��������ַ�
	*/
	static bool isNumberWord(const char* str);

	/**
	* ����ַ��Ƿ��������
	* @param   str		�ַ���
	* @return  �Ƿ��������
	*/
	static bool hasNumberWord(const char* str);

	/**
	* ����ַ��Ƿ������ĸ
	* @param   str		�ַ���
	* @return  �Ƿ������ĸ
	*/
	static bool hasAlphabetWord(const char* str);

	/**
	* ����ַ��Ƿ��������
	* @param   str		�ַ���
	* @return  �Ƿ��������
	*/
	static bool hasSymbolWord(const char* str);

	/**
	* �����ַ�����������ƥ��λ��
	* @param   str			Ҫ���������ַ���Դ
	* @param   match		Ҫ���������ַ���
	* @return  ָ�����ַ����ĵ�һ��ƥ������������� -1�� 
	*/
	static int indexOf(string str, string match);

	/**
	* �滻�ַ���
	* @param   str			Դ�ַ���
	* @param   match		��Ҫ�滻���ݵ����ַ���
	* @param   repl			�滻������
	*/
	static void replace(string &str, string match, string repl);
};

#endif
