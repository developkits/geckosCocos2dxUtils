#pragma once
#ifndef _TIME_FORMAT_
#define _TIME_FORMAT_
#include <iostream>
using namespace std;
class TimeFormat
{
public:
	TimeFormat(void);
	~TimeFormat(void);
	/**
     * ����ת��Ϊʱ����ʽ��
	 * @param	targetStr ��Ҫ�޸ĵ��ַ���    
	 * @param	time ����    
     * @param	partition �ָ���
     * @param	showHour  �Ƿ���ʾСʱ
     * 
     * ����: time = 4351; secondToTime(time)�����ַ���01:12:31;
     */
	static void secondToTime(string* targetStr, int second = 0, string partition = ":", bool showHour = true);
};
#endif
