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
	 * @param	targetStr ��Ҫд����ַ���    
	 * @param	time ����    
     * @param	partition �ָ���
     * @param	showHour  �Ƿ���ʾСʱ
     * 
     * ����: time = 4351; secondToTime(time)�����ַ���01:12:31;
     */
	static void secondToTime(string* targetStr, int second = 0, string partition = ":", bool showHour = true);

	/**
     * ʱ����ʽת��Ϊ������
	 * @param   targetStr	��Ҫд����ַ���
	 * @param   time		��ָ���ָ����ָ��ʱ���ַ���
     * @param   partition	�ָ���
     * 
     * �÷�1 trace(MillisecondTransform.timeToMillisecond("00:60:00"))
     * ���   3600000
     * 
     * �÷�2 trace(MillisecondTransform.timeToMillisecond("00.60.00","."))
     * ���   3600000
     */
	static void timeToSecond(string* targetStr, string time, string partition = ":");
};
#endif
